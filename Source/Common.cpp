#include "OSLibrarys.h"
#include "USLibrarys.h"

void PATHGetInformation()
{
#ifndef _DEBUG
    wchar_t *szBuffer = {0};
    SHGetKnownFolderPath(FOLDERID_AppCaptures, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);      // D:\Personal\Videos\Captures
    SHGetKnownFolderPath(FOLDERID_AppDataDesktop, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);   // C:\Users\FearLose\AppData\Local\Desktop
    SHGetKnownFolderPath(FOLDERID_AppDataDocuments, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // C:\Users\FearLose\AppData\Local\Documents
    SHGetKnownFolderPath(FOLDERID_AppDataFavorites, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // C:\Users\FearLose\AppData\Local\Favorites

    SHGetKnownFolderPath(FOLDERID_Contacts, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);      // D:\Personal\Contacts
    SHGetKnownFolderPath(FOLDERID_Cookies, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);       // D:\Personal\Cookies
    SHGetKnownFolderPath(FOLDERID_Desktop, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);       // D:\Personal\Desktop
    SHGetKnownFolderPath(FOLDERID_Documents, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);     // D:\Personal\Documents
    SHGetKnownFolderPath(FOLDERID_Downloads, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);     // D:\Personal\Downloads
    SHGetKnownFolderPath(FOLDERID_Favorites, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);     // D:\Personal\Favorites
    SHGetKnownFolderPath(FOLDERID_History, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);       // D:\Personal\History
    SHGetKnownFolderPath(FOLDERID_InternetCache, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Cache
    SHGetKnownFolderPath(FOLDERID_Links, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);         // D:\Personal\Links

    SHGetKnownFolderPath(FOLDERID_LocalDocuments, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Documents
    SHGetKnownFolderPath(FOLDERID_LocalDownloads, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Downloads
    SHGetKnownFolderPath(FOLDERID_LocalMusic, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);     // C:\Users\FearLose\Music
    SHGetKnownFolderPath(FOLDERID_LocalPictures, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);  // C:\Users\FearLose\Pictures
    SHGetKnownFolderPath(FOLDERID_LocalVideos, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);    // C:\Users\FearLose\Videos

    SHGetKnownFolderPath(FOLDERID_Music, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);       // D:\Personal\Music
    SHGetKnownFolderPath(FOLDERID_Objects3D, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);   // C:\Users\FearLose\3D-Objects
    SHGetKnownFolderPath(FOLDERID_Pictures, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);    // D:\Personal\Pictures
    SHGetKnownFolderPath(FOLDERID_PhotoAlbums, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Pictures\Slide-Shows

    SHGetKnownFolderPath(FOLDERID_Recent, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Recent

    SHGetKnownFolderPath(FOLDERID_SavedGames, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);    // D:\Personal\Saved Games
    SHGetKnownFolderPath(FOLDERID_SavedPictures, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Pictures\Saved-Pictures
    SHGetKnownFolderPath(FOLDERID_SavedSearches, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Searches
    SHGetKnownFolderPath(FOLDERID_Screenshots, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer);   // D:\Personal\Pictures\Screenshots

    SHGetKnownFolderPath(FOLDERID_Videos, KF_FLAG_CREATE, 0, &szBuffer) & wprintf_s(L"%ls\n", szBuffer); // D:\Personal\Videos
#endif // _DEBUG
}

void ShowAllPathInfomathon()
{
#ifndef _DEBUG
    PWSTR wPath = 0;
    SHGetKnownFolderPath(FOLDERID_AccountPictures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AddNewPrograms, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AdminTools, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AllAppMods, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AppCaptures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AppDataDesktop, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AppDataDocuments, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AppDataFavorites, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AppDataProgramData, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AppsFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ApplicationShortcuts, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_AppUpdates, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CameraRoll, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CameraRollLibrary, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CDBurning, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ChangeRemovePrograms, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CommonAdminTools, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CommonOEMLinks, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CommonPrograms, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CommonStartMenu, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CommonStartMenuPlaces, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CommonStartup, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CommonTemplates, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ComputerFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ConflictFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ConnectionsFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Contacts, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ControlPanelFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Cookies, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_CurrentAppMods, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Desktop, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_DevelopmentFiles, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Device, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_DeviceMetadataStore, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Documents, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_DocumentsLibrary, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Downloads, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Favorites, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Fonts, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Games, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_GameTasks, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_History, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_HomeGroup, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_HomeGroupCurrentUser, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ImplicitAppShortcuts, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_InternetCache, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_InternetFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Libraries, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Links, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalAppData, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalAppDataLow, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalDocuments, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalDownloads, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalizedResourcesDir, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalMusic, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalPictures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_LocalVideos, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Music, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_MusicLibrary, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_NetHood, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_NetworkFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Objects3D, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_OneDrive, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_OriginalImages, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PhotoAlbums, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Pictures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PicturesLibrary, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Playlists, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PrintHood, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PrintersFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Profile, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ProgramData, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ProgramFiles, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ProgramFilesX64, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ProgramFilesX86, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ProgramFilesCommon, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ProgramFilesCommonX64, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ProgramFilesCommonX86, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Programs, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Public, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicDesktop, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicDocuments, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicDownloads, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicGameTasks, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicLibraries, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicMusic, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicPictures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicRingtones, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicUserTiles, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_PublicVideos, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_QuickLaunch, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Recent, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_RecordedCalls, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_RecordedTVLibrary, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_RecycleBinFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_ResourceDir, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_RetailDemo, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Ringtones, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_RoamingAppData, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_RoamingTiles, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_RoamedTileImages, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SampleMusic, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SamplePictures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SamplePlaylists, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SampleVideos, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SavedGames, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SavedPictures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SavedPicturesLibrary, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SavedSearches, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Screenshots, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SEARCH_MAPI, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SEARCH_CSC, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SearchHistory, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SearchHome, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SearchTemplates, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SendTo, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SidebarDefaultParts, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SidebarParts, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SkyDrive, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SkyDriveCameraRoll, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SkyDriveDocuments, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SkyDriveMusic, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SkyDrivePictures, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_StartMenu, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_StartMenuAllPrograms, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Startup, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SyncManagerFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SyncResultsFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SyncSetupFolder, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_System, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_SystemX86, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Templates, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_UserPinned, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_UserProfiles, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_UserProgramFiles, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_UserProgramFilesCommon, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_UsersFiles, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_UsersLibraries, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Videos, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_VideosLibrary, KF_FLAG_CREATE, 0, &wPath) & wprintf(L"%ls\n", wPath);
    SHGetKnownFolderPath(FOLDERID_Windows, KF_FLAG_CREATE, 0, &wPath);
#endif //_DEBUG
}

int PATHExecuteW(REFKNOWNFOLDERID pUidFolderId, PCWSTR pszTargetPath)
{
    long lErrCode = 0;
    long lRetCode = GetFileAttributesW(pszTargetPath);
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

    // Get origin szDirPath
    // Set new dirpath and move folder information
    lRetCode = SHSetKnownFolderPath(pUidFolderId, 0, NULL, pszTargetPath);
    if (lRetCode != S_OK)
    {
        lErrCode = GetLastError();
        wprintf_s(L"[x] SHSetKnownFolderPath Error code: %d\n", lErrCode);
        return lErrCode;
    }

    // using SHFileOperationA api
    // using ExitWindowsEx api
    // using system("P.S KILL Explorer") or TerminateProcess -> Kill Explorer ... api
    return 0;
}

void PATHSetInformation()
{
    const wchar_t *szRoot = L"C:\\Personal";
    const wchar_t *szSubKey[] = {L"Videos\\Captures", L"Local\\Desktop", L"Local\\Documents", L"Local\\Favorites", L"Contacts", L"Cookies", L"Desktop", L"Documents", L"Downloads", L"Favorites", L"History", L"Cache", L"Links", L"Documents", L"Downloads", L"Music", L"Pictures", L"Videos", L"Music", L"Videos", L"Recent", L"Pictures", L"3D Objects", L"Pictures\\Slide Shows", L"Saved Games", L"Pictures\\Saved Pictures", L"Searches", L"Pictures\\Screenshots"};
    const GUID hKFolderID[] = {FOLDERID_AppCaptures, FOLDERID_AppDataDesktop, FOLDERID_AppDataDocuments, FOLDERID_AppDataFavorites, FOLDERID_Contacts, FOLDERID_Cookies, FOLDERID_Desktop, FOLDERID_Documents, FOLDERID_Downloads, FOLDERID_Favorites, FOLDERID_History, FOLDERID_InternetCache, FOLDERID_Links, FOLDERID_LocalDocuments, FOLDERID_LocalDownloads, FOLDERID_LocalMusic, FOLDERID_LocalPictures, FOLDERID_LocalVideos, FOLDERID_Music, FOLDERID_Videos, FOLDERID_Recent, FOLDERID_Pictures, FOLDERID_Objects3D, FOLDERID_PhotoAlbums, FOLDERID_SavedGames, FOLDERID_SavedPictures, FOLDERID_SavedSearches, FOLDERID_Screenshots};

    // Kill Process
    // system("TASKKILL /IM EXPLORER.EXE /T /F");

    for (int iCount = 0; iCount < 28; iCount++)
    {
        wchar_t *szNewPath = 0;
        wchar_t *szOldPath = 0;
        wchar_t szBuffer[MAX_PATH] = {0};

        wcscat_s(szBuffer, szRoot);
        if (szSubKey[iCount][0] != '\\')
            wcscat_s(szBuffer, L"\\") & wcscat_s(szBuffer, szSubKey[iCount]);
        else
            wcscat_s(szBuffer, szSubKey[iCount]);

        // Give to wchar_t();
        szNewPath = (wchar_t *)szBuffer;

        SHGetKnownFolderPath(hKFolderID[iCount], KF_FLAG_CREATE, 0, &szOldPath);
        PATHExecuteW(hKFolderID[iCount], szNewPath);

        // Move Directory and Files
    }

    // Logoff
    // ExitWindowsEx(EWX_LOGOFF, 0);
}

int IsRunasAdmin()
{
#ifndef _DEBUG
    DWORD dwElevated = 0;
    HANDLE hToken = 0;

    // Get current process token
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
        return 0;

    TOKEN_ELEVATION tokenEle;
    DWORD dwRetLen = 0;

    // Retrieve token elevation information
    if (GetTokenInformation(hToken, TokenElevation, &tokenEle, sizeof(tokenEle), &dwRetLen))
    {
        if (dwRetLen == sizeof(tokenEle))
            dwElevated = tokenEle.TokenIsElevated;
    }

    CloseHandle(hToken);
    return dwElevated;
#endif _DEBUG
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    // if(IsRunasAdmin())
    // {
    //     wprintf_s(L"You have not administrator permission\n");
    //     return -1;
    // }

    int isMode = 2;
    switch (isMode)
    {
    case 0:
        PATHGetInformation();
        break;
    case 1:
        ShowAllPathInfomathon();
        break;
    case 2:
        PATHSetInformation();
        break;
    }

#ifndef _DEBUG
    system("pause");
#endif // _DEBUG

    return 0;
}
