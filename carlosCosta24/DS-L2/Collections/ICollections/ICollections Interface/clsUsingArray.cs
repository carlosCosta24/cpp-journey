using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace ICollections_Interface
{
    public class clsUsingArray<T> : ICollection<T>
    {
        private T[] Elements = new T[] { };
        private int _Count = 0;
        public int Count => _Count;
        public int Capacity => Elements.Length;
        public bool IsReadOnly => false;

        public void Add(T NewElement)
        {
            
            T[] NewArray = new T[_Count + 1];
            Elements.CopyTo(NewArray, 0);
            NewArray[_Count] = NewElement;
            Elements = NewArray;

            _Count++;
        }
        public bool Remove(T Item)
        {
            int TargetIndex = Array.IndexOf(Elements, Item);
            if (TargetIndex != -1)
            {
                T[] Temporary = new T[_Count - 1];
                //Copy first portion
                Array.Copy(Elements, 0, Temporary, 0, TargetIndex);
                //copy second portion
                Array.Copy(Elements, TargetIndex + 1, Temporary, TargetIndex, Elements.Length - TargetIndex - 1);


                Elements = Temporary;

                _Count--;
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
            _Count = 0;
        }

        public bool Contains(T Target)
        {
            return Elements.Contains(Target);
        }

        public void CopyTo(T[] array, int ArrayIndex)
        {

            Elements.CopyTo(array, ArrayIndex);
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
