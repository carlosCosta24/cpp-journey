using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IDictionaryExample
{
    internal class Program
    {
        static void Main(string[] args)
        {
            clsIDictionaryImplementation<int , string> Students = 
            new clsIDictionaryImplementation<int , string>();


            // add Items to the dic
            Students.Add(0, "Carlos");
            Students.Add(1, "Luiza");
            Students.Add(2, "Alex");

            //Iterate through 
            Console.WriteLine("Print Students Info:");
            Console.WriteLine("\n");

            foreach (var Item in Students) 
            {
                Console.WriteLine($"\tID: {Item.Key}, Name: {Item.Value}");
            }

            //Access Item By key 

            var FirstStudent = Students[0];
            Console.WriteLine("\n");

            Console.WriteLine($"First Student Name: {FirstStudent}");
            Console.WriteLine("\n");

            //Check if Dictionary contain key 
            Console.WriteLine($"Students Contain Id 4 :{Students.ContainsKey(4)}");
            Console.WriteLine("\n");

            //Remove the last item in the dictionary

            Students.Remove(2);

            //print the dictionary after edits
            Console.WriteLine("Print Students Info After Delete Last Element:");
            Console.WriteLine("\n");

            for (int i = 0; i < Students.Count; i++)
            {
                
                Console.WriteLine($"\tStudent Name: {Students[i]}");
            }

            Console.ReadKey();

        }
    }
}
