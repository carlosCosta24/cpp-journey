using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BitArrays
{
    public class clsBitOperation
    {
        //create twe bitarrays
        public BitArray BitArray1 = new BitArray(new bool[] { true, false, true, false });
        public BitArray BitArray2 = new BitArray(new bool[] { true, true, true, false });

        public clsBitToString Converter = new clsBitToString();
        public void OperatoinsOnArrays() 
        {
            Console.WriteLine("First BitArray: " + Converter.Convert(BitArray1));
            Console.WriteLine("Second BitArray: " + Converter.Convert(BitArray1));
            Console.WriteLine("\n");

            Console.WriteLine("And Operations: \n");
            BitArray AndArray = new BitArray(BitArray1);
            AndArray.And(BitArray2);
            Console.WriteLine("First BitArray: " + Converter.Convert(BitArray1));
            Console.WriteLine("Second BitArray: " + Converter.Convert(BitArray2));
            Console.WriteLine("---------------------");
            Console.WriteLine("Result: " + Converter.Convert(AndArray));
            Console.WriteLine("\n");

            Console.WriteLine("Or Operations: \n");
            BitArray OrArray = new BitArray(BitArray1);
            OrArray.Or(BitArray2);
            Console.WriteLine("First BitArray: " + Converter.Convert(BitArray1));
            Console.WriteLine("Second BitArray: " + Converter.Convert(BitArray2));
            Console.WriteLine("---------------------");
            Console.WriteLine("Result: " + Converter.Convert(OrArray));
            Console.WriteLine("\n");

            Console.WriteLine("Not Operations: \n");
            BitArray NotArray1 = new BitArray(BitArray1);
            BitArray NotArray2 = new BitArray(BitArray2);
            NotArray1.Not();
            NotArray2.Not();
            Console.WriteLine("First BitArray: " + Converter.Convert(BitArray1));
            Console.WriteLine("---------------------");
            Console.WriteLine("Result: " + Converter.Convert(NotArray1));
            Console.WriteLine("\n");
            Console.WriteLine("Second BitArray: " + Converter.Convert(BitArray2));
            Console.WriteLine("---------------------");
            Console.WriteLine("Result: " + Converter.Convert(NotArray2));
            Console.WriteLine("\n");

            Console.WriteLine("Xor Operations: \n");
            BitArray XorArray = new BitArray(BitArray1);
            XorArray.Xor(BitArray2);
            Console.WriteLine("First BitArray: " + Converter.Convert(BitArray1));
            Console.WriteLine("Second BitArray: " + Converter.Convert(BitArray2));
            Console.WriteLine("---------------------");
            Console.WriteLine("Result: " + Converter.Convert(XorArray));
            Console.WriteLine("\n");

            Console.ReadKey();
        }

    }
}
