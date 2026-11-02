using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortedDictionary
{
    internal class Program
    {
        static void Main(string[] args)
        {
            SortedDictionary<string,int> DepartmentEmployees = new SortedDictionary<string,int>();

            DepartmentEmployees.Add("Marketing", 3);
            DepartmentEmployees.Add("HR", 5);
            DepartmentEmployees.Add("IT", 3);
            DepartmentEmployees.Add("Finance", 3);
            DepartmentEmployees.Add("Engineering", 10);
            DepartmentEmployees.Add("Logistics", 3);

            Console.WriteLine("Sorted Dictionary Items: \n");
            foreach (var Item in DepartmentEmployees) 
            {
                Console.WriteLine($"Department: {Item.Key}, Employees: {Item.Value}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Get Number Of Employees In Marketing Department: ");
            Console.WriteLine($"{DepartmentEmployees["Marketing"]}");
            Console.WriteLine("\n");

            Console.WriteLine("Check If Departments Contain Finance? : ");
            Console.WriteLine
            (
                DepartmentEmployees.ContainsKey("Finance")
                ? "Yes, Finance Exist"
                : "There Is No Finance Department"
            );
            Console.WriteLine("\n");

            Console.WriteLine("Sorted Dictionary After Removing Finance: \n");
            DepartmentEmployees.Remove("Finance");
            foreach (var Item in DepartmentEmployees)
            {
                Console.WriteLine($"Department: {Item.Key}, Employees: {Item.Value}");
            }
            Console.ReadKey();

        }
    }
}
