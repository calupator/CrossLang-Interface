#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <windows.h>

#define _API __declspec(dllexport)
extern _API int nMy1212;

namespace InterfaceNativeCpp
{
	typedef void (*EventNativeCpp1EventHandler)(/*ITestInterfaceNativeCpp *sender,*/ std::string str);

	class _API IInterfaceNativeCpp
	{
	public:
		virtual float getPropNativeCpp1(void) = 0;
		virtual void setPropNativeCpp1(float) = 0;
		virtual void MethodNativeCpp1(int) = 0;
		EventNativeCpp1EventHandler *EventNativeCpp1;
	};
}
