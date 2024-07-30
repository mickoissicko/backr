#include "../common/common.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    printf("initialising...\n");

    if (argc >= 2 && !strcmp(argv[1], "--init"))
        Installer(argv);

    else if (argc >= 2 && !strcmp(argv[1], "--edit"))
        EditMenu();

    else if (argc >= 2 && !strcmp(argv[1], "--save"))
        MakeSave();

    else if (argc >= 2 && !strcmp(argv[1], "--run"))
        Clock();

    else if (argc >= 2 && !strcmp(argv[1], "--update"))
        CheckVersions();

    else
        Loader();

    return 0;
}

