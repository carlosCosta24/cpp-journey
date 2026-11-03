using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayLists
{
    public class clsAggregate
    {
        public ArrayList arrayList = new ArrayList { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,11,15,20 };

        public void AggregateFun() 
        {
            var Min = arrayList.Cast<int>().Min();
            var Max = arrayList.Cast<int>().Max();
            var Sum = arrayList.Cast<int>().Sum();
            var Average = arrayList.Cast<int>().Average();
            var Count = arrayList.Cast<int>().Count();

            Console.WriteLine("Printing ArrayList Items: \n");
            for (int i = 0; i < arrayList.Count; i++) 
            {
                Console.WriteLine(arrayList[i]);
            }

            Console.WriteLine("\n");
            Console.WriteLine($"ArrayList Max: {Max}");
            Console.WriteLine($"ArrayList Min: {Min}");
            Console.WriteLine($"ArrayList Sum: {Sum}");
            Console.WriteLine($"ArrayList Average: {Average}");
            Console.WriteLine($"ArrayList Count: {Count}");


            Console.WriteLine("Sorted ArrayList: ");
            arrayList.Sort();
            for (int i = 0; i < arrayList.Count; i++)
            {
                Console.WriteLine(arrayList[i]);
            }
            Console.WriteLine("\n");

            Console.WriteLine("Count Occurrences Of Number 11: ");
            int Target = 11;
            var Occurrences = arrayList.Cast<int>().Count(n => n == Target);
            Console.WriteLine(Occurrences);


            Console.ReadKey();


        }

    }
}
