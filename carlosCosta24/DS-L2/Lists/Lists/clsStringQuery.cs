using System;
using System.Collections.Generic;
using System.Linq;

namespace Lists
{
    public class clsStringQuery
    {
        public void StringOperation()
        {
            List<string> Fruits = new List<string> { "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew" };
            Console.WriteLine("List Items: " + string.Join(", ", Fruits));

            //contain
            Console.WriteLine("Is list contain banana: " + Fruits.Contains("banana"));

            //exist
            Console.WriteLine("Is there fruits with more than 9 characters exist in the list: " + Fruits.Exists(n=> n.Length > 9));

            //find
            Console.WriteLine("Find first fruit with 3 characters in the list: " + Fruits.Find(n => n.Length == 3));

            //find all 
            Console.WriteLine("Find all fruits with 5 characters in the list: " + string.Join(",", Fruits.FindAll(n => n.Length == 5)));

            //any
            Console.WriteLine("Is there any Fruits start with c in the list: " + Fruits.Any(n => n.StartsWith("c")));

            //any 
            Console.WriteLine("Is there any Fruits end with w in the list: " + Fruits.Any(n => n.EndsWith("w")));

            Console.ReadKey();
        }
    }
}
