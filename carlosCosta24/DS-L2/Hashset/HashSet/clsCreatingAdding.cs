using System;
using System.Collections.Generic;

namespace HashSet
{
    public class clsCreatingAdding
    {
        public HashSet<string> Employes = new HashSet<string>
        {
            "Calros",
            "Aloha",
            "Max", 
        };

        public void Operations() 
        {
            Console.WriteLine("Printing Hashset Items: \n");
            foreach (var E in Employes) 
            {
                Console.WriteLine($"Employee Name: {E}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Print After Adding to Hashset 3 Items: \n");
            Employes.Add("Walid");
            Employes.Add("Bhaa");
            Employes.Add("Aly");
            foreach (var E in Employes)
            {
                Console.WriteLine($"Employee Name: {E}");
            }
            Console.WriteLine("\n");

            Console.ReadKey();
        }
    }
}
