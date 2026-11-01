using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortedSet
{
    public class clsCreate
    {
        public SortedSet<int> OrderedNumberSet = new SortedSet<int>();

        public void AddOperation() 
        {
            OrderedNumberSet.Add(0);
            OrderedNumberSet.Add(10);
            OrderedNumberSet.Add(15);
            OrderedNumberSet.Add(3);
            OrderedNumberSet.Add(25);
            OrderedNumberSet.Add(80);
            OrderedNumberSet.Add(100);

        }
        public void RemoveOperation()
        {
            OrderedNumberSet.Remove(25);
        }

        public void PrintSummary()
        {
            AddOperation();
            Console.WriteLine("Print SortedSet Elements: \n");
            for (int i = 0; i < OrderedNumberSet.Count; i++) 
            {
                Console.WriteLine($"OrderdNumberSet Item {i}: {OrderedNumberSet.ElementAt(i)}");
            }

            Console.WriteLine("\n");
            RemoveOperation();
            Console.WriteLine("Print SortedSet Elements After Removal: \n");
            foreach (int Item in OrderedNumberSet) 
            {
                Console.WriteLine($"Item: {Item}");
            }

            Console.WriteLine("\n");
            Console.WriteLine("Check If Number 10 Exist in the SortedSet Elements: \n");
            Console.WriteLine(
            OrderedNumberSet.Contains(10) 
            ? $"Number Exist :-)"
            : "Number Not Exist :-("
            );

            Console.ReadKey();
        }

        
    }
}
