#include "EVariable.h"

#include <windows.h>
#include <shlobj.h>

#include <cwchar>
#include <string>
#include <vector>

bool Init_Main_SetControlStats(HWND hWndDlg);
bool Init_Main_GetWinOSVersion(HWND hWndDlg);

bool Load_Main_GetWinOSDefault(HWND hWndDlg);
bool Load_Main_GetDirConfigure(HWND hWndDlg);
bool Find_Main_GetDocumentPath(HWND hWndDlg);
bool Exec_Main_SetDocumentPath(HWND hWndDlg);

std::vector<DWORD> vcDwEditId  = {ID_MAIN_EDESKTOP, ID_MAIN_EDOWNLOADS, ID_MAIN_EDOCUMENTS, ID_MAIN_EPITCTURES, ID_MAIN_EVIDEOS, ID_MAIN_EMUSIC, ID_MAIN_EOBJECTS3D, ID_MAIN_EHISTORY, ID_MAIN_ERECENT, ID_MAIN_EFAVORITES, ID_MAIN_ELINKS, ID_MAIN_EINETCACHE, ID_MAIN_EINETCOOKIES, ID_MAIN_ESAVEGAMES, ID_MAIN_ESEARCHES, ID_MAIN_ECONTANCTS, ID_MAIN_EROAMING};
std::vector<DWORD> vcDwLabelId = {ID_MAIN_SDESKTOP, ID_MAIN_SDOWNLOADS, ID_MAIN_SDOCUMENTS, ID_MAIN_SPITCTURES, ID_MAIN_SVIDEOS, ID_MAIN_SMUSIC, ID_MAIN_SOBJECTS3D, ID_MAIN_SHISTORY, ID_MAIN_SRECENT, ID_MAIN_SFAVORITES, ID_MAIN_SLINKS, ID_MAIN_SINETCACHE, ID_MAIN_SINETCOOKIES, ID_MAIN_SSAVEGAMES, ID_MAIN_SSEARCHES, ID_MAIN_SCONTANCTS, ID_MAIN_SROAMING};
std::vector<DWORD> vcDwCheckId = {ID_MAIN_CDESKTOP, ID_MAIN_CDOWNLOADS, ID_MAIN_CDOCUMENTS, ID_MAIN_CPITCTURES, ID_MAIN_CVIDEOS, ID_MAIN_CMUSIC, ID_MAIN_COBJECTS3D, ID_MAIN_CHISTORY, ID_MAIN_CRECENT, ID_MAIN_CFAVORITES, ID_MAIN_CLINKS, ID_MAIN_CINETCACHE, ID_MAIN_CINETCOOKIES, ID_MAIN_CSAVEGAMES, ID_MAIN_CSEARCHES, ID_MAIN_CCONTANCTS, ID_MAIN_CROAMING};

std::vector<std::wstring> vcSubsKeys = {L"Desktop", L"Downloads", L"Documents", L"Pictures", L"Videos", L"Music", L"3D Objects", L"History", L"Recent Items", L"Favorites", L"Links", L"Cache", L"Cookies", L"Saved Games", L"Searches", L"Contacts", L"AppData\\Roaming"};
std::vector<GUID> vcGuidKeys         = {FOLDERID_Desktop, FOLDERID_Downloads, FOLDERID_Documents, FOLDERID_Pictures, FOLDERID_Videos, FOLDERID_Music, FOLDERID_Objects3D, FOLDERID_History, FOLDERID_Recent, FOLDERID_Favorites, FOLDERID_Links, FOLDERID_InternetCache, FOLDERID_Cookies, FOLDERID_SavedGames, FOLDERID_SavedSearches, FOLDERID_Contacts, FOLDERID_RoamingAppData};

int __stdcall DLG_WinMain_Proc(HWND hWndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        Init_Main_SetControlStats(hWndDlg);
        Init_Main_GetWinOSVersion(hWndDlg);
        break;
    case WM_CLOSE:
        EndDialog(hWndDlg, 0);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_MAIN_CWINDEFAULT:
            Load_Main_GetWinOSDefault(hWndDlg);
            break;
        case ID_MAIN_CLOADCONFIG:
            Load_Main_GetDirConfigure(hWndDlg);
            break;
        case ID_MAIN_BBROWSE:
            Find_Main_GetDocumentPath(hWndDlg);
            break;
        case ID_MAIN_BEXECUTE:
            Exec_Main_SetDocumentPath(hWndDlg);
            break;
        case ID_MAIN_BINFO:
            DialogBoxW(g_hInstance, MAKEINTRESOURCEW(DLG_INFO), hWndDlg, (DLGPROC)DLG_WinInfo_Proc);
            break;
        case ID_MAIN_BCANCEL:
            EndDialog(hWndDlg, 0);
            break;
        }
        break;
    }

    return FALSE;
}

