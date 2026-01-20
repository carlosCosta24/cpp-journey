using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program { 
        //structures

        struct stStudent
        {
            public string FirstName;
            public string LastName;
        }

        static void Main(string[] args)
        {

        // Creating struct
        stStudent Student;

        Student.FirstName = "Carlos";
        Student.LastName = "Costa";
 
            Console.WriteLine("\nExample: ");

            Console.WriteLine(Student.FirstName);
            Console.WriteLine(Student.LastName);


     

            Console.ReadKey();


        }
    }
}
