using System;
using System.Collections.Generic;
using System.Collections;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IListExample
{
    public class clsIListImplementation<T> : IList<T>
    {
        private List<T> _List = new List<T>();

        public T this[int index] 
        {
            get => _List[index];
            set => _List[index] = value;
        }

        public int Count => _List.Count;

        public bool IsReadOnly => false;

        public void Add(T Item) => _List.Add(Item);
        public void Clear() => _List.Clear();
        public bool Contains(T Item) => _List.Contains(Item);
        public void CopyTo(T[] array, int arrayIndex) =>
        _List.CopyTo(array, arrayIndex);
        public IEnumerator<T> GetEnumerator() => _List.GetEnumerator();
        public int IndexOf(T Item) => _List.IndexOf(Item);
        public void Insert(int index, T Item) => _List.Insert(index, Item);
        public bool Remove(T Item) => _List.Remove(Item);
        public void RemoveAt(int index) => _List.RemoveAt(index);

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
}
