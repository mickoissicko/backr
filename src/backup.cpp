#include "../common/common.hpp"
#include "../common/common.h"

#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <cstdio>

#define MAX_LEN 8192
#define BUF 4096

namespace Fs = std::filesystem;

const std::string Saves = ".saves";

void DirectSaver()
{
    char Cwd[MAX_LEN];
    getcwd(Cwd, sizeof(Cwd));

    char* Path = CDToBackerFolder();

    chdir(Path);

    std::ifstream Name("saves.txt");

    if (!Name.is_open())
    {
        std::cerr << "error reading file" << '\n';
        std::cout << "make sure to enter name first" << '\n';
        std::cout << "run with '--save'" << '\n';
        exit(1);
    }

    std::string Ui;

    Name.seekg(0);

    Name >> Ui;
    Name.close();

    chdir(Cwd);

    if (!Fs::exists(Saves))
        Fs::create_directories(Saves);

    chdir(Saves.c_str());

    if (!Fs::exists(Ui))
        Fs::create_directories(Ui);

    // step back
    chdir("..");

    char BackupFolder[BUF];

    snprintf(BackupFolder, BUF, "%s/%s", Saves.c_str(), Ui.c_str());

    Fs::copy(Ui, BackupFolder, Fs::copy_options::recursive);

    RenameFolder(Saves, Ui);   
}

void MakeSave()
{
    char Ui_2;

    while (
        Ui_2 != 'y' &&
        Ui_2 != 'Y' &&
        Ui_2 != 'N' &&
        Ui_2 != 'n'
    ){
        std::cout << "Use previous folder? [y/n]: ";
        std::cin >> Ui_2;
    }

    if (Ui_2 == 'y' || Ui_2 == 'Y')
        DirectSaver();

    if (Ui_2 == 'n' || Ui_2 == 'N')
    {
        std::string Cwd = Fs::current_path();
        char* Path = CDToBackerFolder();

        chdir(Path);

        std::string Ui;

        std::ofstream Name("saves.txt");

        if (!Name.is_open())
        {
            std::cerr << "error writing file" << '\n';
            exit(1);
        }

        std::cout << "Folder to backup: ",
        std::cin >> Ui;

        Name << Ui << '\n';
        Name.close();

        chdir(Cwd.c_str());

        if (!Fs::exists(Saves))
            Fs::create_directories(Saves);

        chdir(Saves.c_str());

        if (!Fs::exists(Ui))
            Fs::create_directories(Ui);

        // step back
        chdir("..");

        char BackupFolder[BUF];

        snprintf(BackupFolder, BUF, "%s/%s", Saves.c_str(), Ui.c_str());

        Fs::copy(Ui, BackupFolder, Fs::copy_options::recursive);

        RenameFolder(Saves, Ui);
    }
}

