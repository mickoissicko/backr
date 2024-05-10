#include "../common/common.h"
#include "../common/urls.h"

#include <unistd.h>
#include <stdio.h>

#define AUTO 0

void DownloadScripts()
{
    printf("establishing connection...\n");

    char* Cwd;
    getcwd(Cwd, AUTO);

    char* Path = CDToBackerFolder();
    chdir(Path);

    Get("server.py", SERVER_FILE_URL);
    Get("index.html", SERVER_HTML_FILE_URL);
    Get("version.info", SERVER_VERSION_FILE);

    chdir(Cwd);

    CheckVersions();
}

