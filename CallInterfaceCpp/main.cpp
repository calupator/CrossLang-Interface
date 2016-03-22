
using namespace System;
using namespace InterfaceVB;
using namespace InterfaceCS;
using namespace InterfaceCpp;
using namespace InterfaceCpp;
using namespace Wrapper;

void VB();
void CS();
void Cpp();
void Wrap();
void NewCpp();
int func(int a, int b);

void EventHandler(Object ^sender, String ^str)
{
	Console::WriteLine("Обработчик события поймал событие: \r\n" + str);
	Console::WriteLine();
}
void EventHandler(String ^str)
{
	Console::WriteLine("Обработчик события поймал событие: \r\n" + str);
	Console::WriteLine();
}
void EventHandler()
{
	Console::WriteLine("Обработчик события поймал событие без параметров");
	Console::WriteLine();
}

int main(array<System::String ^> ^args)
{
	Console::WriteLine("*****************************");
	if (IntPtr::Size == 4)
	{
		Console::WriteLine("* 32-х битное приложение!!! *");
	}
	else if (IntPtr::Size == 8)
	{
		Console::WriteLine("* 64-х битное приложение!!! *");
	}
	Console::WriteLine("*****************************");


	NewCpp();
	VB();
	CS();
	Cpp();
	Wrap();

	Console::ReadKey();
}

void NewCpp()
{
	Console::WriteLine("         Работа с Native class         ");
	ManagedObjectWrapper^ sow = gcnew ManagedObjectWrapper;
	NativeMethods^ Wrapper = gcnew NativeMethods;
	CompareCallback^ call = gcnew CompareCallback(&func);
	int a = sow->GetStringLength("Первая строка");
	int b = sow->GetStringLength("Вторая длинная строка");
	Console::WriteLine(Wrapper->Max(a, b, call));
	sow->FloatProperty = 20.568f;
	float ret = sow->FloatProperty;
	Console::WriteLine(sow->ToString());

	Console::WriteLine("           Managed wrapper for native C DLL         ");
	CompareCallback^ call2 = gcnew CompareCallback(Wrapper, &NativeMethods::func);
	a = Wrapper->GetStringLength1("Первая строка");
	b = Wrapper->GetStringLength2("Вторая длинная строка");
	Console::WriteLine("Делегат статической функции");
	Console::WriteLine(Wrapper->Max(a, b, call));
	a = Wrapper->GetStringLength1("Первая строка еще длиннее");
	Console::WriteLine("Делегат функции-члена");
	Console::WriteLine(Wrapper->Max(a, b, call2));
}

void VB()
{
	Console::WriteLine("         Visual Basic        ");
	Console::WriteLine();
	IInterfaceVB ^VBtest = gcnew TestInterfaceVB();
	VBtest->EventVB1 += gcnew TestInterfaceVB::EventVB1EventHandler(&::EventHandler);
	VBtest->PropVB1 = 11;
	Console::WriteLine("Свойство PropVB1 установлено в: " + VBtest->PropVB1);
	VBtest->MethodVB1(5);
	Console::WriteLine("=====================================================");
}

void CS()
{
	Console::WriteLine("         Visual C#        ");
	Console::WriteLine();
	IInterfaceCS ^CStest = gcnew TestInterfaceCS();
	CStest->EventCS1 += gcnew EventCS1EventHandler(&::EventHandler);
	CStest->PropCS1 = 11;
	Console::WriteLine("Свойство PropCS1 установлено в: " + CStest->PropCS1);
	CStest->MethodCS1(5);
	Console::WriteLine("=====================================================");
}

void Cpp()
{
	Console::WriteLine("         Visual C++        ");
	Console::WriteLine();
	IInterfaceCpp ^Cpptest = gcnew TestInterfaceCpp();
	Cpptest->EventCpp1 += gcnew EventCpp1EventHandler(&::EventHandler);
	Cpptest->EventCpp2 += gcnew EventCpp2EventHandler(&::EventHandler);
	Cpptest->PropCpp1 = 11;
	Console::WriteLine("Свойство PropCpp1 установлено в: " + Cpptest->PropCpp1);
	Cpptest->MethodCpp1(5);
	Cpptest->MethodCpp1(0);
	Console::WriteLine("=====================================================");
}
void Wrap()
{
	Console::WriteLine("           Managed wrapper for native DLL         ");
	Console::WriteLine();
	Managed ^Mixedtest = gcnew Managed();
	Mixedtest->ValueChanged += gcnew ValueChangedHandler(&::EventHandler);
	Mixedtest->PropMixedCpp1 = 111;
	Console::WriteLine("Свойство PropManagedCpp1 установлено в: " + Mixedtest->PropMixedCpp1);
	Mixedtest->MethodMixedCpp1(5);
	Console::WriteLine("=====================================================");
}

int func(int a, int b)
{
	if ((a - b) >= 0)
		return 1;
	return 0;
}
