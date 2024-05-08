#include "../common/common.hpp"

#include <unistd.h>
#include <fstream>
#include <string>

void RenameFolder(std::string WorkingPath, std::string FolderName)
{
    Counter(WorkingPath);

    chdir(WorkingPath.c_str());
    // no error handling here
    // counter() should have done it
    // this MUST work 👿
    std::ifstream Manifest("MANIFEST");

    int Index;

    Manifest >> Index;
    Manifest.close();

    std::string Str_Index = std::to_string(Index);
    std::string NewName = FolderName + "-" + Str_Index;    

    rename(FolderName.c_str(), NewName.c_str());
}

