#ifndef _DLLTEST_H_
#define _DLLTEST_H_ 

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <windows.h> 
#define _API extern "C" __declspec(dllexport)

typedef void ( *cfunc)(std::string x);

_API int MethodNativeC1(PCWSTR X);
_API int getPropNativeC1();
_API void setPropNativeC1(int X);
_API void callback(cfunc call);

_API int MethodNativeC1(PCWSTR pszString);

#pragma region Callback Function

// Type-definition: 'PFN_COMPARE' now can be used as type
typedef PCWSTR (CALLBACK *PFN_COMPARE)(int, int);

// An exported/imported stdcall function using a DEF file
// It requires a callback function as one of the arguments
// Sym: Max
// See: CppDynamicLinkLibrary.cpp
_API PCWSTR __stdcall Max(int a, int b, PFN_COMPARE cmpFunc);

#pragma endregion
#endif

