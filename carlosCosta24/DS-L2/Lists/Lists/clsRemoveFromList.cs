using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lists
{
    public class clsRemoveFromList
    {

        public void RemoveFuncs() 
        {
            List<int> Operations = new List<int> { 90,80,50,78,45,12};

            Console.WriteLine("Initial List: " + string.Join(", ", Operations));

            // Remove from list by value
            Operations.Remove(78);
            Console.WriteLine("Remove 78 from list: " + string.Join(", ", Operations));

            // Remove from list by index
            Operations.RemoveAt(1);
            Console.WriteLine("Remove 80 from list: " + string.Join(", ", Operations));

            //Remove even numbers
            Operations.RemoveAll(n => n % 2 == 0);
            Console.WriteLine("Remove even numbers from list: " + string.Join(", ", Operations));

            //Clear list items
            Operations.Clear();
            Console.WriteLine("Clearing all list numbers: " +  Operations.Count);

            Console.ReadKey();

        }
    }
}
