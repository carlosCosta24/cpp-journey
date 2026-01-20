using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Byte 
            Console.WriteLine("\nByte: ");
            Console.WriteLine("Min{0} , Max{1}", sbyte.MinValue, sbyte.MaxValue);

           
            Console.WriteLine("\nSByte: ");
            Console.WriteLine("Min{0} , Max{1}", sbyte.MinValue, sbyte.MaxValue);

         
            Console.WriteLine("\nShort: ");
            Console.WriteLine("Min{0} , Max{1}", Int16.MinValue, Int16.MaxValue);

           
            Console.WriteLine("\nuShort: ");
            Console.WriteLine("Min{0} , Max{1}", Int16.MinValue, Int16.MaxValue);

            Console.WriteLine("\nInt: ");
            Console.WriteLine("Min{0} , Max{1}", Int32.MinValue, Int32.MaxValue);

            Console.WriteLine("\nuInt: ");
            Console.WriteLine("Min{0} , Max{1}", Int32.MinValue, Int32.MaxValue);

            Console.WriteLine("\nLong: ");
            // prefix ul
            Console.WriteLine("Min{0} , Max{1}", Int64.MinValue, Int64.MaxValue);

            Console.WriteLine("\nuLong: ");
            Console.WriteLine("Min{0} , Max{1}", Int64.MinValue, Int64.MaxValue);

            //prefix f
            Console.WriteLine("\nfloat: ");
            Console.WriteLine("Min{0} , Max{1}", float.MinValue, float.MaxValue);

            //prefix d
            Console.WriteLine("\ndouble: ");
            Console.WriteLine("Min{0} , Max{1}", double.MinValue, double.MaxValue);

            //prefix m
            Console.WriteLine("\nDecimal: ");
            Console.WriteLine("Min{0} , Max{1}", decimal.MinValue, decimal.MaxValue);

            //scientific note

            double d = 12e2;
            Console.WriteLine(d);

            // hex & bin
            int hex = 0x25f;
            Console.WriteLine($"Hex {hex}");

            int binary = 0b_0010_0110;
            Console.WriteLine($"binary {binary}");
            Console.ReadKey();


        }
    }
}
