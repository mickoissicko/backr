#include "../common/common.h"
#include "../lib/gethome.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    printf("fetching home folder...\n");

    char* Path = strcpy(Path, gethome());

    if (Path != NULL)
        printf("sucess (0)\n");
    else
    {
        printf("failure (1)\n");
        free(Path);
        exit(1);
    }

    chdir(Path);

    printf("preparing...");
    Prepare();

    free(Path);
    return 0;
}

