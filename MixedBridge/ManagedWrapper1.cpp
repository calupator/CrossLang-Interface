#include "stdafx.h"
#include "ManagedWrapper1.h"
#include "Feedback.h"

namespace Wrapper
{
	Managed::Managed()
	{
		setlocale(0, "rus");
		m_pFeedback = new Feedback(this);
		m_pUnmanaged = new CUnmanaged(m_pFeedback);
	}

	Managed::~Managed(void)
	{
		if (m_pUnmanaged || m_pFeedback)
		{
			delete m_pUnmanaged;
			delete m_pFeedback;
			m_pUnmanaged = NULL;
			m_pFeedback = NULL;
		}
	}

	Managed::!Managed(void)
	{
		if (m_pUnmanaged || m_pFeedback)
		{
			delete m_pUnmanaged;
			delete m_pFeedback;
			m_pUnmanaged = NULL;
			m_pFeedback = NULL;
		}
	}
	int Managed::MethodMixedCpp1(String ^ nValue)
	{
		Console::WriteLine("Метод MethodMixedCpp1 вызывает нативный метод MethodNativeCpp1 с аргументом: " + nValue);
		//m_pUnmanaged->MethodNativeCpp1(nValue);
		return 0;
	}



}