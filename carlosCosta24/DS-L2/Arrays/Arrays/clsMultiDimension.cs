using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Arrays
{
    public class clsMultiDimension
    {
        public int[,] Matrix1 = { { 1, 2, 3 }, { 2, 4, 6 } };
        public int[,] Matrix2 = { { 2, 3, 4 }, { 4, 6, 8 } };

        public void MatrixPrinter() 
        {
            Console.WriteLine("Print Matrix 1 Elements: \n");

            for (int i = 0; i < Matrix1.GetLength(0); i++) 
            {
                for (int j = 0; j < Matrix1.GetLength(1); j++) 
                {
                    Console.WriteLine($"Item: {Matrix1[i, j]}");
                }
            }

            Console.WriteLine("Print Matrix 2 Elements: \n");

            for (int i = 0; i < Matrix2.GetLength(0); i++)
            {
                for (int j = 0; j < Matrix2.GetLength(1); j++)
                {
                    Console.WriteLine($"Item: {Matrix2[i, j]}");
                }
            }
            Console.ReadKey();
        }
    }
}
