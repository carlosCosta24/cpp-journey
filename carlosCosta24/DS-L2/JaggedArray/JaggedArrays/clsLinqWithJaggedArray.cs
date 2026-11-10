using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JaggedArrays
{
    public class clsLinqWithJaggedArray
    {
        public int[][] Items = { new int[] { 1,2,3}, new int[] {10,20,30,40 }, new int[] { 100,200, 300}};

        public void LinqOperations()
        {
            Console.WriteLine("Print Array Items: \n");
            for (int i = 0; i < Items.Length; i++)
            {
                for (int j = 0; j < Items[i].Length; j++)
                {
                    Console.WriteLine($"Item {j + 1} in Array Number {i + 1} is: {Items[i][j]}\n");
                }
            }

            int ArraySum = Items.SelectMany(Array => Array).Sum();
            Console.WriteLine("Print Sum of Array Items: ");
            Console.WriteLine($"{ArraySum}\n");

            int MaxNumber = Items.SelectMany(E => E).Max();
            int MinNumber = Items.SelectMany(E => E).Min();
            double AvgNumber = Items.SelectMany(E => E).Average();

            Console.WriteLine("Print Max of Array Items: ");
            Console.WriteLine($"{MaxNumber}\n");

            Console.WriteLine("Print Min of Array Items: ");
            Console.WriteLine($"{MinNumber}\n");

            Console.WriteLine("Print Average of Array Items: ");
            Console.WriteLine($"{AvgNumber}\n");

            var Filter = Items.Where(E => E.Length > 3).Select(E => E.First());

            Console.WriteLine("First Number in Longest Array: \n");
            foreach (var element in Filter)
            {
                Console.Write(element);
            }

            Console.ReadKey();
        }
    }
}
