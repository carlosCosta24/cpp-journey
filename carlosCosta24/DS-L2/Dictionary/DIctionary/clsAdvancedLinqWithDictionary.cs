using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DIctionary
{
    public class clsAdvancedLinqWithDictionary
    {
        public Dictionary<string, string> Students = new Dictionary<string, string>
        {
            { "Carlos", "Bio"},
            {"Aloha", "Chims" },
            {"Yasmim", "Law" },
            {"Costa", "Bio" },
            {"Danial", "Enginering" },
            {"Adriano", "IT" }


        };

        public void AdvancedOperations() 
        {

            Console.WriteLine("Printing Dictionary Items: \n");
            var DictionaryItems = Students.Select(Kpv => new { Kpv.Key, Kpv.Value });
            foreach (var S in DictionaryItems)
            {
                Console.WriteLine($"Student Name: {S.Key}, Department: {S.Value}");

            }
            Console.WriteLine("\n");


            Console.WriteLine("Printing Grouped Dictionary Departments: \n");
            var GroupByDepartments = Students.GroupBy(Kpv => Kpv.Value);
            foreach (var S in GroupByDepartments) 
            {
                Console.WriteLine($"Department: {S.Key}");

            }
            Console.WriteLine("\n");

            Console.WriteLine("Printing Query Items: \n");
            var Query = Students
            .Where(Kpv => Kpv.Value == "Bio")
            .OrderBy(Kpv => Kpv.Key)
            .Select(Kpv => new { Kpv.Key, Kpv.Value });
            foreach (var I in Query)
            {
                Console.WriteLine($"Student Name: {I.Key}, Department: {I.Value}");

            }
            Console.WriteLine("\n");

            Console.ReadKey();
        }

    }
}
