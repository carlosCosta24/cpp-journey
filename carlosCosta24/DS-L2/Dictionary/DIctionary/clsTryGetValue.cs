using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DIctionary
{
    public class clsTryGetValue
    {

        Dictionary<int, string> Fruits = new Dictionary<int, string>
            {
                { 1, "Apple"},
                { 2, "Orange"},
                { 3, "PineApple"},
                { 4, "kwie"},
                { 5, "WaterMelon"},
                { 6, "Grape"},

            };

        public void HandelException() 
        {
            Console.WriteLine("Print dictionary items: \n");
            foreach (KeyValuePair<int, string> Item in Fruits)
            {
                Console.WriteLine($"Key: {Item.Key}, Item: {Item.Value}");
            }

            Console.WriteLine("Get value of item using TryGetValue fun: \n");

            bool IsGrapeExist = Fruits.TryGetValue(6, out string FruitName);
            if (IsGrapeExist) 
            {
                Console.WriteLine($"Fruit was found, Fruit name: {FruitName}");
            }else
            {
                Console.WriteLine($"Fruit not found! {FruitName}");

            }

            Console.WriteLine("Get value of item not in the dictionary: \n");
            if (Fruits.TryGetValue(10, out string NotFound))
            {
                Console.WriteLine($"Fruit was found, Fruit name: {NotFound}");
            }
            else
            {
                Console.WriteLine($"Fruit not found! {NotFound}");

            }
            Console.ReadKey();
        }
    }
}
