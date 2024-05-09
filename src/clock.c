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

    int Current = 0;
    int End = GetEndTime();

    while (End != 0)
    {
        int Std = GetStdTime();
        int Del = GetDelTime();

        chdir(Cwd);

        if (Current % Std == 0)
            DirectSaver();

        if (Current % Del == 0)
            RemoveOldest();

        chdir(Cwd);

        Hlt(1);
        End--;
        Current++;
    }
}


