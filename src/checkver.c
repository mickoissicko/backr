#include "../common/common.h"
#include "../common/urls.h"

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXBUF 512
#define AUTO 0

void CheckVersions()
{
    char* Path = CDToBackerFolder();
    chdir(Path);
    char Line[MAXBUF];

    FILE* VersionFile;
    VersionFile = fopen("VERSION", "r");

    if (VersionFile == NULL)
    {
        Get("VERSION", SERVER_VERSION_FILE);

        VersionFile = fopen("VERSION", "r");

        if (VersionFile == NULL)
        {
            perror("error opening file\n");
            exit(1);
        }
    }

    fgets(Line, sizeof(Line), VersionFile);
    fclose(VersionFile);

    char* Version = (char*)malloc(MAXBUF * sizeof(char));
    Version = strchr(Line, '=');

    if (Version == NULL)
    {
        printf("failure (1)\n");
        exit(1);
    }

    Version += 2;

    FILE* LatestVer;
    LatestVer = fopen("new.version.info", "r");

    if (LatestVer != NULL)
    {
        remove("new.version.info");
        fclose(LatestVer);
    }

    Get("new.version.info", SERVER_VERSION_FILE);

    LatestVer = fopen("new.version.info", "r");

    if (LatestVer == NULL)
    {
        perror("error reading file\n");
        exit(1);
    }

    char LatestLine[MAXBUF];
    fgets(LatestLine, sizeof(LatestLine), LatestVer);

    fclose(LatestVer);

    char* LatestVersion = (char*)malloc(MAXBUF * sizeof(char));

    LatestVersion = strchr(LatestLine, '=');
    LatestVersion += 2;

    int Latest;
    int Current;

    sscanf(LatestVersion, "%d", &Latest);
    sscanf(Version, "%d", &Current);

    if (Latest != Current || Latest > Current)
    {
        printf("newer version available\n");
        printf("updating...\n");

        Update();
    }
}

