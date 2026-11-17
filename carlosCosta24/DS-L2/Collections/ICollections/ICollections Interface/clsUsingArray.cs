using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace ICollections_Interface
{
    public class clsUsingArray<T> : ICollection<T>
    {
        private T[] Elements = new T[] { };

        public int Count => Elements.Length;
        public bool IsReadOnly => false;

        public void Add(T NewElement)
        {
            // Creating new array with size + 1
            T[] NewArray = new T[Elements.Length + 1];
            Elements.CopyTo(NewArray, 0);
            NewArray[NewArray.Length - 1] = NewElement;
            Elements = NewArray;
        }
        public bool Remove(T Item)
        {
            int TargetIndex = Array.IndexOf(Elements, Item);
            if (TargetIndex != -1)
            {
                T[] Temporary = new T[Elements.Length - 1];
                //Copy first portion
                Array.Copy(Elements, 0, Temporary, 0, TargetIndex);
                //copy second portion
                Array.Copy(Elements, TargetIndex + 1, Temporary, TargetIndex, Elements.Length - TargetIndex - 1);


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
