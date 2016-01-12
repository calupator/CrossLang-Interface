
#pragma once

using namespace System;

namespace InterfaceCpp
{
	public delegate void EventCpp1EventHandler();
	public delegate void EventCpp2EventHandler(Object ^ sender, String ^ str);

	public interface class IInterfaceCpp
	{
		property int PropCpp1{int get(); void set(int);}
		void MethodCpp1(int);

		event EventCpp1EventHandler ^ EventCpp1;
		event EventCpp2EventHandler ^ EventCpp2;
	};

	public ref class TestInterfaceCpp : IInterfaceCpp
	{
	private:
		int pval;
		EventCpp2EventHandler ^ d;

	public:
		TestInterfaceCpp();
		~TestInterfaceCpp();

		virtual event EventCpp1EventHandler ^EventCpp1;
		event EventCpp2EventHandler ^ EventCpp2
		{
			virtual void add(EventCpp2EventHandler ^ _d)
			{
				d = safe_cast<EventCpp2EventHandler ^>(System::Delegate::Combine(d, _d));
			}

			virtual void remove(EventCpp2EventHandler ^ _d)
			{
				d = safe_cast<EventCpp2EventHandler ^>(System::Delegate::Remove(d, _d));
			}

			virtual void raise(Object ^ sender, String ^ str)
			{
				if (d)
				{
					d->Invoke(this, str);
				}
			}
		}

		virtual void MethodCpp1(int X) sealed;

		property int PropCpp1
		{
			virtual int get() sealed
			{
				return pval;
			}
			virtual void set(int value) sealed
			{
				pval = value;
			}
		}

	};
}
