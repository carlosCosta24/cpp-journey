using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashSet
{
    public class clsHashSetOperations
    {
        public HashSet<int> set1 = new HashSet<int> { 1, 2, 3 };
        public HashSet<int> set2 = new HashSet<int> { 3, 4, 5 };

        public void UnionOperation()
        {
            Console.WriteLine("Print Set1 items: \n");
            foreach(int i in set1)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine("Print Set2 items: \n");
            foreach (int i in set2)
            {
                Console.WriteLine(i);
            }

            //combine all the sets togther
            set1.UnionWith(set2);

            Console.WriteLine("Print union of 2 Sets: \n");
            foreach (int i in set1)
            {
                Console.WriteLine(i);
            }
            Console.ReadKey();
        }
        public void IntersectionOperation()
        {

            Console.WriteLine("Print Set1 items: \n");
            foreach (int i in set1)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine("Print Set2 items: \n");
            foreach (int i in set2)
            {
                Console.WriteLine(i);
            }

            set1.IntersectWith(set2);

            Console.WriteLine("Print intersection of 2 Sets: \n");
            foreach (int i in set1)
            {
                Console.WriteLine(i);
            }
            Console.ReadKey();

        }
        public void DifferanceOperation() 
        {
            Console.WriteLine("Print Set1 items: \n");
            foreach (int i in set1)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine("Print Set2 items: \n");
            foreach (int i in set2)
            {
                Console.WriteLine(i);
            }

            set1.ExceptWith(set2);

            Console.WriteLine("Print Difference of 2 Sets: \n");
            foreach (int i in set1)
            {
                Console.WriteLine(i);
            }
            Console.ReadKey();
        }
        public void SymmetricDifference() 
        {
            Console.WriteLine("Print set1 items: \n");
            foreach (int i in set1)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine("Print set2 items: \n");
            foreach (int i in set2)
            {
                Console.WriteLine(i);
            }

            set1.SymmetricExceptWith(set2);

            Console.WriteLine("Print symmetric difference of 2 sets: \n");
            foreach (int i in set1)
            {
                Console.WriteLine(i);
            }
            Console.ReadKey();
        }
    }
}
