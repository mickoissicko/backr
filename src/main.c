#include "../common/common.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    printf("initialising...\n");

    if (argv[1] != NULL)
        Installer(argv);
    else
        Loader();

    if (argc >= 2 && !strcmp(argv[1], "--edit"))
        EditMenu();

    if (argc >= 2 && !strcmp(argv[1], "--save"))
        MakeSave();

    if (argc >= 2 && !strcmp(argv[1], "--run"))
        Clock();

    return 0;
}

