#include <iostream>
#include <fstream>

int GetLowestVal()
{
    int Lowest = 3;
    int Index = 3;

    std::ifstream Manifest("c.MANIFEST");

    if (Manifest.is_open())
    {
        Manifest >> Index;
        Manifest.close();

        std::ofstream Manifest("c.MANIFEST");

        if (!Manifest.is_open())
        {
            std::cerr << "error writing file" << '\n';
            exit(1);
        }

        Manifest << Index + 1 << '\n';
        Lowest = Index;
        Manifest.close();
    }

    else
    {
        std::ofstream Manifest("c.MANIFEST");

        if (!Manifest.is_open())
        {
            std::cerr << "error writing file" << '\n';
            exit(1);
        }

        Manifest << Index << '\n';
        Lowest = Index;
        Manifest.close();
    }

    return Lowest;
}

