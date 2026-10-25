using System;
using System.Collections.Generic;

namespace HashSet
{
    public class clsRemoveDuplicates
    {

        public int[] DuplicatedNumbers = new int[] { 1, 2, 2, 3, 6, 5, 8, 9, 7, 8, 5, 4 };

        public void RemoveDuplicates()
        {
            //Remove Duplicates using HashSet
            HashSet<int> UniqueNumbers = new HashSet<int>(DuplicatedNumbers);

            Console.WriteLine("Printing Number Set: \n");
            foreach (int i in DuplicatedNumbers)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine("Printing Number Set After Removing Duplicates: \n");
            foreach (int Item in UniqueNumbers)
            {
                Console.WriteLine(Item);
            }
            Console.ReadKey();

        }
    }
}
