using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortedSet
{
    public class clsLinqOperations
    {
        public SortedSet<int> sortedSet = new SortedSet<int>() { 1, 2, 3, 4, 5 };

        public void PrintOperationsResults() 
        {
            Console.WriteLine("Printing SortedSet Elements: \n");
            foreach (int i in sortedSet) 
            {
                Console.WriteLine($"Element: {i}");
            }
            Console.WriteLine("\n");

            //filtering
            Console.WriteLine("Printing Element Greater Than 3: \n");
            var GreaterThan3 = sortedSet.Where(x => x > 3);
            foreach (var i in GreaterThan3)
            {
                Console.WriteLine($"Element: {i}");
            }

            Console.WriteLine("\n");
            Console.WriteLine("Print Sum Of The Set");
            Console.WriteLine($"Sum: {sortedSet.Sum()}");
            Console.WriteLine("\n");

            //Max and min 
            Console.WriteLine("Printing Max And Min Numbers: \n");
            Console.WriteLine($"Max: {sortedSet.Max}");
            Console.WriteLine($"Min: {sortedSet.Min}");
            Console.WriteLine("\n");

            //Order Desc
            Console.WriteLine("Order Set In Descending Order: \n");
            var ReverseOrder = sortedSet.OrderByDescending(x => x);
            foreach (var i in ReverseOrder)
            {
                Console.WriteLine($"Element: {i}");
            }
            Console.WriteLine("\n");



            Console.ReadKey();

        }
    }
}
