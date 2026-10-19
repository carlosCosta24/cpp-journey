using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lists
{
    public class clsCustomObjects
    {
        public class clsStudent 
        {
            public int ID;
            public string Name;
            public int Age;
            public double GPA;

            public clsStudent(int ID, string Name, int Age, double GPA)
            {
                this.ID = ID;
                this.Name = Name;
                this.Age = Age;
                this.GPA = GPA;
            }
        }

        public void OperationOnListOfObjects() 
        {
            List<clsStudent> ClassList = new List<clsStudent>
            {
                new clsStudent(1,"Carlos", 20 ,3.5),
                new clsStudent(2,"Aloha", 22  ,3.4),
                new clsStudent(3,"Mark", 21 ,3.8),
                new clsStudent(4,"Daived", 22 ,3.9),
                new clsStudent(5,"Max", 20 ,3.3),
                new clsStudent(6,"Eduardo ", 20 ,3.1)

            };

            //iteration over the list
            Console.WriteLine("Print List Items: \n");
            foreach (clsStudent S in ClassList) 
            {
                Console.WriteLine($"ID: {S.ID}, Name: {S.Name}, GPA: {S.GPA}\n");
            }

            //find student named Daived
            Console.WriteLine("Find Student With Name Daived And Print His Info: \n");
            clsStudent Daived = ClassList.Find(S => S.Name == "Daived");
            if (Daived != null) 
            {
                Console.WriteLine($"{Daived.ID}, {Daived.Name}, {Daived.GPA}\n");
            }

            //find and update 
            Console.WriteLine("Find Student With Name Aloha, Update Her GPA, And Print Her Info: \n");
            clsStudent Aloha = ClassList.Find(S => S.Name == "Aloha");
            if (Aloha != null) 
            {
                Aloha.GPA = 3.9;
                Console.WriteLine($"{Aloha.ID}, {Aloha.Name}, {Aloha.GPA}\n");
            }

            //find all Student with GPA Higher than 3.5
            Console.WriteLine("Top Class Students: \n");
            List<clsStudent> Eliet = ClassList.FindAll(S => S.GPA > 3.5);
            foreach(clsStudent S in Eliet)
            {
                Console.WriteLine($"{S.ID}, {S.Name}, {S.GPA}\n");
            }

            //check if any one have name max
            Console.WriteLine("Is There Is Any Student With Name Max In The Class: ");
            bool Max = ClassList.Any(S => S.Name == "Max");
            if (Max) 
            {
                Console.WriteLine("Max exist\n");
            }

            //check if any one is older than 21 in the class using exist
            Console.WriteLine("Is There Is Any Student Older Than 21 In The Class: ");
            bool Older = ClassList.Exists(S => S.Age > 21);
            if (Older)
            {
                Console.WriteLine("There Is Student/s Older Than 21.\n");
            }

            //remove all student with gpa < 3.5
            Console.WriteLine("Remove All Students With GPA < 3.5: \n");
            ClassList.RemoveAll(S => S.GPA < 3.5);
            foreach(clsStudent S in ClassList)
            {
                Console.WriteLine($"{S.ID}, {S.Name}, {S.GPA}\n");
            }

            Console.WriteLine("Current State Of List: \n");
            foreach (clsStudent S in ClassList) 
            {
                Console.WriteLine($"{S.ID}, {S.Name}, {S.GPA}\n");

            }

            Console.ReadKey();
        }
    }
}
