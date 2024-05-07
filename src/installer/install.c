#include "../../common/common.h"
#include "../../lib/gethome.h"

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

        printf("this program offers a user-friendly and intuitive web-UI\n");
        printf("however, it requires python to be installed\n");
        printf("this program will try installing python itself\n");

        char Ui;

        while (Ui != 'y' && Ui != 'Y' && Ui != 'n' && Ui != 'N')
        {
            printf("do you want to use the web-UI? [y/n]: ");
            scanf("%c", &Ui);
        }

        if (Ui == 'Y' || Ui == 'y')
        {
            printf("checking prerequisites...\n");
            GetPython();
        }

        else
            printf("you can edit the config via the '--edit' flag\n");

        free(Path);
        return 0;
    }

    else if (!strcmp(flag[1], "--edit"))
    {
        char* Path = gethome();

        if (chdir(Path) != 0)
        {
            printf("error changing directory xd\n");
            free(Path);
            exit(1);
        }

        free(Path);
        return 0;
    }

    printf("no option selected\n");
    return 1;
}

