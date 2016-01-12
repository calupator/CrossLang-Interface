#include "stdafx.h"
#include "Managed.h"
#include "Feedback.h"
#include <string>

using namespace Wrapper;

Feedback::Feedback(Managed^ p)
{
	m_pManaged = p;
}

void Feedback::OnValueChanged(std::string str)
{
	String ^ mstr = gcnew String(str.c_str());
	m_pManaged->ValueChanged(mstr);
}
