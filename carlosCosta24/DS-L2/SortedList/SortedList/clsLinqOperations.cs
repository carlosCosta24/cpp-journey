using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortedSet
{
    public class clsLinqOperations
    {
        public class clsPerson 
        {
            public int ID { get; set; }
            public string Name { get; set; }
            public string Department {  get; set; }

            public clsPerson(int ID, string Name, string Department) 
            {
                this.ID = ID;
                this.Name = Name;
                this.Department = Department;
            }
        }
        public SortedList<int, clsPerson> Employees = new SortedList<int, clsPerson>
        {
            {1, new clsPerson(1, "Carlos", "Engineering") },
            {2, new clsPerson(1, "Max", "Engineering") },
            {3, new clsPerson(1, "Aloha", "HR") },
            {4, new clsPerson(1, "Brona", "Desinging") },
            {5, new clsPerson(1, "Alex", "IT") },
            {6, new clsPerson(1, "Jerry", "Finance") },
            {7, new clsPerson(1, "Tom", "Finance") },
            {8, new clsPerson(1, "Danial", "Markting") }


        };
        public SortedList<string, int> FruitBasket = new SortedList<string, int> 
        {
            {"Apple", 5 },
            {"Mango", 2 },
            {"Banana", 10 },
            {"Grape", 50 }
        };

        public void OperationResult()
        {

            var Query = from kpv in FruitBasket
                        where kpv.Value > 5 select kpv;
            Console.WriteLine("Query Result: \n");

            foreach (var item in Query)
            {
                Console.WriteLine($"Name: {item.Key}, Count: {item.Value}");
            }

            Console.WriteLine("\n");
            Console.WriteLine("Query Result Using Where Statement: \n");

            var LeastAvailable = FruitBasket.Where(Kvp => Kvp.Value < 5);
            foreach (var item in LeastAvailable)
            {
                Console.WriteLine($"Name: {item.Key}, Count: {item.Value}");
            }

            Console.WriteLine("\n");
            Console.WriteLine("Query Result Using Specific value Statement: \n");
            int MostAvailable = 30;
            var Result = FruitBasket.Where(Kvp => Kvp.Value > MostAvailable);
            foreach (var item in Result)
            {
                Console.WriteLine($"Name: {item.Key} , Count:  {item.Value}");
            }

            //grouping 
            Console.WriteLine("\n");
            Console.WriteLine("Group of fruits with long names: ");
            var FruitWithLongNames = FruitBasket.GroupBy(Kpv => Kpv.Key.Length > 5);
            foreach (var Category in FruitWithLongNames)
            {
                Console.WriteLine(Category.Key ? "Long Names: " : "Short Names: ");  
                foreach (var Item in Category) 
                {
                    Console.WriteLine($"\t{Item.Key}");

                }

            }


            Console.ReadKey();

        }
        public void HetroSortedListOperation() 
        {
            var EngineeringTeam = Employees.
            Where(Kvp => Kvp.Value.Department == "Engineering")
            .OrderBy(Kpv => Kpv.Key)
            .Select(Kpv => Kpv.Value.Name);

            Console.WriteLine("Engineering Team: \n");
            foreach (var Item in EngineeringTeam) 
            {
                Console.WriteLine($"Name: {Item}");
            }
        }
    }
}
