#pragma once

#include <vcclr.h>
#include "..\Unmanaged\Unmanaged.h"
#include <string>

using namespace Wrapper;

class Feedback : public CUnmanaged::CFeedback 
{
public:
	Feedback(Managed^ p);
	void OnValueChanged(std::string str);
	
private:
	gcroot<Managed^> m_pManaged;
};
