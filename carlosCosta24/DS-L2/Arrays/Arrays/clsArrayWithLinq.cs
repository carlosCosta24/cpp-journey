using System;
using System.Linq;

namespace Arrays
{
    public class clsArrayWithLinq
    {
        public int[] numbers = { 1, 2, 3, 4, 5 };
        public class clspeople
        {
            public string Name { set; get; }
            public int Age { set; get; }

            public clspeople(string name, int age)
            {
                Name = name;
                Age = age;
            }
        }
        public clspeople[] peopleArray = new[]
            {
            new clspeople ("Alice", 30 ),
            new clspeople ("Mark", 20 ),
            new clspeople ("Aloha", 30 ),
            new clspeople ("Max", 30 ),
            new clspeople ("Karmen", 28 ),
            new clspeople ("Ricardo", 20 )


        };

        public void FilterWithLinq()
        {
            Console.WriteLine("Print Numbers Array: \n");
            foreach (int i in numbers)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine("Select Odd Numbers and Square Them: ");

            var OddSquare = numbers.Where(i => i % 2 != 0).Select(i => i * i);
            foreach (int i in OddSquare)
            {
                Console.WriteLine(i);
            }
            Console.ReadKey();
        }
        public void Grouping()
        {
            Console.WriteLine("Print People Array: \n");
            foreach (clspeople O in peopleArray)
            {
                Console.WriteLine($"Person Name: {O.Name}, Person Age {O.Age}");
            }

            Console.WriteLine("\n");
            Console.WriteLine("Grouping By Age: \n");

            var AgeGroup = peopleArray
            .GroupBy(p => p.Age)
            .Select(G => new { Age = G.Key, p = G.OrderBy(i => i.Name) });

            foreach (var Group in AgeGroup)
            {

                Console.WriteLine($"Age Group: {Group.Age}");
                foreach (var Item in Group.p)
                {
                    Console.WriteLine($"\t-{Item.Name}");

                }
            }
            Console.ReadKey();
        }
        public void Aggregation()
        {
            Console.WriteLine("Print Numbers Array: \n");
            foreach (int i in numbers)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine("\n");

            var OddNumbers = numbers.Where(n => n % 2 != 0);
            int SumOfOddNumbers = OddNumbers.Sum();
            Console.WriteLine("Print Odd Numbers Array: \n");
            foreach (int i in OddNumbers)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine("\n");

            Console.WriteLine($"Sum Of OddNumbers Arrays: {SumOfOddNumbers}");

            Console.ReadKey();

        }
        public void JoiningOperation()
        {
            var Employee = new[]
            {
                new { Id = 1, Name = "Alice", DepartmentId = 2 },
                new { Id = 2, Name = "Bob", DepartmentId = 1 }
            };

            var Departments = new[]
            {
                new { Id = 1, Name = "Human Resources" },
                new { Id = 2, Name = "Development" }
            };

            Console.WriteLine("Print Employees Array: \n");
            foreach (var i in Employee)
            {
                Console.WriteLine($"ID: {i.Id}, Name: {i.Name}");
            }
            Console.WriteLine("\n");
            Console.WriteLine("Print Departments Array: \n");
            foreach (var i in Departments)
            {
                Console.WriteLine($"ID: {i.Id}, Name: {i.Name}");

            }
            Console.WriteLine("\n");

            var EmployeeData = Employee
            .Join(Departments, e => e.DepartmentId, 
            d => d.Id, 
            (e, d) => new { e.Name, Departments = d.Name });

            Console.WriteLine("Printing Joinned Array: \n");

            foreach (var Item in EmployeeData) 
            {
                Console.WriteLine($"Employee: {Item.Name}, Department: {Item.Departments}");
            }
            Console.ReadKey();
        }
    }
}
