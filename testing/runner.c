#include "../common/common.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    PrepareScripts();

    system("ls");
    system("touch abc.d");
}

