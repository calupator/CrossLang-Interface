
#pragma once

#include <windows.h>

// The following ifdef block is the standard way of creating macros which 
// make exporting from a DLL simpler. All files within this DLL are compiled 
// with the CPPDYNAMICLINKLIBRARY_EXPORTS symbol defined on the command line. 
// This symbol should not be defined on any project that uses this DLL. This 
// way any other project whose source files include this file see 
// SYMBOL_DECLSPEC and SYMBOL_DEF functions as being imported from a DLL, 
// whereas this DLL sees symbols defined with these macros as being exported.

//#ifdef CPPDYNAMICLINKLIBRARY_EXPORTS
#define SYMBOL_DECLSPEC __declspec(dllexport)
#define SYMBOL_DEF



#pragma region Global Data

// An exported/imported global data using a DEF file
// Sym: g_nVal1
// See: CppDynamicLinkLibrary.def
//      CppDynamicLinkLibrary.cpp
// Ref: http://support.microsoft.com/kb/90530


// An exported/imported global data using __declspec(dllexport/dllimport)
// Sym: g_nVal2
// See: CppDynamicLinkLibrary.cpp
// Ref: http://support.microsoft.com/kb/90530
EXTERN_C SYMBOL_DECLSPEC int g_nVal2;

#pragma endregion


#pragma region Ordinary Functions

// An exported/imported cdecl(default) function by using a DEF file
// The default calling convention of the exported function is cdecl
// Sym: GetStringLength1
// See: Project Properties / C/C++ / Advanced / Calling Convention
//      CppDynamicLinkLibrary.def
//      CppDynamicLinkLibrary.cpp
// Ref: http://msdn.microsoft.com/en-us/library/d91k01sh.aspx
SYMBOL_DECLSPEC int /*__cdecl*/ GetStringLength1(PCWSTR pszString);

// An exported/imported stdcall function __declspec(dllexport/dllimport)
// Sym: _GetStringLength2@4
// See: CppDynamicLinkLibrary.cpp
// Ref: http://msdn.microsoft.com/en-us/library/a90k134d.aspx
EXTERN_C SYMBOL_DECLSPEC int __stdcall GetStringLength2(PCWSTR pszString);

#pragma endregion


#pragma region Callback Function

// Type-definition: 'PFN_COMPARE' now can be used as type
typedef PCWSTR (CALLBACK *PFN_COMPARE)(int, int);

// An exported/imported stdcall function using a DEF file
// It requires a callback function as one of the arguments
// Sym: Max
// See: CppDynamicLinkLibrary.cpp
SYMBOL_DECLSPEC PCWSTR __stdcall Max(int a, int b, PFN_COMPARE cmpFunc);

#pragma endregion


#pragma region Class

// An exported/imported class using __declspec(dllexport/dllimport)
// It exports/imports all public members of the class
// See: CppDynamicLinkLibrary.cpp
// Ref: http://msdn.microsoft.com/en-us/library/a90k134d.aspx
class SYMBOL_DECLSPEC NativeObjectClass
{
public:

    NativeObjectClass(void);  // Constructor
    virtual ~NativeObjectClass(void);  // Destructor

    // Property
    float get_FloatProperty(void);
    void set_FloatProperty(float newVal);

    // Method
    HRESULT ToString(PWSTR pszBuffer, DWORD dwSize);

    // Static method
    static int GetStringLength(PCWSTR pszString);

private:
    float m_fField;
};

#pragma endregion