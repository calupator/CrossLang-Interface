using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace InterfaceCS
{
    public delegate void EventCS1EventHandler(object sender, string str);

    public interface IInterfaceCS
    {
        int PropCS1 { get; set; }
        void MethodCS1(int X);
        event EventCS1EventHandler EventCS1;
    }

    public class TestInterfaceCS : IInterfaceCS
    {

        // Holds the value of the property.
        private int pval;

        public event EventCS1EventHandler EventCS1;

        public void MethodCS1(int X)
        {
            Console.WriteLine("Метод MethodCS1 получил параметр: " + X);
            if (EventCS1 != null)
                EventCS1(this, "\t" + "Аргумент метода MethodCS1: " + X);
        }

        public int PropCS1
        {
            get
            {
                return pval;
            }
            set
            {
                pval = value;
            }
        }
    }
}

