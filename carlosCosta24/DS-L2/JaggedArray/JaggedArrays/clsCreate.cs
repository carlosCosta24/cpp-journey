using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JaggedArrays
{
    public class clsCreate
    {
        public int[][] NewJaggedArray = new int [3][];

        public void Print() 
        {
            NewJaggedArray[0] = new int []{ 10, 20, 30};
            NewJaggedArray[1] = new int[] { 1, 50 };
            NewJaggedArray[2] = new int[] { 100, 202, 304 };

            for (int i = 0; i < NewJaggedArray.Length; i++) 
            {
                for (int j = 0; j < NewJaggedArray[i].Length; j++) 
                {
                    Console.WriteLine($"Item {j + 1} in Array Number {i + 1} is: {NewJaggedArray[i][j]}\n");
                }
            }

            Console.ReadKey();
        }
    }
}
