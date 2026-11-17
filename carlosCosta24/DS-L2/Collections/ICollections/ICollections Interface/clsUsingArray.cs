using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ICollections_Interface
{
    public class clsUsingArray<T> : ICollection<T>
    {
        private T [] Elements = new T[] { };

        public int Count => Elements.Length;
        public bool IsReadOnly => false;

        public void Add(T NewElement)
        {
            // Creating new array with size + 1
            T []  NewArray = new T[Elements.Length +1];
            Elements.CopyTo(NewArray, 0);
            NewArray[NewArray.Length - 1] = NewElement;
            Elements = NewArray;
        }
        public bool Remove(T Item)
        {
            if (Array.IndexOf(Elements,Item) != -1)
            {
                T [] Temporary = new T [Elements.Length -1];
                int TargetIndex = Array.IndexOf(Elements, Item);
                //If item is at the beginning of the array
                if (TargetIndex < 1) 
                {
                    Array.Copy(Elements, 1, Temporary, 0 , Temporary.Length);
                    
                }
                //if item in the end of the array
                if (TargetIndex == Elements.Length-1) 
                {
                    Array.Copy(Elements, 0, Temporary ,0 , Temporary.Length);

                }
                //if item in the middle of the array
                if (TargetIndex > 0 && TargetIndex < Elements.Length-1) 
                {
                    //Copy first portion
                    Array.Copy(Elements, 0, Temporary ,0 , Temporary.Length);
                    //copy second portion
                    Array.Copy(Elements, TargetIndex + 1, Temporary, 0, Temporary.Length);

                }
                    Elements = Temporary;

                return true;
            } 
            else 
            {
                return false;
            }
        }
        public void Clear()
        {
            Elements = new T[] { };
        }

        public bool Contains(T Target)
        {
            return Elements.Contains(Target);
        }


        public void CopyTo(T[] Array, int ArrayIndex)
        {
            Elements.CopyTo(Array, ArrayIndex);
        }

        public IEnumerator<T> GetEnumerator()
        {
            return ((IEnumerable<T>)Elements).GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
