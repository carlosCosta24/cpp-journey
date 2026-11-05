using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arrays
{
    public class clsCreate
    {
        public int[] NumbersArray = new int[5];
        public string [] NamesArray = new string[5];

        public void ArraysInfoPrinter() 
        {
            NumbersArray[0] = 0;
            NumbersArray[1] = 10;
            NumbersArray[2] = 20;
            NumbersArray[3] = 30;
            NumbersArray[4] = 40;

            NamesArray[0] = "Carlos";
            NamesArray[1] = "Ricardo";
            NamesArray[2] = "Aloha";
            NamesArray[3] = "Koda";
            NamesArray[4] = "Yasmin";

            Console.WriteLine("Printing Numbers Array: \n");
            for (int i = 0; i < NumbersArray.Length; i++) 
            {
                Console.WriteLine($"Element At Index: {i}: {NumbersArray[i]}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Printing Names Array: \n");
            for (int i = 0; i < NamesArray.Length; i++)
            {
                Console.WriteLine($"Element At Index: {i}: {NamesArray[i]}");
            }
            Console.WriteLine("\n");

            Console.ReadKey();
        }
        public void Operations()
        {
            Console.WriteLine("Modifing Number Array: ");
            NumbersArray[0] = 500;
            Console.WriteLine("Printing Numbers Array: \n");
            for (int i = 0; i < NumbersArray.Length; i++)
            {
                Console.WriteLine($"Element At Index: {i}: {NumbersArray[i]}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Sorting Names Array: ");
            Array.Sort(NamesArray);
            Console.WriteLine("Printing Names Array: \n");
            for (int i = 0; i < NamesArray.Length; i++)
            {
                Console.WriteLine($"Element At Index: {i}: {NamesArray[i]}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Getting Index Of Koda in Names Array: ");
            Console.WriteLine($"{Array.IndexOf(NamesArray, "Koda")}");

            Console.ReadKey();

        }
        public void CopyingOperation() 
        {
            int[] Copy = new int[5];

            Array.Copy(NumbersArray, Copy, NumbersArray.Length);

            Console.WriteLine("Copying Number Array Into New Array: ");
            Console.WriteLine("Printing Copied Array: \n");
            for (int i = 0; i < Copy.Length; i++)
            {
                Console.WriteLine($"Element At Index: {i}: {Copy[i]}");
            }
            Console.WriteLine("\n");

            Console.ReadKey();
        }
    }
}
