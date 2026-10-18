using System;
using System.Collections.Generic;
using System.Linq;

namespace Lists
{
    public class clsQuerying
    {
        public void ListQuery()
        {
            List<int> numbers = new List<int> { 44, 22, -55, 666, 9, -6, 345, 11, 3, 3 };

            Console.WriteLine("List Items: " + string.Join(", ", numbers));

            //contain
            Console.WriteLine("Is list contain -55: " + numbers.Contains(-55));

            //exist
            Console.WriteLine("Is there number > 9 exist in the list: " + numbers.Exists(n=> n > 9));

            //find
            Console.WriteLine("Find number 11 in the list: " + numbers.Find(n=> n ==11));

            //find all 
            Console.WriteLine("Find all -ve number in the list: " + string.Join(",",numbers.FindAll(n => n < 0)));

            //any
            Console.WriteLine("Is there any number with 3 digits in the list: " + numbers.Any(n => n > 100 && n < 999));

            Console.ReadKey();
        }
    }
}
