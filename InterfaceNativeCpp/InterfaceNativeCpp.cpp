
#include "InterfaceNativeCpp.h"
// ��� ���� ���������� �� ��������� lib-����
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
		std::cout << "����� MethodNativeCpp1 ������� ��������: " << pszString << std::endl;
		std::stringstream ss;
		ss << pszString;
		(*EventNativeCpp1)(/*this,*/ "\t�������� ������ MethodNativeCpp1: " + ss.str());
	}

	/*TestInterfaceNativeCpp::TestInterfaceNativeCpp(CFeedback* pFeedback)
	{ 
		m_pFeedback = pFeedback;
		pval = 0;
	}*/
}