bool Init_Main_SetControlStats(HWND hWndDlg)
{
    for (std::size_t iCount = 0; iCount < vcGuidKeys.size(); iCount++)
    {
        PWCHAR szWBuffer = 0;
        SHGetKnownFolderPath(vcGuidKeys[iCount], 0, NULL, &szWBuffer);
        SetDlgItemTextW(hWndDlg, vcDwEditId[iCount], szWBuffer);
        SetDlgItemTextW(hWndDlg, vcDwLabelId[iCount], L"11451419 GB");
        CheckDlgButton(hWndDlg, vcDwCheckId[iCount], BST_CHECKED);
    }

    // Sigle Option
    CheckDlgButton(hWndDlg, ID_MAIN_CSIGNOUT, BST_CHECKED);
    CheckDlgButton(hWndDlg, ID_MAIN_CCLEAR, BST_CHECKED);

    CheckDlgButton(hWndDlg, ID_MAIN_CWINDEFAULT, BST_UNCHECKED);
    CheckDlgButton(hWndDlg, ID_MAIN_CLOADCONFIG, BST_UNCHECKED);

    CheckDlgButton(hWndDlg, ID_MAIN_RMOVE, BST_CHECKED);
    CheckDlgButton(hWndDlg, ID_MAIN_RCOPY, BST_UNCHECKED);
    CheckDlgButton(hWndDlg, ID_MAIN_RNOACTION, BST_UNCHECKED);

    // RegGetValue Temp && Tmp Environment
    WCHAR szTempPath[MAX_PATH] = {0};
    DWORD dwTempPath = MAX_PATH;
    if(RegGetValueW(HKEY_CURRENT_USER, L"Environment", L"TEMP", RRF_RT_REG_SZ, NULL, szTempPath, &dwTempPath) != ERROR_SUCCESS)
        RegGetValueW(HKEY_CURRENT_USER, L"Environment", L"TMP", RRF_RT_REG_SZ, NULL, szTempPath, &dwTempPath);
    
    SetDlgItemTextW(hWndDlg, ID_MAIN_ETEMP, szTempPath);
    SetDlgItemTextW(hWndDlg, ID_MAIN_STEMP, L"11451419 GB");
    CheckDlgButton(hWndDlg, ID_MAIN_CTEMP, BST_CHECKED);

    // Get Disk Folder
    WCHAR szWBuffer[MAX_PATH] = {0};
    // DWORD dwLength = GetLogicalDriveStringsW(sizeof(szWBuffer) / sizeof(WCHAR), szWBuffer);

    DWORD dwLocked = 0;
    for (PWCHAR szDrive = szWBuffer; *szDrive; szDrive += wcslen(szDrive) + 1)
    {
        // wprintf_s(L"Name:%s Type:%d\n", szDrive, GetDriveTypeW(szDrive));
        if (GetDriveTypeW(szDrive) != DRIVE_FIXED)
            continue;

        WCHAR szWResult[MAX_PATH] = {0};
        swprintf_s(szWResult, L"%sPersonal", szDrive);

        // wprintf_s(L"%s", szDrive);   // Print the drive letter
        // wprintf_s(L"%s\n", szWResult);   // Print the drive letter

        // GetFirst DiskString
        SetDlgItemTextW(hWndDlg, ID_MAIN_ETARGETFOLDER, szWResult);
        if (dwLocked >= 1)
        {
            // GetSecond DiskString
            SetDlgItemTextW(hWndDlg, ID_MAIN_ETARGETFOLDER, szWResult);
            break;
        }
        dwLocked++;
    }

    return true;
}

