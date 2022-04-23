#include "OSLibrarys.h"
#include "USLibrarys.h"

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Initialize the library.
    g_hInst = hInstance;
    g_hInstPrev = hPrevInstance;

    INITCOMMONCONTROLSEX InitCtrls = {0};
    InitCtrls.dwSize = sizeof(INITCOMMONCONTROLSEX);
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);
    // InitCommonControls();

    int iResult = DialogBoxW(hInstance, MAKEINTRESOURCEW(DLG_MAIN), NULL, (DLGPROC)DLG_WinMain_Proc);
    return 0;
}