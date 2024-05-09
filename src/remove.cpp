#include "../common/common.hpp"
#include "../common/common.h"

#include <filesystem>
#include <string>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

void RemoveOldest()
{
    int Count = {0};

    std::ifstream Manifest(".saves/MANIFEST");

    if (!Manifest.is_open())
    {
        std::cerr << "unable to read MANIFEST at '.saves/MANIFEST'" << '\n';
        std::cout << "maybe deletion time is higher than std/end time?" << '\n';
    }

    Manifest >> Count;

    Manifest.close();

    if (Count > 2)
        int Result = Count - 1;

    else
        std::cout << "to early to delete at the moment" << '\n';

    std::string FilePath = CDToBackerFolder();
    chdir(FilePath.c_str());

    std::ifstream Saves("saves.txt");

    if (!Saves.is_open())
    {
        std::cerr << "run with --save first" << '\n';
        exit(1);
    }

    std::string FolderName;
    Saves >> FolderName;

    Saves.close();

    std::string StrCount = std::to_string(Count);
    std::string FormattedFolderName = FolderName + "-" + StrCount;

    chdir(".saves");

    std::filesystem::remove_all(FormattedFolderName);

    chdir("..");
}

