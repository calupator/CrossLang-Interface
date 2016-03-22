
#include "IInterface.h"

// без этой переменной не создается lib-файл
_API int fnMy1212(void);


namespace InterfaceNativeCpp
{

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
		float m_val;

	public:
		TestInterfaceNativeCpp(void);
		virtual ~TestInterfaceNativeCpp(void);
		//TestInterfaceNativeCpp(CFeedback* pFeedback);
		int MethodNativeCpp1(std::string pszString);
		float getPropNativeCpp1(void);
		void setPropNativeCpp1(float newVal);
	};
}