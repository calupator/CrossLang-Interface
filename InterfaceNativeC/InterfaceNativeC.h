#ifndef _DLLTEST_H_
#define _DLLTEST_H_ 

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <windows.h> 
#define _API extern "C" __declspec(dllexport)

typedef void ( *cfunc)(std::string x);

_API void MethodNativeC1(int X);
_API int getPropNativeC1();
_API void setPropNativeC1(int X);
_API void callback(cfunc call);
#endif