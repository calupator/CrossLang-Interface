#include "InterfaceNativeC.h"
#define MAXMODULE 250

using namespace std;

cfunc EventNativeC1;
int pval;

_API void MethodNativeC1(int X)
{
	std::cout << "����� MethodNativeC1 ������� ��������: " << X << endl;
	stringstream ss;
	ss<<X;
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
