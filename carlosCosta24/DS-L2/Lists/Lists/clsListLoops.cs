using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lists
{
    public class clsListLoops
    {
        public void LoopOperations() 
        {
            List<int> IntegerSet = new List<int> { 10,20,70,85,90,78,25,76,66};

            //Loop through using for 
            Console.WriteLine("Print list using for loop: \n");
            for (int i = 0; i < IntegerSet.Count; i++) 
            {
                Console.WriteLine($"Index {i}: " + IntegerSet[i]);
            }

            //loop through using foreach
            Console.WriteLine("Print list using foreach: \n");
            foreach(int n in IntegerSet)
            {
                Console.WriteLine(n);   
            }

            //Loop through using lambda fun
            Console.WriteLine("Loop using lambda func: \n");
            IntegerSet.ForEach(i => Console.WriteLine(i));

            Console.ReadKey();
        }
    }
}
