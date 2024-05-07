#include "../../common/common.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void GetPython()
{
    printf("preparing..\n");

    PrepareScripts();

    char* Path = CDToBackerFolder();
    chdir(Path);

    #ifdef _WIN32
        system("ntpy.bat");
    #else
        system("chmod +x nixpy.sh");
        system("./nixpy.sh");
    #endif
}

