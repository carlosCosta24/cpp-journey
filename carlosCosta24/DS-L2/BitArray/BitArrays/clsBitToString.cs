using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BitArrays
{
    public class clsBitToString
    {

        public string Convert(BitArray Array) 
        {
            char[] Bits = new char[Array.Length];
            for (int i =0; i < Array.Length; i++) 
            {
               
                 Bits[i] = Array[i] ? '1' : '0';
                
            }
            return new string(Bits);
        }
    }
}
