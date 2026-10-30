using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortedSet
{
    public class clsLinqOperations
    {
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

            Console.ReadKey();

        }
    }
}
