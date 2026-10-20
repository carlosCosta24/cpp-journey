using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DIctionary
{
    public class clsDefinition
    {
        public void StartDictionary() 
        {
            Dictionary<int, string> Fruits = new Dictionary<int, string>
            {
                { 1, "Apple"},
                { 2, "Orange"},
                { 3, "PinApple"},
                { 4, "kwie"},
                { 5, "WaterMelon"},
                { 6, "Grap"},

            };
            Console.WriteLine("Printing Dictionary Items: \n");
            foreach (KeyValuePair<int, string> Item in Fruits)
            {
                Console.WriteLine($"Key: {Item.Key}, Item: {Item.Value}");
            }

            Console.WriteLine("Update Item Number 3 to Banana: \n");
            Fruits[3] = "Banana";
            foreach (KeyValuePair<int, string> Item in Fruits) 
            {
                Console.WriteLine($"Key: {Item.Key}, Item: {Item.Value}");
            }

            Console.WriteLine("Removing Grap From Dictionary: \n");
            Fruits.Remove(6);
            foreach (KeyValuePair<int, string> Item in Fruits)
            {
                Console.WriteLine($"Key: {Item.Key}, Item: {Item.Value}");
            }

            Console.ReadKey();
        }
    }
}
