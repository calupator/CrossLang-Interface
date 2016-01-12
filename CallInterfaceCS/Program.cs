using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using InterfaceVB;
using InterfaceCS;
using InterfaceCpp;
using Wrapper;

namespace CallInterfaceCS
{
    class Program
    {
        private static TestInterfaceVB VBtest;
        private static TestInterfaceCS CStest;
        private static TestInterfaceCpp Cpptest;
        private static Managed Mixedtest;

        static void Main(string[] args)
        {
            Console.WriteLine("*****************************");
            if (IntPtr.Size == 4)
            {
                Console.WriteLine("* 32-х битное приложение!!! *");
            }
            else if (IntPtr.Size == 8)
            {
                Console.WriteLine("* 64-х битное приложение!!! *");
            }
            Console.WriteLine("*****************************");

            VB();
            CS();
            Cpp();
            Wrapper();

            Console.ReadKey();
        }

        static void EventHandler(object sender, string str)
        {
            Console.WriteLine("Обработчик события поймал событие: " + "\r" + "\n" + str);
            Console.WriteLine();
        }
        static void EventHandler(string str)
        {
            Console.WriteLine("Обработчик события поймал событие: " + "\r" + "\n" + str);
            Console.WriteLine();
        }

        static void EventHandler()
        {
            Console.WriteLine("Обработчик события поймал событие без параметров");
            Console.WriteLine();
        }

        static void VB()
        {
            Console.WriteLine("         Visual Basic        ");
            Console.WriteLine();
            VBtest = new TestInterfaceVB();
            VBtest.EventVB1 += new IInterfaceVB.EventVB1EventHandler(EventHandler);
            VBtest.PropVB1 = 111;
            Console.WriteLine("Свойство PropVB1 установлено в: " + VBtest.PropVB1);
            VBtest.MethodVB1(5);
            Console.WriteLine("=====================================================");
        }

        static void CS()
        {
            Console.WriteLine("         Visual C#        ");
            Console.WriteLine();
            CStest = new TestInterfaceCS();
            CStest.EventCS1 += new EventCS1EventHandler(EventHandler);
            CStest.PropCS1 = 111;
            Console.WriteLine("Свойство PropCS1 установлено в: " + CStest.PropCS1);
            CStest.MethodCS1(5);
            Console.WriteLine("=====================================================");
        }

        static void Cpp()
        {
            Console.WriteLine("         Visual C++        ");
            Console.WriteLine();
            Cpptest = new TestInterfaceCpp();
            Cpptest.EventCpp1 += new EventCpp1EventHandler(EventHandler);
            Cpptest.EventCpp2 += new EventCpp2EventHandler(EventHandler);
            Cpptest.PropCpp1 = 111;
            Console.WriteLine("Свойство PropCpp1 установлено в: " + Cpptest.PropCpp1);
            Cpptest.MethodCpp1(5);
            Cpptest.MethodCpp1(0);
            Console.WriteLine("=====================================================");
        }

        static void Wrapper()
        {
            Console.WriteLine("           Managed wrapper for native DLL         ");
            Console.WriteLine();
            Mixedtest = new Managed();
            Mixedtest.ValueChanged += new ValueChangedHandler(EventHandler);
            Mixedtest.PropMixedCpp1 = 111;
            Console.WriteLine("Свойство PropManagedCpp1 установлено в: " + Mixedtest.PropMixedCpp1);
            Mixedtest.MethodMixedCpp1(5);
            Console.WriteLine("=====================================================");
        }
    }
}
