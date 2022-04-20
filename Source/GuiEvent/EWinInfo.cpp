#include "EVariable.h"

#include <windows.h>
#include <wchar.h>

bool Init_Info_SetControlStats(HWND hWndDlg);
bool Ctrl_Info_CreateAtControl(HWND hWndDlg);

int __stdcall DLG_WinInfo_Proc(HWND hWndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        Init_Info_SetControlStats(hWndDlg);
        break;
    case WM_CREATE:
        Ctrl_Info_CreateAtControl(hWndDlg);
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

bool Init_Info_SetControlStats(HWND hWndDlg)
{
    WCHAR szPlatform[MAX_PATH];
    ZeroMemory(szPlatform, sizeof(szPlatform));
    swprintf_s(szPlatform, L"MCF %hs", __VERSION__);
    SetDlgItemTextW(hWndDlg, ID_INFO_SPLATFORM, szPlatform);
    return true;
}

bool Ctrl_Info_CreateAtControl(HWND hWndDlg)
{
    return true;
}