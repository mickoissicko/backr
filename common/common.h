#ifndef COMMON_H
    #define COMMON_H
#endif

char* CDToBackerFolder();

void Get(const char FILENAME[], const char URL[]);
void PrepareScripts();
void RemoveOldest();
void DirectSaver();
void InitServer();
void GetPython();
void EditMenu();
void MakeSave();
void Prepare();
void Loader();
void Clock();

int Installer(char** flag);
int GetStdTime();
int GetDelTime();
int GetEndTime();

