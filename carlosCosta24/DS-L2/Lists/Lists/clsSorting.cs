using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lists
{
    public class clsSorting
    {

        public void SortingList() 
        {
            List<int> NumberSet = new List<int> { 44, 22, 55, 666, 9, -6, 345, 11, 3, 3 };

            //default sorting methods
            Console.WriteLine("List items: " + string.Join(", ", NumberSet));

            NumberSet.Sort();
            Console.WriteLine("Sorted list: " + string.Join(",", NumberSet));

            NumberSet.Reverse();
            Console.WriteLine("Reversed list: " + string.Join(",", NumberSet));

            // sort using linq funcs

            Console.WriteLine("Sorted list using linq func: " + string.Join(",", NumberSet.OrderBy(n => n)));
            Console.WriteLine("Reversed list usnig linq func: " + string.Join(",", NumberSet.OrderByDescending(n => n)));

            Console.ReadKey();

        }
    }
}
