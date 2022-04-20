@ECHO OFF & PUSHD "%~DP0" && CD /D "%~DP0"
@REM @ECHO OFF & PUSHD %~DP0 & TITLE
@REM Obfuscation batch: FEFF0D0A

>NUL 2>&1 REG.eXE query "HKU\S-1-5-19" || (
    ECHO SET UAC = CreateObject^("Shell.Application"^) > "%TEMP%\Getadmin.vbs"
    ECHO UAC.ShellExecute "%~f0", "%1", "", "runas", 1 >> "%TEMP%\Getadmin.vbs"
    "%TEMP%\Getadmin.vbs"
    DEL /f /q "%TEMP%\Getadmin.vbs" 2>NUL
    Exit /b
)

IF EXIST "%Public%" >NUL 2>&1 REG QUERY "HKU\S-1-5-19\Environment"
IF NOT %errorlevel% EQU 0 (
    IF EXIST "%Public%" POWERSHELL.EXE -windowstyle hidden -noprofile "Start-Process '%~dpnx0' -Verb RunAs"
    EXIT
)>NUL

::@ECHO OFF&(PUSHD "%~DP0")&(REG QUERY "HKU\S-1-5-19">NUL 2>&1)||(
::POWERSHELL.EXE -Command "Start-Process '%~sdpnx0' -Verb RunAs"&&EXIT)

::VER|FINDSTR "5\.[0-9]\.[0-9][0-9]*" > NUL && (
::ECHO.&ECHO  WinOS Not Supported WinXP &PAUSE>NUL&EXIT)

:: //Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel
SET MODE_BUILD=Debug

:: //Choose the type of build, options are: rc exe dll lib mod
SET MODE_TYPES=exe

:: //Choose the type of build, options are: Platform
SET TOOL_BUILD=E:/Runtime/Bins/MCF/x86/bin

SET CMAKE_FILE=CMake
SET CMAKE_TYPE=MinGW Makefiles

SET PATH_WROOT=%CD%
SET PATH_BUILD=%PATH_WROOT%\%MODE_BUILD%
SET PATH_CMAKE=%PATH_WROOT%\%CMAKE_FILE%

:: Format String "var"
SET ARGS_FRMAT=%*
for /F "delims=" %%A IN ("%*") DO SET ARGS_FRMAT=%%~A

FOR %%A IN (%ARGS_FRMAT%) DO (

    :: Clean project
    FOR %%B IN ("clean" "clear" "cls") DO IF "%%A"==%%B (
        IF EXIST "%PATH_WROOT%\%CMAKE_FILE%" (RMDIR /S /Q "%PATH_WROOT%\%CMAKE_FILE%")

        IF EXIST "%PATH_WROOT%\Debug" (RMDIR /S /Q "%PATH_WROOT%\Debug")
        IF EXIST "%PATH_WROOT%\Release" (RMDIR /S /Q "%PATH_WROOT%\Release")
        IF EXIST "%PATH_WROOT%\MinSizeRel" (RMDIR /S /Q "%PATH_WROOT%\MinSizeRel")
        IF EXIST "%PATH_WROOT%\RelWithDebInfo" (RMDIR /S /Q "%PATH_WROOT%\RelWithDebInfo")
        ECHO [*] Clean is done!
        EXIT
    )

    FOR %%B IN ("rebuild" "rb" "re") DO IF "%%A"==%%B (
        IF EXIST "%PATH_WROOT%\%CMAKE_FILE%" (RMDIR /S /Q "%PATH_WROOT%\%CMAKE_FILE%")

        IF EXIST "%PATH_WROOT%\Debug" (RMDIR /S /Q "%PATH_WROOT%\Debug")
        IF EXIST "%PATH_WROOT%\Release" (RMDIR /S /Q "%PATH_WROOT%\Release")
        IF EXIST "%PATH_WROOT%\MinSizeRel" (RMDIR /S /Q "%PATH_WROOT%\MinSizeRel")
        IF EXIST "%PATH_WROOT%\RelWithDebInfo" (RMDIR /S /Q "%PATH_WROOT%\RelWithDebInfo")
        ECHO [*] Clean is done!
    )

    :: Setting project build vars
    FOR %%B IN ("x32" "32") DO IF "%%A"==%%B (SET TOOL_BUILD=E:/Runtime/Bins/MCF/x86/bin)
    FOR %%B IN ("x64" "64") DO IF "%%A"==%%B (SET TOOL_BUILD=E:/Runtime/Bins/MCF/x64/bin)

    FOR %%B IN ("Debug" "debug") DO IF "%%A"==%%B (SET MODE_BUILD=Debug)
    FOR %%B IN ("Release" "release") DO IF "%%A"==%%B (SET MODE_BUILD=Release)
    FOR %%B IN ("MinSizeRel" "minsizerel") DO IF "%%A"==%%B (SET MODE_BUILD=MinSizeRel)
    FOR %%B IN ("RelWithDebInfo" "relwithdebinfo") DO IF "%%A"==%%B (SET MODE_BUILD=RelWithDebInfo)

    FOR %%B IN ("exe" "EXE") DO IF "%%A"==%%B (SET MODE_TYPES=exe)
    FOR %%B IN ("dll" "DLL") DO IF "%%A"==%%B (SET MODE_TYPES=dll)
    FOR %%B IN ("lib" "LIB") DO IF "%%A"==%%B (SET MODE_TYPES=lib)
)

:: DEBUG View
:: ECHO %MODE_BUILD%
:: ECHO %MODE_TYPES%
:: ECHO Args: %*
:: EXIT

SET CMAKE_PARM=-D CMAKE_BUILD_TYPE:STRING="%MODE_BUILD%"
SET CMAKE_PARM=%CMAKE_PARM% -D BUILD_BINRARY_TYPE:STRING="%MODE_TYPES%"
SET CMAKE_PARM=%CMAKE_PARM% -D CMAKE_SHARED_LINKER_FLAGS:STRING="-Wl,--output-def=../%MODE_BUILD%/APIStatus.def.txt"
SET CMAKE_PARM=%CMAKE_PARM% -D CMAKE_VERBOSE_MAKEFILE:BOOL=ON -D CMAKE_C_COMPILER:STRING="%TOOL_BUILD%/gcc.exe"
SET CMAKE_PARM=%CMAKE_PARM% -D CMAKE_VERBOSE_MAKEFILE:BOOL=ON -D CMAKE_CXX_COMPILER:STRING="%TOOL_BUILD%/g++.exe"

CMAKE.EXE -G "%CMAKE_TYPE%" -B "%PATH_CMAKE%" %CMAKE_PARM%
MINGW32-MAKE.EXE -C "%PATH_CMAKE%"
:: RMDIR /S /Q "%PATH_CMAKE%\CMakeFiles" && ECHO [*] CMakeFiles has remove
