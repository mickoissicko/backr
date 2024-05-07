#include "../common/common.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void InitServer()
{
    printf("initialising server...\n");

    char* Path = CDToBackerFolder();
    chdir(Path);

    FILE* Serverfile;

    Serverfile = fopen("server.py", "w");

    if (Serverfile == NULL)
        printf("error writing to file\n"),
        exit(1);

    fprintf(Serverfile, "# nothing here yet");

    fclose(Serverfile);
}

