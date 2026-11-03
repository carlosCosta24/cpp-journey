using System;
using System.Collections.Generic;
using System.Linq;

namespace Stacks
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Stack<int> NumberStack = new Stack<int>();

            NumberStack.Push(1);
            NumberStack.Push(2);
            NumberStack.Push(3);

            Console.WriteLine("Stack Elements: ");
            foreach (int Number in NumberStack)
            {
                Console.WriteLine($"Item: {Number}");
            }
            Console.WriteLine("\n");
            Console.WriteLine($"Top element in the stack: {NumberStack.Peek()}");
            Console.WriteLine("\n");

            NumberStack.Pop();

            Console.WriteLine("Stack Elements: ");
            foreach (int Number in NumberStack)
            {
                Console.WriteLine($"Item: {Number}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Check if stack is empty: ");
            if (NumberStack.Count == 0)
            {
                Console.WriteLine("Stack is empty!");
            }
            else
            {
                Console.WriteLine("Stack is not empty :-)");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Stack after clearing: ");
            NumberStack.Clear();


            Console.WriteLine($"Number of item in the stack: {NumberStack.Count()}");

            Console.ReadKey();

        }
    }
}
