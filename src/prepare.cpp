#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

// yes, im finally shortening stuff

using namespace std;

namespace Fs = std::filesystem;
typedef std::ifstream Read; 
typedef std::ofstream Write;

void MkCfgs()
{
    int Ui;

    if (chdir("backer") != 0)
    {
        cerr << "error noob" << '\n';
        exit(1);
    }

    Write Cfg("cfg.yml");

    if (!Cfg.is_open())
    {
        cerr << "couldn't write file" << '\n';
        exit(1);
    }

    Cfg << "# rerun program with --edit" << '\n'
        << "# this will open the edit menu" << '\n'
        << "# then you can personalise and customise!" << '\n';

    Cfg.close();
}

void Prepare()
{
    cout << "initialising folders..." << '\n';

    if (!Fs::exists(".mix"))
        Fs::create_directories(".mix");

    cout << "making program folder..." << '\n';

    if (!Fs::exists("backer"))
        Fs::create_directories("backer");

    cout << "making config..." << '\n';

    MkCfgs();
}

