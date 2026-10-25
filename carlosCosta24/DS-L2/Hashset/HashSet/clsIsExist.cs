using System;
using System.Collections.Generic;


namespace HashSet
{
    public class clsIsExist
    {
        public HashSet<string> Employes = new HashSet<string>
        {
            "Carlos",
            "Aloha",
            "Max",
        };

        public void Found() 
        {
            Console.WriteLine("Printing Hashset Items If It Exist: \n");
            if (Employes.Contains("Carlos"))
            {
                Console.WriteLine($"Employ With Name Carlos Was Found :-) ");
            }
            else 
            {
                Console.WriteLine("There Is No Employee found!\n");
            }
            Console.WriteLine("\n");

            if (Employes.Contains("Adriano"))
            {
                Console.WriteLine($"Employ Was Found :-) ");
            }
            else
            {
                Console.WriteLine("There Is No Employee found!\n");
            }
            Console.WriteLine("\n");

            Console.ReadKey();

        }



    }
}
