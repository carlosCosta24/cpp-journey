using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace ICollections_Interface
{
    public class clsUsingArray<T> : ICollection<T>
    {
        private T[] Elements = new T[] { };
        private int _Count = 0;
        public int Count => _Count;
        public int Capacity => Elements.Length;
        public bool IsReadOnly => false;

        void Resize(int NewCapacity)
        {
            if (NewCapacity < _Count) 
            {
                throw new ArgumentException("Can't Resize To Smaller Array");
            }
            if (NewCapacity < 0)
            {
                throw new ArgumentOutOfRangeException(nameof(NewCapacity),"Can't Resize To -Ve Capacity");
            }
            T[] NewArray = new T[NewCapacity];
            Array.Copy(Elements, NewArray, Elements.Length);
            Elements = NewArray;
        }
        public void Add(T NewElement)
        {
            if (_Count == Capacity) 
            {
                if (Capacity == 0)
                {
                    Resize(2);
                }
                else 
                {
                    Resize(Capacity * 2);
                }
            }
            Elements[_Count] = NewElement;

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
            if (ArrayIndex > array.Length) 
            {
                throw new ArgumentOutOfRangeException(nameof(ArrayIndex));
            }
            if (array == null) 
            {
                throw new  ArgumentNullException(nameof(array));
            }
            if (ArrayIndex < 0) 
            {
                throw new ArgumentOutOfRangeException(nameof(ArrayIndex));
            }
            if (_Count >  (array.Length - ArrayIndex))
            {
                throw new ArgumentException("Invalid Access (Out Of Range Access)!");
            }

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
