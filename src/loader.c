#include "../common/common.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 1024

void Loader()
{
    printf("welcome!\n");
    printf("looks like you didn't type any argument\n");
    printf("...\n");

    char Ui[MAX_LEN];

    printf("well... type smth here so I can take you there:\n");
    printf("availble commands:\nedit\ninit\nsave\nupdate\nrun\nexit\n");

    while (
        strcasecmp(Ui, "edit")   &&
        strcasecmp(Ui, "init")   &&
        strcasecmp(Ui, "save")   &&
        strcasecmp(Ui, "update") &&
        strcasecmp(Ui, "run")    &&
        strcasecmp(Ui, "exit")
    ){
        printf("> "),
        scanf("%s", Ui);
    }

    if (!strcasecmp(Ui, "edit"))
        EditMenu();

    else if (!strcasecmp(Ui, "save"))
        MakeSave();

    else if (!strcasecmp(Ui, "update"))
        CheckVersions();

    else if (!strcasecmp(Ui, "run"))
        Clock();

    else if (!strcasecmp(Ui, "exit"))
        exit(0);

    else if (!strcasecmp(Ui, "init"))
    {
        char* Flag[] = {NULL, "--init"};

        Installer(Flag);
    }

    exit(0);
}

