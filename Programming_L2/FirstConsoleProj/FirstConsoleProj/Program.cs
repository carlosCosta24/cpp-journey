using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program
    {
        static void Main(string[] args)
        {

            string Name = "Carlos costa";
            Console.WriteLine($"My name is: {Name}");

            int i = 0; int j = 1;
            Console.WriteLine($"X + Y = {i + j}");

            double pi = 3.14D;

            Console.WriteLine($"Double var: Pi : {pi}");

            Console.ReadKey();

        }
    }
}
