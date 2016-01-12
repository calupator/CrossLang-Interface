#include "InterfaceNativeC.h"
#define MAXMODULE 250

using namespace std;

cfunc EventNativeC1;
int pval;

_API void MethodNativeC1(int X)
{
	std::cout << "Метод MethodNativeC1 получил параметр: " << X << endl;
	stringstream ss;
	ss<<X;
	EventNativeC1("\tАргумент метода MethodNativeC1: " + ss.str());

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
