#ifndef SLEEP_H
    #define SLEEP_H
#endif

#ifdef _WIN32
    #include <Windows.h>

    static void Hlt(unsigned int ms)
    {
        Sleep(ms);
    }
#else
    #include <unistd.h>

    static void Hlt(unsigned int s)
    {
        sleep(s);
    }
#endif

