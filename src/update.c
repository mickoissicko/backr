#include "../common/filenames.h"
#include "../common/common.h"
#include "../common/urls.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define AUTO 0

void Update()
{
    char* Path = CDToBackerFolder();
    chdir(Path);

    printf("updating...\n");

    RemoveScripts();

    printf("fetching resources...\n");

    Get(INDEX_HTML, SERVER_HTML_FILE_URL);
    Get(PY_SERVER, SERVER_FILE_URL);
    Get(INDEX_VER, SERVER_VERSION_FILE);

    printf("done!\n");
    exit(0);
}

