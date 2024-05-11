#include "../common/filenames.h"
#include "../common/common.h"
#include "../common/urls.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZ 512
#define AUTO 0

void Update()
{
    char* Path = CDToBackerFolder();
    chdir(Path);

    FILE* NewVersion;
    NewVersion = fopen(INDEX_NEW_VER, "r");

    if (NewVersion == NULL)
    {
        Get("new.version.info", SERVER_VERSION_FILE);
        NewVersion = fopen(INDEX_NEW_VER, "r");

        if (NewVersion == NULL)
        {
            perror("failed to read (1)\n");
            exit(1);
        }
    }

    char Info[MAX_SIZ];

    fgets(Info, MAX_SIZ, NewVersion);
    fclose(NewVersion);

    RemoveScripts();

    printf("fetching resources...\n");

    Get(INDEX_HTML, SERVER_HTML_FILE_URL);
    Get(PY_SERVER, SERVER_FILE_URL);

    printf("updating index...\n");

    Get(INDEX_VER, SERVER_VERSION_FILE);

    FILE* Version;
    Version = fopen(INDEX_VER, "w");

    if (Version == NULL)
    {
        perror("error reading from file (2)\n");
        exit(1);
    }

    fprintf(Version, "%s", Info);

    fclose(Version);
    exit(0);
}

