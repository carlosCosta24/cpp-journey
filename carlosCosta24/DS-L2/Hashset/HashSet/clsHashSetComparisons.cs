using System;
using System.Collections.Generic;


namespace HashSet
{
    public class clsHashSetComparisons
    {
        public HashSet<int> set1 = new HashSet<int> { 1, 2, 3 };
        public HashSet<int> set2 = new HashSet<int> { 1, 2, 3, 4, 5 };
        public HashSet<int> set3 = new HashSet<int> { 6, 7, 8 };



        public void EqualityChecking()
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
            Console.WriteLine("Print Set3 items: \n");
            foreach (int i in set3)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine("Is set1 = set2: " + set1.SetEquals(set2));
            Console.WriteLine("Is set2 = set3: " + set2.SetEquals(set3));

            Console.ReadKey();

        }
        public void IsSubSetOf()
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

            Console.WriteLine("Is set1 subset of set2: " + set1.IsSubsetOf(set2));

            Console.ReadKey();

        }
        public void IsSuperSetOf()
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

            Console.WriteLine("Is set2 subset of set1: " + set2.IsSupersetOf(set1));

            Console.ReadKey();

        }
        public void IsOverlaps()
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
            Console.WriteLine("Print Set3 items: \n");
            foreach (int i in set3)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine("Is set1 overlaps with set2: " + set1.Overlaps(set2));
            Console.WriteLine("Is set2 overlaps with set3: " + set2.Overlaps(set3));


            Console.ReadKey();

        }
    }
}
