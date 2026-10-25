using System;
using System.Collections.Generic;


namespace HashSet
{
    public class clsRemove
    {
        public HashSet<string> Fruits = new HashSet<string>{ "Orange", "Mango", "Apple", "Grape", "Fig"};


        public void RemovingItems()
        {
            Console.WriteLine("Print HashSet Items: \n");
            foreach (var item in Fruits) 
            {
                Console.WriteLine($"Item Name: {item}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Remove Apple From HashSet: \n");
            Fruits.Remove("Apple");
            foreach (var item in Fruits)
            {
                Console.WriteLine($"Item Name: {item}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Clear HashSet Items: \n");

            Fruits.Clear();

            Console.WriteLine("HashSet Count: " + Fruits.Count.ToString());

            Console.ReadKey();
        } 
    }
}
