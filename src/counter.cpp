#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

void Counter(std::string WorkingPath)
{
    chdir(WorkingPath.c_str());

    std::ifstream Manifest("MANIFEST");

    int Index = 1;

    if (Manifest.is_open())
    {
        Manifest >> Index;
        Manifest.close();

        std::ofstream Manifest("MANIFEST");

        if (!Manifest.is_open())
        {
            std::cerr << "error writing file" << '\n';
            exit(1);
        }

        Manifest << Index + 1 << '\n';
        Manifest.close();
    }

    else
    {
        std::ofstream Manifest("MANIFEST");

        if (!Manifest.is_open())
        {
            std::cerr << "error writing file" << '\n';
            exit(1);
        }

        Manifest << "1" << '\n';
        Manifest.close();
    }

    chdir("..");
}

