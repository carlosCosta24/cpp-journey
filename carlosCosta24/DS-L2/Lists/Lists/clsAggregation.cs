using System;
using System.Collections.Generic;
using System.Linq;

namespace Lists
{
    public class clsAggregation
    {
        public void AggFunc() 
        {
            List<int> Even = new List<int> { 10, 20, 40, 80 };

            //aggregation function from linq lib

            Console.WriteLine("List items: \n" + string.Join(", ", Even));
            Console.WriteLine("Count of list items: " + Even.Count());
            Console.WriteLine("Sum of list items: " + Even.Sum());
            Console.WriteLine("Maximum item in list: " + Even.Max());
            Console.WriteLine("Minimum item in list: " + Even.Min());
            Console.WriteLine("Average of list items: " + Even.Average());

            Console.ReadKey();

        }
    }
}
