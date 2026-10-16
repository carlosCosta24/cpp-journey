using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lists
{
    public class clsIntro
    {
        public void Initialization() 
        {
            List<int> Ints = new List<int>();

            Ints.Add(10);
            Ints.Add(20);
            Ints.Add(30);

            Console.WriteLine("List Count: " + Ints.Count);
            Console.WriteLine("List Items: " + string.Join(", ", Ints));
            
            Console.WriteLine("Change the second item to 900");

            Ints[2] = 900;

            Console.WriteLine("3rd item: " + Ints[2]);

            Console.ReadKey();


        }
    }
}
