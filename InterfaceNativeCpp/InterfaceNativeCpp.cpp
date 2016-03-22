
#include "InterfaceNativeCpp.h"
// без этой переменной не создается lib-файл
_API int nMy1212=0;

namespace InterfaceNativeCpp
{
	TestInterfaceNativeCpp::TestInterfaceNativeCpp(void) : m_val(0.0f)
	{
	}

	TestInterfaceNativeCpp::~TestInterfaceNativeCpp(void)
	{
	}

	float TestInterfaceNativeCpp::getPropNativeCpp1(void)
	{
		return m_val;
	}

	void TestInterfaceNativeCpp::setPropNativeCpp1(float newVal)
	{
		m_val = newVal;
	}

	void TestInterfaceNativeCpp::MethodNativeCpp1(int pszString)
	{
		std::cout << "Метод MethodNativeCpp1 получил параметр: " << pszString << std::endl;
		std::stringstream ss;
		ss << pszString;
		(*EventNativeCpp1)(/*this,*/ "\tАргумент метода MethodNativeCpp1: " + ss.str());
	}

	/*TestInterfaceNativeCpp::TestInterfaceNativeCpp(CFeedback* pFeedback)
	{ 
		m_pFeedback = pFeedback;
		pval = 0;
	}*/
}