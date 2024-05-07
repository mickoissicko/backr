#include "../common/common.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("finding folders...\n");

    char* Path = CDToBackerFolder();

    printf("%s", Path);
    chdir(Path);


    exit(0);
}

