#include "../../common/common.h"

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_VAL 4096

void EditMenu()
{
    printf("finding file...\n");

    char* Path = CDToBackerFolder();
    chdir(Path);

    FILE* Cfg;

    Cfg = fopen("cfg.yml", "w");

    if (Cfg == NULL)
    {
        printf("error manupilating file\n");
        exit(1);
    }

    char c_Ui; // i ran out of creativity...
               // variable naming sucks
    int Ui;    // to be consistent, this should be i_Ui,
               // but im not bothered lol

    char DeleteTime[MAX_VAL];
    char EndTime[MAX_VAL];
    char Addr[MAX_VAL];
    char Port[MAX_VAL];
    char Time[MAX_VAL];

    printf("***settings menu***\n");
    printf("ADDR: 127.0.0.1\n");
    printf("PORT: 80\n");
    printf("TIME: 600\n");
    printf("DEL_TIME: Off\n");
    printf("STOP_AFTER: Off\n");
    printf("***via v0.1.0.a1***\n");

    // Addr
    printf("Editing address...\n");
    printf("Don't type localhost, just use the default value\n");

    while (
        c_Ui != 'y' &&
        c_Ui != 'Y' &&
        c_Ui != 'N' &&
        c_Ui != 'n'
    ){
        printf("Use default value? [y/n]: "),
        scanf("%c", &c_Ui);
    }

    if (c_Ui == 'y' || c_Ui == 'Y')
        strcpy(Addr, "127.0.0.1");

    else
    {
        printf("New ADDR: "),
        scanf("%s", Addr);
    }

    // Port
    printf("Now editing port number...\n");

    c_Ui = '\0';
    while (
        c_Ui != 'y' &&
        c_Ui != 'Y' &&
        c_Ui != 'N' &&
        c_Ui != 'n'
    ){
        printf("Use default value? [y/n]: "),
        scanf(" %c", &c_Ui);
    }

    if (c_Ui == 'y' || c_Ui == 'Y')
        strcpy(Port, "80");

    else
    {
        printf("New PORT: "),
        scanf(" %s", Port);
    }

    // Time/clock
    printf("Editing time (save-intervals), in seconds\n");

    c_Ui = '\0';
    while (
        c_Ui != 'y' &&
        c_Ui != 'Y' &&
        c_Ui != 'N' &&
        c_Ui != 'n'
    ){
        printf("Use default value? [y/n]: "),
        scanf(" %c", &c_Ui);
    }

    if (c_Ui == 'y' || c_Ui == 'Y')
        strcpy(Time, "600");

    else
    {
        printf("Don't append unit\n");
        printf("Just type in a positive integer value\n");

        printf("New Time: "),
        scanf(" %s", Time);
    }

    // Deletion intervals
    printf("Editing deletion intervals, in seconds\n");

    c_Ui = '\0';
    while (
        c_Ui != 'y' &&
        c_Ui != 'Y' &&
        c_Ui != 'N' &&
        c_Ui != 'n'
    ){
        printf("Use default value? [y/n]: "),
        scanf(" %c", &c_Ui);
    }

    if (c_Ui == 'y' || c_Ui == 'Y')
        strcpy(DeleteTime, "Off");

    else
    {
        printf("Don't append unit\n");
        printf("Just type in a positive integer value\n");

        printf("New DelTime: "),
        scanf(" %s", DeleteTime);
    }

    // Stop after interval
    printf("Editing stop interval, in seconds\n");

    c_Ui = '\0';
    while (
        c_Ui != 'y' &&
        c_Ui != 'Y' &&
        c_Ui != 'N' &&
        c_Ui != 'n'
    ){
        printf("Use default value? [y/n]: "),
        scanf(" %c", &c_Ui);
    }

    if (c_Ui == 'y' || c_Ui == 'Y')
        strcpy(EndTime, "Off");

    else
    {
        printf("Don't append unit\n");
        printf("Just type in a positive integer value\n");

        printf("New EndTime: "),
        scanf(" %s", EndTime);
    }

    fprintf(Cfg, "ADDR: %s\n", Addr);
    fprintf(Cfg, "PORT: %s\n", Port);
    fprintf(Cfg, "TIME: %s\n", Time);
    fprintf(Cfg, "DEL_TIME: %s\n", DeleteTime);
    fprintf(Cfg, "STOP_AFTER: %s\n", EndTime);

    fclose(Cfg);
}

