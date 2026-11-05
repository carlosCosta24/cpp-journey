using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queues
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Queue<int> WaitingLine = new Queue<int>();

            WaitingLine.Enqueue(1);
            WaitingLine.Enqueue(2);
            WaitingLine.Enqueue(3);
            WaitingLine.Enqueue(4);
            WaitingLine.Enqueue(5);


            Console.WriteLine("Printing Queue Content: \n");
            foreach (int Item in WaitingLine) 
            {
                Console.WriteLine($"Item: {Item}");
            }
            Console.WriteLine("\n");

            Console.WriteLine($"First Item In Queue: {WaitingLine.Peek()}");
            Console.WriteLine($"Serving Item: {WaitingLine.Dequeue()}");
            Console.WriteLine($"Serving Item: {WaitingLine.Dequeue()}");

            Console.WriteLine("\n");
            Console.WriteLine($"Getting Queue Length: {WaitingLine.Count}");
            Console.WriteLine("\n");

            Console.WriteLine("Checking if Queue Is Empty: ");
            Console.WriteLine(WaitingLine.Count == 0? "Queue Is Empty :-(" : "Queue Is Not Empty :-)" );
            Console.WriteLine("\n");

            Console.WriteLine("Clearing The Queue: ");
            WaitingLine.Clear();
            Console.WriteLine($"Queue Contents Count: {WaitingLine.Count()}");

            Console.ReadKey();

        }
    }
}
