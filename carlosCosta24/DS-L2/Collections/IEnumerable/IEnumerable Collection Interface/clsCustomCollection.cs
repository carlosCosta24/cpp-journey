using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IEnumerable_Collection_Interface
{
    public class clsCustomCollection<T> : IEnumerable<T>
    {
        private List<T> Content = new List<T> ();

        public IEnumerator<T> GetEnumerator()
        {
            for (int i = 0; i < Content.Count; i++) 
            {
                yield return Content[i];
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public void Add(T Item) 
        {
            Content.Add(Item);
        }
    }
}
