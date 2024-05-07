#include "../common/common.h"

#include <string.h>
#include <stdio.h>
#include <strings.h>

#define MAX_LEN 1024

// --init
// --edit

void Loader()
{
    printf("welcome!\n");
    printf("looks like you didn't type any argument\n");
    printf("...\n");

    char Ui[MAX_LEN];

    printf("well... type smth here so I can take you there:\n");
    printf("availble commands:\nedit\ninit\n");

    while (
        strcasecmp(Ui, "edit") &&
        strcasecmp(Ui, "init")
    ){
        printf("> "),
        scanf("%s", Ui);
    }

    if (!strcasecmp(Ui, "edit"))
        EditMenu();

    else if (!strcasecmp(Ui, "init"))
    {
        char* Flag[] = {NULL, "--init"};

        Installer(Flag);
    }
}

