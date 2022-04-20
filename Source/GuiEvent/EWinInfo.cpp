#include "EVariable.h"

#include <windows.h>
#include <wchar.h>

int __stdcall DLG_WinInfo_Proc(HWND hWndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        WCHAR szPlatform[MAX_PATH];
        ZeroMemory(szPlatform, sizeof(szPlatform));
        swprintf_s(szPlatform, L"MCF %hs", __VERSION__);
        SetDlgItemTextW(hWndDlg, ID_INFO_SPLATFORM, szPlatform);
        break;
    case WM_CLOSE:
        EndDialog(hWndDlg, 0);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_INFO_BOK:
            EndDialog(hWndDlg, 0);
            break;
        }
        break;
    }
    return FALSE;
}