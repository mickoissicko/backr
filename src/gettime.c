#include "../common/common.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUF 4096

int GetStdTime()
{
    int Interval;
    char* Path = CDToBackerFolder();

    chdir(Path);

    FILE* Cfg;
    Cfg = fopen("cfg.yml", "r");

    if (Cfg == NULL)
    {
        printf("Run config editor first!\n");
        exit(1);
    }

    char Ln[BUF];

    fgets(Ln, BUF, Cfg); // read line 1
    fgets(Ln, BUF, Cfg); // read line 2
    fgets(Ln, BUF, Cfg); // read line 3

    char* Delim = "TIME: ";

    if (strstr(Ln, Delim) == Ln)
    {
        if (sscanf(Ln + strlen(Delim), "%d", &Interval) != 1)
            return 0;
    }

    fclose(Cfg);

    return Interval;
}

int GetEndTime()
{
    int Interval;
    char* Path = CDToBackerFolder();

    chdir(Path);

    FILE* Cfg;
    Cfg = fopen("cfg.yml", "r");

    if (Cfg == NULL)
    {
        printf("Run config editor first!\n");
        exit(1);
    }

    char Ln[BUF];

    fgets(Ln, BUF, Cfg); // read line 1
    fgets(Ln, BUF, Cfg); // read line 2
    fgets(Ln, BUF, Cfg); // read line 3
    fgets(Ln, BUF, Cfg); // read line 4
    fgets(Ln, BUF, Cfg); // read line 5

    char* Delim = "STOP_AFTER: ";

    if (strstr(Ln, Delim) == Ln)
    {
        if (sscanf(Ln + strlen(Delim), "%d", &Interval) != 1)
            return 0;
    }

    fclose(Cfg);

    return Interval;
}

int GetDelTime()
{
    char* Path = CDToBackerFolder();
    chdir(Path);

    FILE* Cfg;
    Cfg = fopen("cfg.yml", "r");

    if (Cfg == NULL)
    {
        printf("Run config editor first!\n");
        exit(1);
    }

    char Ln[BUF];

    fgets(Ln, BUF, Cfg); // read line 1
    fgets(Ln, BUF, Cfg); // read line 2
    fgets(Ln, BUF, Cfg); // read line 3
    fgets(Ln, BUF, Cfg); // read line 4

    if (!strcmp(Ln, "DEL_TIME: Off"))
        exit(0);

    int Interval;
    char* Delim = "DEL_TIME: ";

    if (strstr(Ln, Delim) == Ln)
    {
        if (sscanf(Ln + strlen(Delim), "%d", &Interval) != 1)
            return 0;
    }

    fclose(Cfg);

    return Interval;
}

