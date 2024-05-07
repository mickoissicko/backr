#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_STR_LEN 8192

static char* gethome()
{
    unsigned long LEN = MAX_STR_LEN;

    char* HomeDirectory = getenv("USERPROFILE");

    return HomeDirectory;
}

