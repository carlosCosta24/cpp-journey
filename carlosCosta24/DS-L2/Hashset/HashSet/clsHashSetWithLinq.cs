using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;


namespace HashSet
{
    public class clsHashSetWithLinq
    {
        public HashSet<int> numbers = new HashSet<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        public HashSet<string> names = new HashSet<string>
                        { "Alice", "Bob", "Charlie", "Daisy", "Ethan", "Fiona" };

        public void IntLinqOperations()
        {
            Console.WriteLine("Print HashSet Items: \n");

            foreach (var item in numbers)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\n");

            Console.WriteLine("Print Even Numbers: ");
            var EvenNumbers = numbers.Where(n => n % 2 == 0);
            
            foreach (var number in EvenNumbers)
            {
                Console.WriteLine(number);
            }
            Console.WriteLine("\n");

            Console.WriteLine("Print Numbers dividable by 3: ");
            var DividedByThree = numbers.Where(n => n % 3 == 0);

            foreach (var number in DividedByThree)
            {
                Console.WriteLine(number);
            }
            Console.WriteLine("\n");

            Console.ReadKey();
        }

        public void StringLinqOperations()
        {
            Console.WriteLine("Print HashSet Items: \n");

            foreach (var item in names)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\n");

            Console.WriteLine("Print Items Start With B: \n");
            var StartWithB = names.Where(n => n.StartsWith("B"));
            foreach (var item in StartWithB)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\n");


            Console.WriteLine("Print Items Longer 4 characters: \n");
            var LongerThan4 = names.Where(n => n.Length > 4);
            foreach (var item in LongerThan4)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\n");

            Console.WriteLine("Print Items end with e: \n");
            var EndWithE = names.Where(n => n.EndsWith("e"));
            foreach (var item in EndWithE)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine("\n");

            Console.ReadKey();
        }

    }
}
