#pragma once

#ifndef SOURCE_USDEFINEDS_H_
#define SOURCE_USDEFINEDS_H_

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

#endif // SOURCE_USDEFINEDS_H_
