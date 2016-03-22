#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "..\Unmanaged\Unmanaged.h"

using namespace System;

class Feedback;

namespace Wrapper
{
	public delegate void ValueChangedHandler(String ^ str);
	
	public ref class Managed
	{
	public:
		Managed(void);
		virtual ~Managed(void);

		int MethodMixedCpp1(String ^ nValue);
		
		property int PropMixedCpp1
		{
			virtual int get() sealed
			{
				std::cout << "ѕолучени€ свойства setPropNativeCpp1 нативного класса." << std::endl;
				return m_pUnmanaged->getPropNativeCpp1();
			}
			virtual void set(int nValue) sealed
			{
				std::cout << "”становка свойства getPropNativeCpp1 нативного класса." << std::endl;
				m_pUnmanaged->setPropNativeCpp1(nValue);
			}
		}
	
		event ValueChangedHandler^ ValueChanged
		{
			virtual void add(ValueChangedHandler^ pValueChanged)
			{
				m_pValueChanged = safe_cast<ValueChangedHandler^>(Delegate::Combine(m_pValueChanged, pValueChanged));
			}

			virtual void remove(ValueChangedHandler^ pValueChanged)
			{
				m_pValueChanged = safe_cast<ValueChangedHandler^>(Delegate::Remove(m_pValueChanged, pValueChanged));
			}

			virtual void raise(String ^ str)
			{
				if(m_pValueChanged != nullptr)
					m_pValueChanged->Invoke(str);
			}
		}

	protected:
		!Managed(void);

	private:
		CUnmanaged* m_pUnmanaged;
		Feedback* m_pFeedback;
		ValueChangedHandler^ m_pValueChanged;
	};
}
