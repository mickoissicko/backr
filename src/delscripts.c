#include "../common/filenames.h"
#include "../common/common.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void RemoveScripts()
{
    char* Path = CDToBackerFolder();
    chdir(Path);

    if (
        remove(INDEX_NEW_VER) != 0 ||
        remove(INDEX_HTML)    != 0 ||
        remove(PY_SERVER)     != 0 ||
        remove(INDEX_VER)     != 0
    ){
        printf("error deleting\n");
        printf("maybe insufficient permissions?\n");
        printf("or you didn't install the program yet\n");
        exit(1);
    }
}

