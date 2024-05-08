#include "../common/common.h"
#include "../lib/sleep.h"

#include <stdio.h>

void Clock()
{
    int Std = GetStdTime();
    int Del = GetDelTime();
    int End = GetEndTime();

    MakeSave();

    int Index;

    while (Index != End)
    {
        Hlt(Std);
        DirectSaver();

        if (Index == Del)
            RemoveOldest();

        Index++;
    }
}

