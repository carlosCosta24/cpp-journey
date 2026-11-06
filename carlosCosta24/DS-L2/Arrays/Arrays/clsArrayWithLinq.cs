using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arrays
{
    public  class clsArrayWithLinq
    {
        public int[] numbers = { 1, 2, 3, 4, 5 };

        public void FilterWithLinq() 
        {
            Console.WriteLine("Print Numbers Array: \n");
            foreach (int i in numbers) 
            {
                Console.WriteLine(i);
            }
            Console.WriteLine("Select Odd Numbers and Square Them: ");

            var OddSquare = numbers.Where(i => i % 2 != 0).Select(i => i * i);
            foreach (int i in OddSquare)
            {
                Console.WriteLine(i);
            }
            Console.ReadKey();
        }
    }
}
