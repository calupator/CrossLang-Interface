
#include <string>
#include <iostream>
#include <sstream>

#define _API __declspec(dllexport)
extern _API int nMy1212;

// без этой переменной не создается lib-файл
_API int fnMy1212(void);

typedef void (*EventNativeCpp1EventHandler)(/*ITestInterfaceNativeCpp *sender,*/ std::string str);

namespace InterfaceNativeCpp
{
	class _API IInterfaceNativeCpp
	{
	public:
		virtual int getPropNativeCpp1() = 0;
		virtual void setPropNativeCpp1(int) = 0;
		virtual void MethodNativeCpp1(int) = 0;
		EventNativeCpp1EventHandler *EventNativeCpp1;
	};
	class _API TestInterfaceNativeCpp : public IInterfaceNativeCpp
	{
	public:
		/*class _API CFeedback
		{
		public:
			virtual void OnValueChanged( int nValue ) = 0;
		};*/
	private:
		//CFeedback* m_pFeedback;
		int pval;

	public:
		TestInterfaceNativeCpp();
		~TestInterfaceNativeCpp();
		//TestInterfaceNativeCpp(CFeedback* pFeedback);
		void MethodNativeCpp1(int X);
		int getPropNativeCpp1();
		void setPropNativeCpp1(int value);
	};
}