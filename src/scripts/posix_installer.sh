#!/bin/bash

exists()
{
    command -v "$1" > /dev/null 2 >& 1
}

if exists python3; then
    echo 'Python is already installed'
    exit 0
fi

if exists apt-get; then
    # Debian
    sudo apt-get update
    sudo apt-get install -y python3

elif exists yum; then
    # Redhat
    sudo yum install -y python3

elif exists pacman; then
    # Archlinux
    sudo pacman -Sy --noconfirm python

elif exists apk; then
    # Alpine
    sudo apk add --update python3

elif exists dnf; then
    # Fedora
    sudo dnf install -y python3

elif exists zypper; then
    # Opensussy
    sudo zypper install -y python3

elif exists brew; then
    # MacOS
    brew install python3

elif exists port; then
    # MacOS
    sudo port install python3

elif exists pkg; then
    # FreeBSD
    sudo pkg install -y python3

elif exists emerge; then
    # Gentoo
    sudo emerge --ask --noreplace dev-lang/python

elif exists eopkg; then
    # Solus
    sudo eopkg install -y python3

elif exists guix; then
    # Guix
    sudo guix package -i python

else
    echo 'Unsupported package manager, install Python manually'
    exit 1
fi

if exists python3; then
    echo 'Python was sucessfully installed'
    exit 0

else
    echo 'There was an error, please install Python manually'
    exit 1
fi

