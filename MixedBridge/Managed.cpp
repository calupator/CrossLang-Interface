#include "stdafx.h"
#include "Managed.h"
#include "Feedback.h"

namespace Wrapper
{
	Managed::Managed()
	{
		setlocale(0, "rus");
		m_pFeedback = new Feedback(this);
		m_pUnmanaged = new CUnmanaged(m_pFeedback);
	}

	Managed::~Managed()
	{
		delete m_pUnmanaged;
		delete m_pFeedback;
	}

	void Managed::MethodMixedCpp1(int nValue)
	{
		std::cout << "Метод MethodMixedCpp1 вызывает нативный метод MethodNativeCpp1 с аргументом: " << nValue << std::endl;
		m_pUnmanaged->MethodNativeCpp1(nValue);
	}



}