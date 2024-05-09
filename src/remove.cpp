#include "../common/common.hpp"
#include "../common/common.h"

#include <filesystem>
#include <string>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

#define MAX_LEN 8192

void RemoveOldest()
{
    int Count = 0;

    char Cwd[MAX_LEN];
    getcwd(Cwd, sizeof(Cwd));

    char* Path = CDToBackerFolder();
    chdir(Path);

    std::ifstream Saves("saves.txt");

    if (!Saves.is_open())
    {
        std::cerr << "error reading" << '\n';
        std::cout << "run --save first" << '\n';
        exit(1);
    }

    std::string FolderName;
    Saves >> FolderName;

    Saves.close();

    chdir(Cwd);
    chdir(".saves");

    std::ifstream Manifest("MANIFEST");

    if (!Manifest.is_open())
    {
        std::cerr << "error reading" << '\n';
        std::cout << "run --save first" << '\n';
        exit(1);
    }

    Manifest >> Count;
    Manifest.close();

    if (Count > 2)
    {
        int Num;
        Num = Count - 1;

        std::cout << Num << '\n';

        std::string NewFolderName = FolderName + "-" + std::to_string(Num);
        std::filesystem::remove_all(NewFolderName);
    }

    chdir("..");
}


