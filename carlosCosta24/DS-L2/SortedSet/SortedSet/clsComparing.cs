using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortedSet
{
    public class clsComparing
    {
        public SortedSet<int> set1 = new SortedSet<int>() { 1, 2, 3, 4, 5 };
        public SortedSet<int> set2 = new SortedSet<int>() { 3, 4, 5, 6, 7 };

        public void ComparingOperations() 
        {
            Console.WriteLine("Printing First SortedSet Elements: \n");
            foreach (int i in set1)
            {
                Console.WriteLine($"Element: {i}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Printing Second SortedSet Elements: \n");
            foreach (int i in set2)
            {
                Console.WriteLine($"Element: {i}");
            }
            Console.WriteLine("\n");

            SortedSet<int> union = new SortedSet<int> (set1);
            union.UnionWith(set2);
            Console.WriteLine("Union Of Two Sets: \n");
            foreach (int i in union)
            {
                Console.WriteLine($"Element: {i}");
            }
            Console.WriteLine("\n");

            SortedSet<int> intersect = new SortedSet<int> (set1);
            intersect.IntersectWith(set2);
            Console.WriteLine("Intersect Of Two Sets: \n");
            foreach (int i in intersect)
            {
                Console.WriteLine($"Element: {i}");
            }
            Console.WriteLine("\n");

            SortedSet<int> difference = new SortedSet<int> (set1);
            difference.ExceptWith(set2);
            Console.WriteLine("Difference Of Two Sets: \n");
            foreach (int i in difference)
            {
                Console.WriteLine($"Element: {i}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Is Set2 Subset Of Set1: ");
            Console.WriteLine
            (
                set2.IsSubsetOf(set1)
                ? "Yes"
                : "No" 


            );

            Console.WriteLine("Is Set1 Superset Of Set2: ");
            Console.WriteLine
            (
                set1.IsSupersetOf(set2)
                ? "Yes"
                : "No"


            );
            Console.WriteLine("Is Set1 Equal Set2: ");
            Console.WriteLine
            (
                set1.SetEquals(set2)
                ? "Yes"
                : "No"


            );
            Console.ReadKey();
        }
    }
}
