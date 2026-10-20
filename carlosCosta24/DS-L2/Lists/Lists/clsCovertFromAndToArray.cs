using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Text;
using System.Threading.Tasks;

namespace Lists
{
    public class clsCovertFromAndToArray
    {
        List<int> NumberSet = new List<int> { 10, 20, 30, 40, 50, 60, 1, 2, 3, 55 };

        public void ListToArray()
        {
            int [] NumbersetArray = NumberSet.ToArray();

            Console.WriteLine("Converting List To Array And Print IT: \n");

            foreach (int N in NumbersetArray) 
            {
                Console.WriteLine($"Number{N}: " + N);   
            }
            //Useing List Methods
            Console.WriteLine("Array elements: " + string.Join(", ", NumbersetArray));
            Console.ReadKey();
        }
        public void ArrayToList() 
        {
            int [] NumbersetArray = NumberSet.ToArray();
            List<int> ListFromArray = new List<int>(NumbersetArray);
            Console.WriteLine("Printing List Item After Converting from Array: " + string.Join(", ", ListFromArray));
            Console.ReadKey();

        }
    }
}
