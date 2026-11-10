using System;
using System.Collections.Generic;
using System.Linq;

namespace Tuples
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //declar a tuple 
            (int, string, double) Person = (1, "Carlos", 1.77);
            List<(int ID, string Name, int Age)> People = new List<(int ID, string Name, int Age)>
            {
                            (1, "Alice", 30),
            (2, "Bob", 25),
            (3, "Charlie", 35),
            (4, "Diana", 28)
            };

            Console.WriteLine($"First Tuple Item: {Person.Item1}");
            Console.WriteLine($"Second Tuple Item: {Person.Item2}");
            Console.WriteLine($"Third Tuple Item: {Person.Item3}");


            var Values = TupleFunction();
            Console.WriteLine($"Tuple Function First Item: {Values.Item1}");
            Console.WriteLine($"Tuple Function Second Item: {Values.Item2}");
            Console.WriteLine("\n");

            var Filtered = People.Where(P => P.Age > 27);
            Console.WriteLine("Print People of Age > 27: \n");
            foreach (var P in Filtered) 
            {
                Console.WriteLine($"Person ID: {P.Item1}, Name: {P.Item2}, Age: {P.Item3}");
            }

            Console.WriteLine("\n");
            var AverageAge = People.Average(P => P.Age);
            Console.WriteLine("Print Average People Age: \n");
            Console.WriteLine(AverageAge);


            Console.ReadKey();

        }
        static (int, string) TupleFunction()
        {
            return (1, "Name");
        }
    }
}
