#include <filesystem>
#include <iostream>

namespace fs = std::filesystem; // yes, i finally used it

void Prepare()
{
    std::cout << "initialising folders..." << '\n';

    if (!fs::exists(".mix"))
        fs::create_directories(".mix");

    std::cout << "making program folder..." << '\n';

    if (!fs::exists("backer"))
        fs::create_directories("backer");
}

