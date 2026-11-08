using System;
using System.Collections;
namespace BitArrays
{
    public class clsCreate
    {
        clsBitToString Converter = new clsBitToString();
        public BitArray Bits1 = new BitArray(5);

        public void Printer()
        {
            Console.WriteLine("\nBitArray 1: " + Converter.Convert(Bits1));
            Console.WriteLine("Print Bits1 As Bool: \n");
            for (int i = 0; i < Bits1.Length; i++)
            {
                bool Value = Bits1[i];
                Console.WriteLine($"Item {i}: {Value}");
            }
            Console.WriteLine("\n");
            //create bitarray from bool arr

            bool[] BoolanArray = { true, false, true, true, false };
            BitArray Bits2 = new BitArray(BoolanArray);
            Console.WriteLine("\nBitArray 2: " + Converter.Convert(Bits2));
            for (int i = 0; i < Bits2.Length; i++)
            {
                bool Value = Bits2[i];
                Console.WriteLine($"Item {i}: {Value}");
            }
            Console.WriteLine("\n");

            //create bitarray from byte array;
            byte[] ByteArray = { 0xff, 0x5b };
            BitArray ByteToBits = new BitArray(ByteArray);
            Console.WriteLine("\nByteToBits Array: " + Converter.Convert(ByteToBits));
            for (int i = 0; i < ByteToBits.Length; i++)
            {
                bool Value = ByteToBits[i];
                Console.WriteLine($"Item {i}: {Value}");
            }
            Console.WriteLine("\n");

            //basic operations on bitarray
            Bits1.Set(4, true);
            Bits1[4] = true;
            Console.WriteLine("\n Bits1 Array after modificatino: " + Converter.Convert(Bits1));
            for (int i = 0; i < Bits1.Length; i++)
            {
                bool Value = Bits1[i];
                Console.WriteLine($"Item {i}: {Value}");
            }
            Console.WriteLine("\n");

            Console.WriteLine("Set all values of Bits1 array to true: ");
            Bits1.SetAll(true);
            for (int i = 0; i < Bits1.Length; i++)
            {
                bool Value = Bits1[i];
                Console.WriteLine($"Item {i}: {Value}");
            }
            Console.WriteLine("\n");
            bool boolValue = Bits1[2];
            Console.WriteLine($"Value of item 3 in Bits1 Array: {boolValue}");
            int Bits1Lenght = Bits1.Length;
            Console.WriteLine($"Length of Bits1 Array: {Bits1Lenght}");


            Console.ReadKey();
        }

    }
}
