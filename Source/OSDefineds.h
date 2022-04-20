#pragma once

#ifndef SOURCE_OSDEFINEDS_H_
#define SOURCE_OSDEFINEDS_H_

//---------------------------------------------------------------//
//                     Register build symbol                     //

// Register to header file symbol Force wide characters ?
// TODO: wchar   WinAPIA/W();
//        Use UTF-8 ?

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

// Window default using ?
// TODO: default nothing.
//

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL 0
#endif

// MinGW / MSVC -> Build Export dynamic link library will need ?
// TODO: export DLL
//        [MinGW] Linker: -Xlinker --kill-at
//        [MinGW] Need use extren 'C'
//

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

#ifndef DLL_IMPORT
#define DLL_IMPORT __declspec(dllimport)
#endif

#ifndef DLL_EXPORT_C
#define DLL_EXPORT_C extern "C" __declspec(dllexport)
#endif

#ifndef DLL_IMPORT_C
#define DLL_IMPORT_C extern "C" __declspec(dllimport)
#endif

#ifndef DLLHK_EXPORT
#define DLLHK_EXPORT __declspec(dllexport) __declspec(naked) void __cdecl
#endif

#ifndef DLLHK_IMPORT
#define DLLHK_IMPORT __declspec(dllimport) __declspec(naked) void __cdecl
#endif

#ifndef DLLHK_EXPORT_C
#define DLLHK_EXPORT_C extern "C" __declspec(dllexport) __declspec(naked) void __cdecl
#endif

#ifndef DLLHK_IMPORT_C
#define DLLHK_IMPORT_C extern "C" __declspec(dllimport) __declspec(naked) void __cdecl
#endif

// Type convert
// TODO: (type)valve like this convert mode is old
//       [ static_cast ] The basic simple class convert - int，double，char | char* to int* can't not convert
//       [ const_cast ] The const object is converted to a non-const object
//       [ reinterpret_cast ]  Memory byte-level conversion, literally, recombines the memory content and reinterprets the contents of the address with pointers over different spans
//       [ dynamic_cast ] Used to transform down. For example, a parent class pointer (reference) is converted into a child class pointer (reference)

#ifndef CONVERT_BASE
#define CONVERT_BASE(_TYPE, VALUE) (static_cast<_TYPE>(VALUE))
#endif

#ifndef CONVERT_NONCONST
#define CONVERT_NONCONST(_TYPE, VALUE) (const_cast<_TYPE>(VALUE))
#endif

#ifndef CONVERT_FORCED
#define CONVERT_FORCED(_TYPE, VALUE) (reinterpret_cast<_TYPE>(VALUE))
#endif

#ifndef CONVERT_POINTER
#define CONVERT_POINTER(_TYPE, VALUE) (dynamic_cast<_TYPE>(VALUE))
#endif

#endif // SOURCE_OSDEFINEDS_H_