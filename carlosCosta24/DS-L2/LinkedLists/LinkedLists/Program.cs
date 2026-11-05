using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedLists
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LinkedList<string> Freinds = new LinkedList<string>();

            Freinds.AddLast("Spongy");
            Freinds.AddLast("Koko");
            Freinds.AddLast("Lucas");

            Console.WriteLine("Printing Linked List Items:");
            var IndexedList = Freinds.Select((Item, Index) => new { Item, Index });
            foreach (var i in IndexedList)
            {
                Console.WriteLine($"Item {i.Index}: {i.Item}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Add At Start: ");
            Freinds.AddFirst("Aloha");
            foreach (string i in Freinds)
            {
                Console.WriteLine($"Item: {i}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Clear Linked List: ");
            Freinds.Clear();
            Console.WriteLine($"Number of Item In Linked List: {Freinds.Count} ");
            Console.WriteLine("\n");

            Console.ReadKey();

        }
    }
}
