using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program

    {
        static void Main(string[] args)
        {

            // anonymous types, are read only, can include another anonymous type
            var student = new { Id = 1, 
                FirstName = "carlos", 
                LastName = "costa" ,
                Address = new {
                    City = "Aracaju",
                    Country = "Brazil",
                }
            };
            Console.WriteLine("\nExample: ");
            Console.WriteLine($"Id: {student.Id}");
            Console.WriteLine($"First Name: {student.FirstName}");
            Console.WriteLine($"LastName: {student.LastName}");
            Console.WriteLine($"city: {student.Address.City}");
            Console.WriteLine($"Country: {student.Address.Country}");
            Console.WriteLine(student);


            Console.ReadKey();


        }
    }
}
