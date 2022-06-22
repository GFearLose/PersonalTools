#pragma once

#ifndef SOURCE_OSDEFINEDS_H_
#define SOURCE_OSDEFINEDS_H_

// Setting build encode flags options
// TODO: Build Win32 API using A/W

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#ifndef _UNICODE
#define _UNICODE
#endif /* _UNICODE */

// Setting defined convert fullname to simple name
// TODO: Redefine base grammar

#ifndef TO_CONST
#define TO_CONST(_TYPE, _VALUE) (const_cast<_TYPE>(_VALUE))
#endif /* TO_CONST */

#ifndef TO_REINT
#define TO_REINT(_TYPE, _VALUE) (reinterpret_cast<_TYPE>(_VALUE))
#endif /* TO_REINT */

#ifndef TO_STATIC
#define TO_STATIC(_TYPE, _VALUE) (static_cast<_TYPE>(_VALUE))
#endif /* TO_STATIC */

#ifndef TO_DYNAMIC
#define TO_DYNAMIC(_TYPE, _VALUE) (dynamic_cast<_TYPE>(_VALUE))
#endif /* TO_DYNAMIC */

// Setting Build export dynamic link library options
// TODO: Export dll will be used in other project
// [MinGW] C++ Linker: -Xlinker --kill-at
// [MinGW] C Linker: It dosen't need option

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif /* DLL_EXPORT */

#ifndef DLL_IMPORT
#define DLL_IMPORT __declspec(dllimport)
#endif /* DLL_IMPORT */

#ifndef DLL_EXPORT_C
#define DLL_EXPORT_C extern "C" __declspec(dllexport)
#endif /* DLL_EXPORT_C */

#ifndef DLL_IMPORT_C
#define DLL_IMPORT_C extern "C" __declspec(dllimport)
#endif /* DLL_IMPORT_C */

#ifndef DLL_EXPORT_HK
#define DLL_EXPORT_HK __declspec(dllexport) void __cdecl
#endif /* DLL_EXPORT_HK */

#ifndef DLL_IMPORT_HK
#define DLL_IMPORT_HK __declspec(dllimport) void __cdecl
#endif /* DLL_IMPORT_HK */

#ifndef DLL_EXPORT_HK_C
#define DLL_EXPORT_HK_C extern "C" __declspec(dllexport) void __cdecl
#endif /* DLL_EXPORT_HK_C */

#ifndef DLL_IMPORT_HK_C
#define DLL_IMPORT_HK_C extern "C" __declspec(dllimport) void __cdecl
#endif /* DLL_IMPORT_HK_C */

// Setting Build export dynamic link library options
// TODO: Keep my Assembly code

#ifndef DLL_EXPORT_ASM
#define DLL_EXPORT_ASM __declspec(dllexport) __declspec(naked)
#endif /* DLL_EXPORT */

#ifndef DLL_IMPORT_ASM
#define DLL_IMPORT_ASM __declspec(dllimport) __declspec(naked)
#endif /* DLL_IMPORT */

#ifndef DLL_EXPORT_ASM_C
#define DLL_EXPORT_ASM_C extern "C" __declspec(dllexport) __declspec(naked)
#endif /* DLL_EXPORT_C */

#ifndef DLL_IMPORT_ASM_C
#define DLL_IMPORT_ASM_C extern "C" __declspec(dllimport) __declspec(naked)
#endif /* DLL_IMPORT_C */

#ifndef DLL_EXPORT_ASM_HK
#define DLL_EXPORT_ASM_HK __declspec(dllexport) __declspec(naked) void __cdecl
#endif /* DLL_EXPORT_HK */

#ifndef DLL_IMPORT_ASM_HK
#define DLL_IMPORT_ASM_HK __declspec(dllimport) __declspec(naked) void __cdecl
#endif /* DLL_IMPORT_HK */

#ifndef DLL_EXPORT_ASM_HK_C
#define DLL_EXPORT_ASM_HK_C extern "C" __declspec(dllexport) __declspec(naked) void __cdecl
#endif /* DLL_EXPORT_HK_C */

#ifndef DLL_IMPORT_ASM_HK_C
#define DLL_IMPORT_ASM_HK_C extern "C" __declspec(dllimport) __declspec(naked) void __cdecl
#endif /* DLL_IMPORT_HK_C */

#endif // SOURCE_OSDEFINEDS_H_
