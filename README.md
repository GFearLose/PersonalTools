![image](https://github.com/GFearLose/PersonalTools/raw/master/GuiMain.png)
# PersonalTools - WinOS (Only)
- Tools&Platform:<br>
&emsp;Visual Studio Code<br>
&emsp;MinGW GCC with the MCF thread model<br>
&emsp;Batch Scirpt && CMake<br>

- OS Platform:<br>
&emsp;Windows 10 x64

- Using API:<br>
&emsp;SHGetKnownFolderPath<br>
&emsp;SHSetKnownFolderPath<br>
&emsp;GetFileAttributesW<br>
&emsp;SHCreateDirectory<br>

# How to build ?
<h2>MSVC Build</h2>
&emsp;Import to Visual Studio ? (not test)<bt>

<h2>MinGW Build</h2>
&emsp;You need to config GCC compiler path in CMakeScript.bat<br>
&emsp;&emsp;Build EXE Run command: ./CMakeScript.bat debug exe<br>
&emsp;&emsp;Build DLL Run command: ./CMakeScript.bat debug dll<br>
&emsp;&emsp;Build LIB Run command: ./CMakeScript.bat debug lib<br>

&emsp;other args: debug ,release ..., exe, dll, lib, cls, rb, x32, x64, 32, 64...<br>
&emsp;Args view CMakeSript.bat file.
