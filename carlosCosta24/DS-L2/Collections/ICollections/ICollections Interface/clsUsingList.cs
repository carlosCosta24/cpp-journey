using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.ComponentModel;

namespace ICollections_Interface
{
    internal class clsUsingList<T> : ICollection<T>
    {
        private List<T> Elements = new List<T>();

        public int Count => Elements.Count;
        public bool IsReadOnly => false;
        
        public void Add(T NewElement) 
        {
            Elements.Add(NewElement);
        }
        public bool Remove(T Item) 
        {
            return Elements.Remove(Item);
        }
        public void Clear()
        {
            Elements.Clear();
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
            return Elements.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }
        


    }
}
