#include "../common/common.h"
#include "../lib/sleep.h"

void Clock()
{
    int CurrentTime = 0;

    int Std = GetStdTime();
    int Del = GetDelTime();
    int End = GetEndTime();

    while (CurrentTime != End)
    {
        if (CurrentTime == Std)
            DirectSaver();

        if (CurrentTime == Del)
            RemoveOldest();

        Hlt(1);
        CurrentTime++;
    }
}