bool Init_Main_GetWinOSVersion(HWND hWndDlg)
{
    WCHAR szPlatform[MAX_PATH];
    ZeroMemory(szPlatform, sizeof(szPlatform));

    OSVERSIONINFOW hOSVersionInfo = {0};
    hOSVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOW);

    WINBOOL bIsWow64 = 0;
    GetVersionExW(&hOSVersionInfo);
    if (IsWow64Process(GetCurrentProcess(), &bIsWow64) && bIsWow64)
        swprintf_s(szPlatform, L"%d.%d.%d.%d (x64)", hOSVersionInfo.dwMajorVersion, hOSVersionInfo.dwMinorVersion, hOSVersionInfo.dwBuildNumber, hOSVersionInfo.dwPlatformId);
    else
        swprintf_s(szPlatform, L"%d.%d.%d.%d", hOSVersionInfo.dwMajorVersion, hOSVersionInfo.dwMinorVersion, hOSVersionInfo.dwBuildNumber, hOSVersionInfo.dwPlatformId);

    SetDlgItemTextW(hWndDlg, ID_MAIN_SPLATFORM, szPlatform);
    return true;
}

bool Load_Main_GetWinOSDefault(HWND hWndDlg)
{
    if (IsDlgButtonChecked(hWndDlg, ID_MAIN_CWINDEFAULT) == BST_CHECKED)
    {
        if(IsDlgButtonChecked(hWndDlg, ID_MAIN_CLOADCONFIG) == BST_CHECKED)
            CheckDlgButton(hWndDlg, ID_MAIN_CLOADCONFIG, BST_UNCHECKED);

        for (std::size_t iCount = 0; iCount < vcDwEditId.size(); iCount++)
        {
            EnableWindow(GetDlgItem(hWndDlg, vcDwEditId[iCount]), false);
            EnableWindow(GetDlgItem(hWndDlg, vcDwCheckId[iCount]), false);
        }

        // Temp Control
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_ETEMP), false);
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_CTEMP), false);
    }
    else
    {
        for (std::size_t iCount = 0; iCount < vcDwEditId.size(); iCount++)
        {
            EnableWindow(GetDlgItem(hWndDlg, vcDwEditId[iCount]), true);
            EnableWindow(GetDlgItem(hWndDlg, vcDwCheckId[iCount]), true);
        }

        // Temp Control
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_ETEMP), true);
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_CTEMP), true);
    }

    return true;
}

bool Load_Main_GetDirConfigure(HWND hWndDlg)
{
    if (IsDlgButtonChecked(hWndDlg, ID_MAIN_CLOADCONFIG) == BST_CHECKED)
    {
        if(IsDlgButtonChecked(hWndDlg, ID_MAIN_CWINDEFAULT) == BST_CHECKED)
            CheckDlgButton(hWndDlg, ID_MAIN_CWINDEFAULT, BST_UNCHECKED);
            
        for (std::size_t iCount = 0; iCount < vcDwEditId.size(); iCount++)
        {
            EnableWindow(GetDlgItem(hWndDlg, vcDwEditId[iCount]), false);
            EnableWindow(GetDlgItem(hWndDlg, vcDwCheckId[iCount]), false);
        }

        // Temp Control
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_ETEMP), false);
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_CTEMP), false);
    }
    else
    {
        for (std::size_t iCount = 0; iCount < vcDwEditId.size(); iCount++)
        {
            EnableWindow(GetDlgItem(hWndDlg, vcDwEditId[iCount]), true);
            EnableWindow(GetDlgItem(hWndDlg, vcDwCheckId[iCount]), true);
        }

        // Temp Control
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_ETEMP), true);
        EnableWindow(GetDlgItem(hWndDlg, ID_MAIN_CTEMP), true);
    }

    return true;
}

int __stdcall DLG_Browser_Proc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
    switch (uMsg)
    {
    case BFFM_INITIALIZED:
        return TRUE;
    }
    return FALSE;
}

bool Find_Main_GetDocumentPath(HWND hWndDlg)
{
    BROWSEINFOW hBrowseInfo = {0};
    LPITEMIDLIST hItemIDList = 0;
    hBrowseInfo.lpszTitle = L"Browse for folder...";
    hBrowseInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
    hBrowseInfo.lpfn = DLG_Browser_Proc;
    hBrowseInfo.hwndOwner = hWndDlg;

    hItemIDList = SHBrowseForFolderW(&hBrowseInfo);
    if (hItemIDList != 0)
    {
        WCHAR szWBuffer[MAX_PATH] = {0};
        SHGetPathFromIDListW(hItemIDList, szWBuffer);
        SetDlgItemTextW(hWndDlg, ID_MAIN_ETARGETFOLDER, szWBuffer);
        return true;
    }
    return true;
}

