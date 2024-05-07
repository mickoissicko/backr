#include "../common/common.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ARG_LEN 256
#define MAX_LEN 1024

// --init
// --edit

int main(int argc, char** argv)
{
    if (argv != NULL)
    {
        Installer(argv);
        exit(0);
    }

    printf("welcome!\n");
    printf("looks like you didn't type any argument\n");
    printf("...\n");

    char Ui[MAX_LEN];

    printf("well... type smth here so I can take you there: ");

    while (
        !!strcasecmp(Ui, "edit") &&
        !!strcasecmp(Ui, "init")
    ){
        printf(">");
        scanf("%s", Ui);

        if (
            !!strcasecmp(Ui, "edit") &&
            !!strcasecmp(Ui, "init")
        ){
            printf("buddy, i think there was a typo\n");
            printf("let me help you to a list of commands\n");

            printf("edit\ninit\n");
        }
    }

    // https://i.ibb.co/rtYH1k6/image-psd.jpg
    // :skull:

    char* ArgBuf = malloc(ARG_LEN * sizeof(char));

    if (strcasecmp(Ui, "edit"))
    {
        strcpy(ArgBuf, "--edit");
        Installer(&ArgBuf);

        exit(0);
    }

    else if (strcasecmp(Ui, "init"))
    {
        strcpy(ArgBuf, "--init");
        Installer(&ArgBuf);

        exit(0);
    }

    return 0;
}

