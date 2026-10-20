using System;
using System.Collections;
using System.Security.Cryptography.X509Certificates;


namespace HashTable
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Hashtable Values = new Hashtable();

            Values.Add(1, "Carlos");
            Values.Add(2, "Aloha");
            Values.Add(3, "Ricardo");
            Values.Add(4, "Koda");
            Values.Add(5, "Pento");
            Values.Add(6, "Yasmim");

            //iterating over the hashtable
            Console.WriteLine("Printing hashtable content: \n");
            foreach (DictionaryEntry DE in Values)
            {
                Console.WriteLine(DE.Value);
            }

            //updating value 5
            Values[5] = "Bugy";
            Console.WriteLine("Printing value item 5 after update: \n");
            foreach (DictionaryEntry DE in Values)
            {
                Console.WriteLine(DE.Value);
            }

            Console.WriteLine("Remove First Item From The HashTable: \n");
            Values.Remove(1);
            foreach (DictionaryEntry DE in Values)
            {
                Console.WriteLine(DE.Value);
            }

            Console.ReadKey();

        }
    }
}