long Path_Main_SetNewPathCheck(REFKNOWNFOLDERID pUidFolderId, PCWSTR pszTargetPath)
{
    long lErrCode = 0;
    DWORD lRetCode = GetFileAttributesW(pszTargetPath);
    if (lRetCode == INVALID_FILE_ATTRIBUTES)
    {
        lRetCode = SHCreateDirectory(0, pszTargetPath);
        if (lRetCode != ERROR_SUCCESS)
        {
            lErrCode = GetLastError();
            wprintf_s(L"[x] SHCreateDirectory Error code: %d\n", lErrCode);
            return lErrCode;
        }
    }

    lRetCode = SHSetKnownFolderPath(pUidFolderId, 0, NULL, pszTargetPath);
    if (lRetCode != S_OK)
    {
        lErrCode = GetLastError();
        wprintf_s(L"[x] SHSetKnownFolderPath Error code: %d\n", lErrCode);
        return lErrCode;
    }

    return 0;
}

bool Exec_Main_SetDocumentPath(HWND hWndDlg)
{
    WCHAR szWRootPath[MAX_PATH] = {0};
    GetDlgItemTextW(hWndDlg, ID_MAIN_ETARGETFOLDER, szWRootPath, sizeof(szWRootPath));

    for (std::size_t iCount = 0; iCount < vcGuidKeys.size(); iCount++)
    {
        WCHAR szWBuffer[MAX_PATH] = {0};
        wcscat_s(szWBuffer, szWRootPath);
        if (vcSubsKeys[iCount][0] != '\\')
            wcscat_s(szWBuffer, L"\\") && wcscat_s(szWBuffer, vcSubsKeys[iCount].c_str());
        else
            wcscat_s(szWBuffer, vcSubsKeys[iCount].c_str());

        PWCHAR szWNewPath = (PWCHAR)szWBuffer;
        PWCHAR szWOldPath = 0;
        SHGetKnownFolderPath(vcGuidKeys[iCount], KF_FLAG_CREATE, 0, &szWOldPath);
        // wprintf_s(L"[*] %s: %s -> %s\n", vcSubsKeys[iCount].c_str(), szWOldPath, szWNewPath);
        Path_Main_SetNewPathCheck(vcGuidKeys[iCount], szWNewPath);
    }

    // RegSetValue Temp && Tmp Environment
    HKEY hKeyData = 0;
    WCHAR szWTempPath[MAX_PATH] = {0};
    long lRetCode = RegOpenKeyExW(HKEY_CURRENT_USER, L"Environment", 0, KEY_ALL_ACCESS, &hKeyData);
    if(lRetCode != ERROR_SUCCESS)
    {
        wprintf_s(L"[x] RegOpenKeyExW Error code: %d\n", lRetCode);
        return false;
    }
    else
    {
        swprintf_s(szWTempPath, L"%s\\Temp", szWRootPath);
        if(GetFileAttributesW(szWTempPath) == INVALID_FILE_ATTRIBUTES)
        {
            lRetCode = SHCreateDirectory(0, szWTempPath);
            if (lRetCode != ERROR_SUCCESS)
            {
                lRetCode = GetLastError();
                wprintf_s(L"[x] SHCreateDirectory Error for Temp folder code: %d\n", lRetCode);
                return false;
            }
        }

        RegSetValueExW(hKeyData, L"TEMP", 0, REG_EXPAND_SZ, (PBYTE)szWTempPath, sizeof(szWTempPath));
        RegSetValueExW(hKeyData, L"TMP", 0, REG_EXPAND_SZ, (PBYTE)szWTempPath, sizeof(szWTempPath));
    }
    

    if (IsDlgButtonChecked(hWndDlg, ID_MAIN_RMOVE) == BST_CHECKED)
    {
        wprintf_s(L"[*] Move mode is checked\n");
    }
    else if (IsDlgButtonChecked(hWndDlg, ID_MAIN_RCOPY) == BST_CHECKED)
    {
        wprintf_s(L"[*] Copy mode is checked\n");
    }
    else if (IsDlgButtonChecked(hWndDlg, ID_MAIN_RNOACTION) == BST_CHECKED)
    {
        wprintf_s(L"[*] NoAction mode is checked\n");
    }

    if (IsDlgButtonChecked(hWndDlg, ID_MAIN_CCLEAR) == BST_CHECKED)
        wprintf_s(L"[*] Clear cache...\n");

    if (IsDlgButtonChecked(hWndDlg, ID_MAIN_CSIGNOUT) == BST_CHECKED)
        ExitWindowsEx(EWX_LOGOFF, 0);

    return true;
}
