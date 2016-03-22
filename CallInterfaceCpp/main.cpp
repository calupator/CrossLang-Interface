
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
	Console::WriteLine("���������� ������� ������ �������: \r\n" + str);
	Console::WriteLine();
}
void EventHandler(String ^str)
{
	Console::WriteLine("���������� ������� ������ �������: \r\n" + str);
	Console::WriteLine();
}
void EventHandler()
{
	Console::WriteLine("���������� ������� ������ ������� ��� ����������");
	Console::WriteLine();
}

int main(array<System::String ^> ^args)
{
	Console::WriteLine("*****************************");
	if (IntPtr::Size == 4)
	{
		Console::WriteLine("* 32-� ������ ����������!!! *");
	}
	else if (IntPtr::Size == 8)
	{
		Console::WriteLine("* 64-� ������ ����������!!! *");
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
	Console::WriteLine("         ������ � Native class         ");
	ManagedObjectWrapper^ sow = gcnew ManagedObjectWrapper;
	NativeMethods^ Wrapper = gcnew NativeMethods;
	CompareCallback^ call = gcnew CompareCallback(&func);
	int a = sow->GetStringLength("������ ������");
	int b = sow->GetStringLength("������ ������� ������");
	Console::WriteLine(Wrapper->Max(a, b, call));
	sow->FloatProperty = 20.568f;
	float ret = sow->FloatProperty;
	Console::WriteLine(sow->ToString());

	Console::WriteLine("           Managed wrapper for native C DLL         ");
	CompareCallback^ call2 = gcnew CompareCallback(Wrapper, &NativeMethods::func);
	a = Wrapper->GetStringLength1("������ ������");
	b = Wrapper->GetStringLength2("������ ������� ������");
	Console::WriteLine("������� ����������� �������");
	Console::WriteLine(Wrapper->Max(a, b, call));
	a = Wrapper->GetStringLength1("������ ������ ��� �������");
	Console::WriteLine("������� �������-�����");
	Console::WriteLine(Wrapper->Max(a, b, call2));
}

void VB()
{
	Console::WriteLine("         Visual Basic        ");
	Console::WriteLine();
	IInterfaceVB ^VBtest = gcnew TestInterfaceVB();
	VBtest->EventVB1 += gcnew TestInterfaceVB::EventVB1EventHandler(&::EventHandler);
	VBtest->PropVB1 = 11;
	Console::WriteLine("�������� PropVB1 ����������� �: " + VBtest->PropVB1);
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
	Console::WriteLine("�������� PropCS1 ����������� �: " + CStest->PropCS1);
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
	Console::WriteLine("�������� PropCpp1 ����������� �: " + Cpptest->PropCpp1);
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
	Console::WriteLine("�������� PropManagedCpp1 ����������� �: " + Mixedtest->PropMixedCpp1);
	Mixedtest->MethodMixedCpp1(5);
	Console::WriteLine("=====================================================");
}

int func(int a, int b)
{
	if ((a - b) >= 0)
		return 1;
	return 0;
}
