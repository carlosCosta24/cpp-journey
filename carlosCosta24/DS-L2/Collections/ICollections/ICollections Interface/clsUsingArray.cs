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
           
            int TargetIndex = -1;
            for (int i = 0; i < _Count; i++) 
            {
                if (EqualityComparer<T>.Default.Equals(Elements[i], Item)) 
                {
                    TargetIndex = i;
                    break;
                }
                
            }
            if (TargetIndex != -1)
            {
                for (int i = TargetIndex ; i < _Count -1; i++) 
                {
                    Elements[i] = Elements[i +1];
                }
                Elements[_Count-1] = default(T);
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
            
            for (int i = 0; i < _Count; i++)
            {
                if (EqualityComparer<T>.Default.Equals(Elements[i], Target))
                {
                    return true;
                }

            }
            return false;
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
            for (int i = 0; i < _Count; i++) 
            {
                yield return Elements[i];
            }
            
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
