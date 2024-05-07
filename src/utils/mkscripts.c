#include "../../common/common.h"

#include <unistd.h>
#include <stdio.h>

void PrepareScripts()
{
    printf("finding folders...\n");

    char* Path = CDToBackerFolder();
    chdir(Path);

    FILE* Win32;
    Win32 = fopen("ntpy.bat", "w");

    fprintf(Win32, "@ECHO OFF\n");
    fprintf(Win32, "REM Maximum compatibility\n\n");
    fprintf(Win32, "python --version >NUL 2>&1\n");
    fprintf(Win32, "IF %%ERRORLEVEL%% EQU 0 (\n");
    fprintf(Win32, "    EXIT\n");
    fprintf(Win32, ")\n\n");
    fprintf(Win32, "wget https://www.python.org/ftp/python/3.11.9/python-3.11.9.exe\n");
    fprintf(Win32, "python-3.11.9.exe /quiet PrependPath=1\n");

    fclose(Win32);

    FILE* Posix;
    Posix = fopen("nixpy.sh", "w");

    fprintf(Posix, "#!/bin/bash\n\n");
    fprintf(Posix, "exists()\n");
    fprintf(Posix, "{\n");
    fprintf(Posix, "    command -v \"$1\" > /dev/null 2>&1\n");
    fprintf(Posix, "}\n\n");
    fprintf(Posix, "if exists python3; then\n");
    fprintf(Posix, "    echo 'Python is already installed'\n");
    fprintf(Posix, "    exit 0\n");
    fprintf(Posix, "fi\n\n");
    fprintf(Posix, "if exists apt-get; then\n");
    fprintf(Posix, "    # Debian\n");
    fprintf(Posix, "    sudo apt-get update\n");
    fprintf(Posix, "    sudo apt-get install -y python3\n\n");
    fprintf(Posix, "elif exists yum; then\n");
    fprintf(Posix, "    # Redhat\n");
    fprintf(Posix, "    sudo yum install -y python3\n\n");
    fprintf(Posix, "elif exists pacman; then\n");
    fprintf(Posix, "    # Archlinux\n");
    fprintf(Posix, "    sudo pacman -Sy --noconfirm python\n\n");
    fprintf(Posix, "elif exists apk; then\n");
    fprintf(Posix, "    # Alpine\n");
    fprintf(Posix, "    sudo apk add --update python3\n\n");
    fprintf(Posix, "elif exists dnf; then\n");
    fprintf(Posix, "    # Fedora\n");
    fprintf(Posix, "    sudo dnf install -y python3\n\n");
    fprintf(Posix, "elif exists zypper; then\n");
    fprintf(Posix, "    # OpenSUSE\n");
    fprintf(Posix, "    sudo zypper install -y python3\n\n");
    fprintf(Posix, "elif exists brew; then\n");
    fprintf(Posix, "    # MacOS with Homebrew\n");
    fprintf(Posix, "    brew install python3\n\n");
    fprintf(Posix, "elif exists port; then\n");
    fprintf(Posix, "    # MacOS with MacPorts\n");
    fprintf(Posix, "    sudo port install python3\n\n");
    fprintf(Posix, "elif exists pkg; then\n");
    fprintf(Posix, "    # FreeBSD\n");
    fprintf(Posix, "    sudo pkg install -y python3\n\n");
    fprintf(Posix, "elif exists emerge; then\n");
    fprintf(Posix, "    # Gentoo\n");
    fprintf(Posix, "    sudo emerge --ask --noreplace dev-lang/python\n\n");
    fprintf(Posix, "elif exists eopkg; then\n");
    fprintf(Posix, "    # Solus\n");
    fprintf(Posix, "    sudo eopkg install -y python3\n\n");
    fprintf(Posix, "elif exists guix; then\n");
    fprintf(Posix, "    # Guix\n");
    fprintf(Posix, "    sudo guix package -i python\n\n");
    fprintf(Posix, "else\n");
    fprintf(Posix, "    echo 'Unsupported package manager, install Python manually'\n");
    fprintf(Posix, "    exit 1\n");
    fprintf(Posix, "fi\n\n");
    fprintf(Posix, "if exists python3; then\n");
    fprintf(Posix, "    echo 'Python was successfully installed'\n");
    fprintf(Posix, "    exit 0\n");
    fprintf(Posix, "else\n");
    fprintf(Posix, "    echo 'There was an error, please install Python manually'\n");
    fprintf(Posix, "    exit 1\n");
    fprintf(Posix, "fi\n");

    fclose(Posix);
}

