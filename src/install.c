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

        char* Path = gethome();

        if (
            chdir(Path) != 0 &&
            chdir(MIX)  != 0 &&
            chdir(BAK)  != 0
        )
            printf("failure (1)\n"),
            free(Path),
            exit(1);

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

