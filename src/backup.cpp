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

void MakeDirectSave()
{
    std::string Cwd = Fs::current_path();
    char* Path = CDToBackerFolder();

    chdir(Path);

    std::ifstream Savefile("saves.txt");

    if (!Savefile.is_open())
    {
        std::cout << "please configure first" << '\n';
        std::cout << "you may also run with prompt" << '\n';

        exit(1);
    }

    std::string Folder;
    Savefile >> Folder;
    Savefile.close();

    chdir(Cwd.c_str());

    std::cout << "searching for folder in current path..." << '\n';

    if (!Fs::exists(Saves))
        Fs::create_directories(Saves);

    chdir(Saves.c_str());

    if (!Fs::exists(Folder))
        Fs::create_directories(Folder);

    // step back
    chdir("..");

    char BackupFolder[BUF];

    snprintf(
        BackupFolder, BUF,
        "%s/%s", Saves.c_str(), Folder.c_str()
    );

    Fs::copy(Folder, BackupFolder, Fs::copy_options::recursive);

    RenameFolder(Saves, Folder);
}

void MakeSave()
{
    std::string Cwd = Fs::current_path();
    char* Path = CDToBackerFolder();

    chdir(Path);

    std::ofstream Name("saves.txt");

    if (!Name.is_open())
    {
        std::cerr << "error writing file" << '\n';
        exit(1);
    }

    std::string Ui;

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

