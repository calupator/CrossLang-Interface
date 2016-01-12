#include "..\InterfaceNativeC\InterfaceNativeC.h"
#include "..\InterfaceNativeCpp\InterfaceNativeCpp.h"
#include <iostream>
#include <conio.h>
#include <locale.h> 
 
using namespace std;
using namespace InterfaceNativeCpp;
void EventHandler(string str);
void NativeCpp();
void NativeC();

void main() 
{

	setlocale(0, "rus"); 

	cout << "*****************************" << endl;
	if (sizeof(INT_PTR) == 4)
	{
		cout << "* 32-х битное приложение!!! *" << endl;
	}
	else if (sizeof(INT_PTR) == 8)
	{
		cout << "* 64-х битное приложение!!! *" << endl;
	}
	cout << "*****************************" << endl;

	NativeCpp();
	NativeC();

	getch();

}

void NativeCpp()
{
	cout << "        Native Visual C++        " << endl;
	IInterfaceNativeCpp *NativeCpptest = new TestInterfaceNativeCpp();
	NativeCpptest->EventNativeCpp1 = new EventNativeCpp1EventHandler(&::EventHandler);
	NativeCpptest->setPropNativeCpp1(111);
	cout << "Свойство PropNativeCpp1 установлено в: " << NativeCpptest->getPropNativeCpp1() << endl;
	NativeCpptest->MethodNativeCpp1(5);
	cout << "======================================" << endl;

}

void NativeC()
{
	cout << "         Native C        " << endl;
	callback(*EventHandler);
    setPropNativeC1(111);
    cout << "Свойство PropNativeC1 установлено в: " << getPropNativeC1() << endl;
    MethodNativeC1(5);
    cout << "======================================" << endl;
}

void EventHandler(string str)
{
	cout << "Обработчик события поймал событие: \r\n" << str.c_str() << endl;
}
