#ifndef GETHOME_H
    #define GETHOME_H
#endif

#ifndef _WIN32
    #include "linux.h"
    static char* gethome();

#else
    #include "win32.h"
    static char* gethome();
#endif

