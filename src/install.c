#include "../common/common.h"
#include "../common/paths.h"
#include "../lib/gethome.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int Installer(char** flag)
{
    if (!strcmp(flag[1], "--init"))
    {
        printf("fetching home folder...\n");

        char* Path = CDToBackerFolder();
        chdir(Path);

        printf("preparing...");
        Prepare();
        printf("verifying prerequisites...\n");

        GetPython();
        InitServer();

        free(Path);
        return 0;
    }

    printf("no option selected\n");
    return 1;
}

