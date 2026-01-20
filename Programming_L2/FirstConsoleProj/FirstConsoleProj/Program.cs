using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program { 
        static void Main(string[] args)
        {

            // date and time
            DateTime dt = new DateTime();

            DateTime dt1 = new DateTime(2023, 12, 12);

            DateTime dt2 = new DateTime(2025, 12, 30, 5, 10, 26);

            DateTime dt3 = DateTime.Now;


            Console.WriteLine(dt);       
            Console.WriteLine(dt1);
            Console.WriteLine(dt2);
            Console.WriteLine(dt3);


            Console.ReadKey();


        }
    }
}
