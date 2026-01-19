using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("this write line fun");
            Console.Write("this is a line without any space ");
            Console.Write("and will be printed togther");
            //formated string
            Console.WriteLine(" ");
            Console.WriteLine("{0} {1}", "Carols", "Costa");

            Console.WriteLine("Useful Escape Characters: \n");

            Console.WriteLine("NewLine:");
            Console.WriteLine("Welcome to \n newline");

            //tab
            Console.WriteLine("Tab");
            Console.WriteLine("Welcome to \tthe tap");

            //Backspace
            Console.WriteLine("Backspace");
            Console.WriteLine("Welcome to \b this is the backspace");

            //singel quote
            Console.WriteLine("Single quote");
            Console.WriteLine("Welcome to the \' my space \' ");

            //Double quote
            Console.WriteLine("Single quote");
            Console.WriteLine("Welcome to the \" my space \" ");

            //Backslash
            Console.WriteLine("Backslash");
            Console.WriteLine("Welcome this is a \\ backslash");

            //alert
            Console.WriteLine("\a");

            Console.ReadKey();

        }
    }
}
