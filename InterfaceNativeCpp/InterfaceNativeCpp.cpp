#include "InterfaceNativeCpp.h"
// без этой переменной не создается lib-файл
_API int nMy1212=0;

namespace InterfaceNativeCpp
{
	void TestInterfaceNativeCpp::MethodNativeCpp1(int X)
	{
		std::cout << "Метод MethodNativeCpp1 получил параметр: " << X << std::endl;
		std::stringstream ss;
		ss<<X;
		(*EventNativeCpp1)(/*this,*/ "\tАргумент метода MethodNativeCpp1: " + ss.str());
	}

	int TestInterfaceNativeCpp::getPropNativeCpp1()
	{
		return pval;
	}
	
	void TestInterfaceNativeCpp::setPropNativeCpp1(int value)
	{
		pval = value;
	}
	
	TestInterfaceNativeCpp::TestInterfaceNativeCpp()
	{
	}
	
	TestInterfaceNativeCpp::~TestInterfaceNativeCpp()
	{
	}

	/*TestInterfaceNativeCpp::TestInterfaceNativeCpp(CFeedback* pFeedback)
	{ 
		m_pFeedback = pFeedback;
		pval = 0;
	}*/
}