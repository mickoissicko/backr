#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>

#define MAX_STR_LEN 8192

static char* gethome()
{
    struct passwd *Home;

    char* Path = NULL;

    if ((Home = getpwuid(getuid())) != NULL)
    {
        Path = (char*)malloc(MAX_STR_LEN);

        if (Path != NULL)
            strcpy(Path, Home->pw_dir);
    }

    return Path;
}

