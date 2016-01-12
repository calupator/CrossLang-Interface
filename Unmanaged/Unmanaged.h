#pragma once
#include <string>

#define UNMANAGED_API __declspec(dllexport)

class UNMANAGED_API CUnmanaged 
{
public:
	class UNMANAGED_API CFeedback
	{
	public:
		virtual void OnValueChanged(std::string str) = 0;
	};
	
	CUnmanaged(CFeedback* pFeedback);
	
	void MethodNativeCpp1(int nValue);
	void setPropNativeCpp1(int nValue);
	int getPropNativeCpp1();
	
private:
	CFeedback* m_pFeedback;
	int m_nValue;
};

