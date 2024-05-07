#include "../../common/paths.h"
#include "../../lib/gethome.h"

#include <unistd.h>
#include <stdio.h>

#define MAX_PATH_LEN 8192

char* CDToBackerFolder()
{
    char* Path = gethome();

    if (
        chdir(Path) != 0 &&
        chdir(MIX)  != 0 &&
        chdir(BAK)  != 0
    ){
        printf("error changing directory\n");
        printf("try running '--init' first :shrug:\n");
        exit(1);
    }

    char* FinalPath = malloc(MAX_PATH_LEN * sizeof(char));
    snprintf(FinalPath, MAX_PATH_LEN, "%s/%s/%s", Path, MIX, BAK);

    return FinalPath;
}

