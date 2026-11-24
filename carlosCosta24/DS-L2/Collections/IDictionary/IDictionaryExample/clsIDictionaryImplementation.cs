using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace IDictionaryExample
{
    public class clsIDictionaryImplementation<TKey, TValue> : IDictionary<TKey, TValue>
    {
        private List<KeyValuePair<TKey, TValue>> _Items = new List<KeyValuePair<TKey, TValue>>();

        public TValue this[TKey Key]
        {
            get
            {
                foreach (var Kvp in _Items)
                {
                    if (Equals(Kvp.Key, Key))
                    {
                        return Kvp.Value;
                    }
                }
                throw new KeyNotFoundException
                ($"The given key '{Key}' was not found!");
            }
            set
            {
                bool found = false;
                for (int i = 0; i < _Items.Count; i++)
                {
                    if (Equals(_Items[i].Key, Key))
                    {
                        _Items[i] = new KeyValuePair<TKey, TValue>(Key, value);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    _Items.Add(new KeyValuePair<TKey, TValue>(Key, value));
                }
            }
        }

        public ICollection<TKey> Keys => _Items.ConvertAll(Kvp => Kvp.Key);
        public ICollection<TValue> Values => _Items.ConvertAll(Kvp => Kvp.Value);

        public int Count => _Items.Count;

        public bool IsReadOnly => false;

        public void Add(TKey Key, TValue Value)
        {
            foreach (var Kvp in _Items)
            {
                if (Equals(Kvp.Key, Key))
                {
                    throw new ArgumentException("An element with same key already exists! ");
                }
            }
            _Items.Add(new KeyValuePair<TKey, TValue>(Key, Value));
        }
        public void Add(KeyValuePair<TKey, TValue> Item)
        {

            Add(Item.Key, Item.Value);
        }
        public void Clear()
        {
            _Items.Clear();
        }

        public bool Contains(KeyValuePair<TKey, TValue> Item)
        {
            return _Items.Contains(Item);

        }

        public bool ContainsKey(TKey Key)
        {
            foreach (var Kvp in _Items)
            {
                if (Equals(Kvp.Key, Key))
                {
                    return true;
                }
            }
            return false;
        }

        public void CopyTo(KeyValuePair<TKey, TValue>[] array, int arrayIndex)
        {
            _Items.CopyTo(array, arrayIndex);
        }
        public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator()
        {
            return _Items.GetEnumerator();
        }
        public bool Remove(TKey Key)
        {
            for (int i = 0; i < _Items.Count; i++)
            {
                if (Equals(_Items[i].Key, Key))
                {
                    _Items.RemoveAt(i);
                    return true;
                }
            }
            return false;

        }
        public bool Remove(KeyValuePair<TKey, TValue> Item)
        {
            return _Items.Remove(Item);
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return _Items.GetEnumerator();
        }

        public bool TryGetValue(TKey Key, out TValue Value) 
        {
            foreach (var Kvp in _Items) 
            {
                if (Equals(Kvp.Key, Key)) 
                {
                    Value = Kvp.Value;
                    return true;
                }
            }
            Value = default;
            return false;
        }
    }
}
