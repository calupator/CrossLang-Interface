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
			Console::WriteLine("Метод MethodCpp1 получил нулевой параметр.");
			EventCpp1();
		}
		else if (X !=0 )
		{
			Console::WriteLine("Метод MethodCpp1 получил параметр: " + X);
			EventCpp2(this, "\tАргумент метода MethodCpp1: " + X.ToString());
		}
	}
}
