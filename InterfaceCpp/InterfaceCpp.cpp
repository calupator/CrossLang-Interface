#include "InterfaceCpp.h"
namespace InterfaceCpp
{
	TestInterfaceCpp::TestInterfaceCpp()
	{
	}

	TestInterfaceCpp::~TestInterfaceCpp()
	{
	}

	void TestInterfaceCpp::MethodCpp1(int X)
	{
		if (X == 0)
		{
			Console::WriteLine("����� MethodCpp1 ������� ������� ��������.");
			EventCpp1();
		}
		else if (X !=0 )
		{
			Console::WriteLine("����� MethodCpp1 ������� ��������: " + X);
			EventCpp2(this, "\t�������� ������ MethodCpp1: " + X.ToString());
		}
	}
}
