#include "../common/common.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void Runner()
{
    printf("finding folders...\n");

    char* Path = CDToBackerFolder();
    chdir(Path);

    exit(0);
}

