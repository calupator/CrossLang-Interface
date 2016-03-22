#include "InterfaceNativeC.h"
#define MAXMODULE 250

using namespace std;

cfunc EventNativeC1;
int pval;

_API void MethodNativeC1(int pszString)
{
	std::cout << "����� MethodNativeC1 ������� ��������: " << pszString << endl;
	stringstream ss;
	ss << pszString;
	EventNativeC1("\t�������� ������ MethodNativeC1: " + ss.str());
}

_API int getPropNativeC1()
{
	return pval;
}

_API void setPropNativeC1(int X)
{
	pval = X;
}

_API void callback(cfunc call)
{
       EventNativeC1 = call;
}

#pragma region Callback Function

// An exported/imported stdcall function using a DEF file
// It requires a callback function as one of the arguments
PCWSTR __stdcall Max(int a, int b, PFN_COMPARE cmpFunc)
{
	// Make the callback to the comparison function

	// If a is greater than b, return a; 
    // If b is greater than or equal to a, return b.
    return ((*cmpFunc)(a, b) > 0) ? L"������ ������ ������ ������." : L"������ ������ ������ ������.";
}

#pragma endregion