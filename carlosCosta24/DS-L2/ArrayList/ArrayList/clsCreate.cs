using System;
using System.Collections;
using System.Linq;

namespace ArrayLists
{
    public class clsCreate
    {
        public ArrayList NumberList = new ArrayList();

        public void OperationOnList() 
        {
            NumberList.Add(10);
            NumberList.Add(20);
            NumberList.Add(30);
            NumberList.Add(50);
            NumberList.Add(80);

            Console.WriteLine("Elements in ArrayList: \n");
            foreach (var Element in NumberList) 
            {
                Console.WriteLine(Element);
            }
            Console.WriteLine("\n");

            Console.WriteLine("Removing 20 from ArrayList: \n");
            NumberList.Remove(20);
            foreach (var Element in NumberList)
            {
                Console.WriteLine(Element);
            }
            Console.WriteLine("\n");

            Console.WriteLine("Adding different data type: \n");
            NumberList.Add("Hello");
            NumberList.Add("Carlos");
            NumberList.Add(true);
            NumberList.Add(3.5);

            foreach (var Element in NumberList)
            {
                Console.WriteLine(Element);
            }

            Console.WriteLine("Getting total count of elements: \n");
            Console.WriteLine(NumberList.Count);
            Console.WriteLine("\n");

            Console.WriteLine("Print numberred list items: \n");

            for (int i = 0; i < NumberList.Count; i++) 
            {
                Console.WriteLine($"Number {i}: List item: {NumberList[i]}");
            }
            Console.ReadKey();
        }
    }
}
