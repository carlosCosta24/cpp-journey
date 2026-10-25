using System;
using System.Collections.Generic;
using System.Linq;

namespace DIctionary
{
    public class clsDictionaryWithLinq
    {
        public Dictionary<string, double> Students = new Dictionary<string, double>
        {
            { "Carlos", 3.5},
            {"Aloha", 3.9 },
            {"Yasmim", 2.5 }

        };

        public void OperationWitLinq() 
        {
            //Iterate through the dictionary 
            Console.WriteLine("Print Dictionary Items: \n");
            var StudentsList = Students.Select(Kpv => new { Kpv.Key, Kpv.Value});
            foreach(var S in StudentsList)
            {
                Console.WriteLine($"Student Name: {S.Key}, GPA: {S.Value}");
            }
            Console.WriteLine("\n");
            //Filter base on GPA
            Console.WriteLine("Print All Students with GPA higher than 3.4: \n");
            var TopStudens = Students.Where(Kpv => Kpv.Value > 3.4);
            foreach (var S in TopStudens)
            {
                Console.WriteLine($"Student Name: {S.Key}, GPA: {S.Value}");
            }
            Console.WriteLine("\n");
            //Order student asc
            Console.WriteLine("Print All Students ascending: \n");
            var OrderdStudentDictionary = Students.OrderBy(Kvp => Kvp.Key);
            foreach (var S in OrderdStudentDictionary)
            {
                Console.WriteLine($"Student Name: {S.Key}, GPA: {S.Value}");
            }
            Console.WriteLine("\n");
            //order students decs
            Console.WriteLine("Print All Students Descending: \n");
            var DescOrderdStudentDictionary = Students.OrderByDescending(Kvp => Kvp.Key);
            foreach (var S in DescOrderdStudentDictionary)
            {
                Console.WriteLine($"Student Name: {S.Key}, GPA: {S.Value}");
            }
            Console.WriteLine("\n");
            //Get sum of all student gpa and then get the avg

            var SumOfGPA = Students.Sum(Kpv => Kpv.Value);
            double Avg = SumOfGPA / Students.Count;

            Console.WriteLine("Print The Sum And The Average Of Students GPAS: \n");
            Console.WriteLine($"Students GPA Sum: {SumOfGPA}, Average of GPA: {Avg}");

            Console.ReadKey();

        }
    }
}
