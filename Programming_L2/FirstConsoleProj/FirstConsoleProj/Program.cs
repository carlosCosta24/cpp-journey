using System;

namespace FirstConsoleProj
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a number to calculate the factorial: ");
            int n = int.Parse(Console.ReadLine());
            int fact = 1;

            for (int i = 2; i <= n; i++) { 
                fact = fact * i;
            }
            Console.WriteLine($"result of {n}! is: ");
            Console.WriteLine(fact);
        }
    }
}
