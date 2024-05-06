@ECHO OFF
REM Maximum compatibility

python --version >NUL 2>&1
IF %ERRORLEVEL% EQU 0 (
    EXIT
)

wget https://www.python.org/ftp/python/3.11.9/python-3.11.9.exe
python-3.11.9.exe /quiet PrependPath=1

