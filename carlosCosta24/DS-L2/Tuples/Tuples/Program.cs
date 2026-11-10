using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tuples
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //declar a tuple 
            (int, string, double) Person = ( 1, "Carlos", 1.77 );

            Console.WriteLine($"First Tuple Item: {Person.Item1}");
            Console.WriteLine($"Second Tuple Item: {Person.Item2}");
            Console.WriteLine($"Third Tuple Item: {Person.Item3}");


            var Values = TupleFunction();
            Console.WriteLine($"Tuple Function First Item: {Values.Item1}");
            Console.WriteLine($"Tuple Function Second Item: {Values.Item2}");

            Console.ReadKey();

        }
        static (int, string) TupleFunction()
        {
            return (1, "Name");
        }
    }
}
