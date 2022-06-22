@ECHO OFF && PUSHD "%~DP0" && CD /D "%~DP0"
@REM @ECHO OFF & PUSHD %~DP0 & TITLE
@REM Obfuscation batch: FEFF0D0A

:: >NUL 2>&1 REG.exe query "HKU\S-1-5-19" || (
::     ECHO SET UAC = CreateObject^("Shell.Application"^) > "%TEMP%\Getadmin.vbs"
::     ECHO UAC.ShellExecute "%~f0", "%1", "", "runas", 1 >> "%TEMP%\Getadmin.vbs"
::     "%TEMP%\Getadmin.vbs"
::     DEL /f /q "%TEMP%\Getadmin.vbs" 2>NUL
::     Exit /b
:: )
:: 
:: IF EXIST "%Public%" >NUL 2>&1 REG QUERY "HKU\S-1-5-19\Environment"
:: IF NOT %errorlevel% EQU 0 (
::     IF EXIST "%Public%" powershell.exe -windowstyle hidden -noprofile "Start-Process '%~dpnx0' -Verb RunAs"
::     EXIT
:: )>NUL

:: @ECHO OFF&(PUSHD "%~DP0")&(REG QUERY "HKU\S-1-5-19">NUL 2>&1)||(
:: powershell -Command "Start-Process '%~sdpnx0' -Verb RunAs"&&EXIT)

:: VER|FINDSTR "5\.[0-9]\.[0-9][0-9]*" > NUL && (
:: ECHO.&ECHO System OS Not supported WinXP &PAUSE>NUL&EXIT)

SET DSTLOWERCASE=a b c d e f g h i j k l m n o p q r s t u v w x y z
SET DSTUPPERCASE=A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

SET TOOLMINGW=E:/Runtime/Bins/MCF/x86/bin
SET TOOLCMAKE=E:/Runtime/Bins/WTK/CMake/x86/bin

:: //Options: Debug Release RelWithDebInfo MinSizeRel
SET BUILDMODE=Debug

:: //Options: exe dll lib mod
SET BUILDTYPE=exe

SET CMAKEPATH=CMake
SET CMAKETYPE=MinGW Makefiles

SET PATHWROOT=%CD%
SET PATHBUILD=%PATHWROOT%/%BUILDMODE%
SET PATHCACHE=%PATHWROOT%/%CMAKEPATH%

SET PARAMETER=%*
FOR %%A IN (%DSTLOWERCASE%) DO CALL SET PARAMETER=%%PARAMETER:%%A=%%A%%
:: FOR %%A IN (%DSTUPPERCASE%) DO CALL SET PARAMETER=%%PARAMETER:%%A=%%A%%

FOR %%A IN (%PARAMETER%) DO (
    FOR %%B IN ("clean" "clear" "cls") DO IF "%%A" EQU %%B (
        IF EXIST "%PATHWROOT%\%CMAKEPATH%" (RMDIR /S /Q "%PATHWROOT%\%CMAKEPATH%")
        IF EXIST "%PATHWROOT%\%BUILDMODE%" (RMDIR /S /Q "%PATHWROOT%\%BUILDMODE%")

        IF EXIST "%PATHWROOT%\Debug" (RMDIR /S /Q "%PATHWROOT%\Debug")
        IF EXIST "%PATHWROOT%\Release" (RMDIR /S /Q "%PATHWROOT%\Release")
        IF EXIST "%PATHWROOT%\MinSizeRel" (RMDIR /S /Q "%PATHWROOT%\MinSizeRel")
        IF EXIST "%PATHWROOT%\RelWithDebInfo" (RMDIR /S /Q "%PATHWROOT%\RelWithDebInfo")
        ECHO [*] Cleanup completed!
        EXIT
    )

    FOR %%B IN ("rebuild" "rb" "re") DO IF "%%A" EQU %%B (
        IF EXIST "%PATHWROOT%\%CMAKEPATH%" (RMDIR /S /Q "%PATHWROOT%\%CMAKEPATH%")
        IF EXIST "%PATHWROOT%\%BUILDMODE%" (RMDIR /S /Q "%PATHWROOT%\%BUILDMODE%")
        ECHO [*] Rebuild completed!
    )

    FOR %%B IN ("x32" "32") DO IF "%%A" EQU %%B (
        SET TOOLMINGW=E:/Runtime/Bins/MCF/x86/bin
        SET TOOLCMAKE=E:/Runtime/Bins/WTK/CMake/x86/bin
        ECHO [*] Setting Project to x86!
    )
    FOR %%B IN ("x64" "64") DO IF "%%A" EQU %%B (
        SET TOOLMINGW=E:/Runtime/Bins/MCF/x64/bin
        SET TOOLCMAKE=E:/Runtime/Bins/WTK/CMake/x64/bin
        ECHO [*] Setting Project to x64!
    )
 
    FOR %%B IN ("Debug" "debug") DO IF "%%A" EQU %%B (SET BUILDMODE=Debug)
    FOR %%B IN ("Release" "release") DO IF "%%A" EQU %%B (SET BUILDMODE=Release)
    FOR %%B IN ("MinSizeRel" "minsizerel") DO IF "%%A" EQU %%B (SET BUILDMODE=MinSizeRel)
    FOR %%B IN ("RelWithDebInfo" "relwithdebinfo") DO IF "%%A" EQU %%B (SET BUILDMODE=RelWithDebInfo)

    FOR %%B IN ("exe" "EXE") DO IF "%%A" EQU %%B (SET BUILDTYPE=exe)
    FOR %%B IN ("dll" "DLL") DO IF "%%A" EQU %%B (SET BUILDTYPE=dll)
    FOR %%B IN ("lib" "LIB") DO IF "%%A" EQU %%B (SET BUILDTYPE=lib)
    FOR %%B IN ("mod" "MOD") DO IF "%%A" EQU %%B (SET BUILDTYPE=mod)
)

SET CMAKEPARM=-D CMAKE_BUILD_TYPE:STRING="%BUILDMODE%"
SET CMAKEPARM=%CMAKEPARM% -D BUILD_BINRARY_TYPE:STRING="%BUILDTYPE%"
SET CMAKEPARM=%CMAKEPARM% -D CMAKE_SHARED_LINKER_FLAGS:STRING="-Wl,--output-def=../%BUILDMODE%/SymbolEx.def"
SET CMAKEPARM=%CMAKEPARM% -D CMAKE_VERBOSE_MAKEFILE:BOOL=ON -D CMAKE_C_COMPILER:STRING="%TOOLMINGW%/gcc.exe"
SET CMAKEPARM=%CMAKEPARM% -D CMAKE_VERBOSE_MAKEFILE:BOOL=ON -D CMAKE_CXX_COMPILER:STRING="%TOOLMINGW%/g++.exe"

%TOOLCMAKE%/CMAKE.EXE -G "%CMAKETYPE%" -B "%PATHCACHE%" %CMAKEPARM%
%TOOLMINGW%/MINGW32-MAKE.EXE -C "%PATHCACHE%"

FOR %%A IN (%ERRORLEVEL%) DO (
    IF %%A EQU 0 (ECHO [*] Build completed! Code: %%A && EXIT)
    IF %%A EQU 2 (ECHO [!] Build failed! Code: %%A && EXIT)
    ECHO [!] Build terminated! Code: %%A
)