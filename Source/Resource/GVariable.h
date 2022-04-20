#pragma once

#ifndef SOURCE_RESOURCE_GVARIABLE_H_
#define SOURCE_RESOURCE_GVARIABLE_H_

#ifndef STATIC
#define STATIC static
#endif // STATIC

#ifndef EXTERN
#define EXTERN extern
#endif // EXTERN

#include <windows.h>

STATIC HINSTANCE g_hInst;
STATIC HINSTANCE g_hInstPrev;

#endif  // SOURCE_RESOURCE_GVARIABLE_H_
