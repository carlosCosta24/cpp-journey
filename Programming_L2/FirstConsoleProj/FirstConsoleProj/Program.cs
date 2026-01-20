using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program { 
        static void Main(string[] args)
        {

            // dynamic types
            dynamic DynamicVar = 10;
            Console.WriteLine("Value: {0}, Type {1}", DynamicVar, DynamicVar.GetType());

            DynamicVar = "Carlos costa";
            Console.WriteLine("Value: {0}, Type {1}", DynamicVar, DynamicVar.GetType());

            DynamicVar = true;
            Console.WriteLine("Value: {0}, Type {1}", DynamicVar, DynamicVar.GetType());

            DynamicVar = DateTime.Now;
            Console.WriteLine("Value: {0}, Type {1}", DynamicVar, DynamicVar.GetType());


            Console.ReadKey();


        }
    }
}
