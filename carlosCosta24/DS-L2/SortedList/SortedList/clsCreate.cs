using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortedSet
{
    public class clsCreate
    {
        SortedList<string, int> FruitBasket = new SortedList<string, int>();

        public void Operation()
        {
            FruitBasket.Add("Apple", 5);
            FruitBasket.Add("Mango", 2);
            FruitBasket.Add("Banana", 10);
            FruitBasket.Add("Grape", 50);

            Console.WriteLine("Print SortedList Items: \n");

            foreach (var item in FruitBasket) 
            {
                Console.WriteLine($"Fruit name: {item.Key}, Quantity: {item.Value}");
            }

            Console.WriteLine("\n");

            Console.WriteLine($"Quantity of banana: {FruitBasket["Banana"]}\n");

            Console.WriteLine($"List after removing grape: \n");
            FruitBasket.Remove("Grape");

            foreach (var item in FruitBasket)
            {
                Console.WriteLine($"Fruit name: {item.Key}, Quantity: {item.Value}");
            }

            Console.ReadKey();
        }


    }
    }
