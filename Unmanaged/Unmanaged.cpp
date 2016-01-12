#include "stdafx.h"
#include "Unmanaged.h"
#include <string>
#include <iostream>
#include <sstream>


CUnmanaged::CUnmanaged(CFeedback* pFeedback)
{ 
	m_pFeedback = pFeedback;
	m_nValue = 0;
}

void CUnmanaged::MethodNativeCpp1(int nValue)
{
	std::cout << "Метод MethodNativeCpp1 получил параметр: " << nValue << std::endl;
	std::stringstream ss;
	ss<<nValue;
	m_pFeedback->OnValueChanged("\tАргумент метода MethodNativeCpp1: " + ss.str());
}

void CUnmanaged::setPropNativeCpp1(int nValue)
{
	m_nValue = nValue;
}

int CUnmanaged::getPropNativeCpp1()
{
	return m_nValue;
}
