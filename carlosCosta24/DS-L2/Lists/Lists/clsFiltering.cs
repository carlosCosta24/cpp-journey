using System;
using System.Collections.Generic;
using System.Linq;


namespace Lists
{
    public class clsFiltering
    {
        public void FilteringEx() 
        { 
            List<int> NumberSet = new List<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            Console.WriteLine("List items: " + string.Join(",", NumberSet));
            Console.WriteLine("Print all even numbers: " + string.Join(", ", NumberSet.Where(N => N % 2 == 0)));
            Console.WriteLine("Print all odd numbers: " + string.Join(", ", NumberSet.Where(N => N % 2 == 1)));
            Console.WriteLine("Print all numbers between 3 and 9: " + string.Join(", ", NumberSet.Where(N => N > 3 && N < 9)));
            Console.WriteLine("Print numbers > 8: " + string.Join(", ", NumberSet.Where(N => N > 8)));
            Console.WriteLine("Print every second number: " + string.Join(", ", NumberSet.Where((_, index) => index % 2 == 1)));

            Console.ReadKey();




        }


    }
}
