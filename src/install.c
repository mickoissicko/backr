#include "../common/common.h"
#include "../lib/gethome.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int Installer(char** flag)
{
    if (!strcmp(flag[1], "--init"))
    {
        printf("fetching home folder...\n");

        char* Path = strcpy(Path, gethome());

        if (chdir(Path) != 0)
            printf("sucess (0)\n");
        else
        {
            printf("failure (1)\n");
            free(Path);
            exit(1);
        }

        printf("preparing...");
        Prepare();

        printf("verifying prerequisites...\n");
        GetPython();

        free(Path);
        return 0;
    }

    printf("no option selected\n");
    return 1;
}

