using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayLists
{
    public class clsFiltering
    {
        public ArrayList arrayList = new ArrayList { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        public void OddNumbers()
        {
            var OddNumbers = arrayList.Cast<int>().Where(E => E % 2 != 0);
            Console.WriteLine("Print odd numbers in the ArrayList: \n");

            foreach(var e in OddNumbers)
            {
                Console.WriteLine(e);
            }
            Console.ReadKey();
        }

    }
}
