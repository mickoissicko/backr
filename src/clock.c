#include "../common/common.h"
#include "../lib/sleep.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZ 8192
#define LS system("ls");

void Clock()
{
    char Cwd[MAX_SIZ];

    if (getcwd(Cwd, MAX_SIZ) == NULL)
    {
        perror("error\n");
        exit(1);
    }

    int End = GetEndTime();
    int Std = GetStdTime();
    int Del = GetDelTime();
    int Current = 0;

    if (End == 0)
    {
        printf("(i) stopping is switched off\n");

        while (1)
        {
            chdir(Cwd);

            if (Current % Std == 0)
                DirectSaver();

            if (Del != 0 && Current % Del == 0)
                RemoveOldest();

            chdir(Cwd);
            Hlt(1);

            Current++;
        }
    }

    if (Del == 0)
        printf("(i) deletion is switched off\n");

    while (End != 0)
    {
        chdir(Cwd);

        if (Current % Std == 0)
            DirectSaver();

        if (Del != 0 && Current % Del == 0)
            RemoveOldest();

        chdir(Cwd);

        Hlt(1);

        End--;
        Current++;
    }
}


