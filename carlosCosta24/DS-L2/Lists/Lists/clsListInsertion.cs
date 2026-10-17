using System;
using System.Collections.Generic;

namespace Lists
{
    public class clsListInsertion
    {
        public void InsertIntoList()
        {
            List<int> numbers = new List<int> { 10, 50, 80 };

            //insert into list 
            numbers.Add(80);

            Console.WriteLine("Insert 80 into List: " + string.Join(", ", numbers));


            //insert into specific index

            numbers.Insert(2, 900);

            Console.WriteLine("Insert into the 3rd index: " + string.Join(", ", numbers));

            //insert a list into numbers list

            numbers.InsertRange(1, new List<int> { 90, 80, 150 });

            Console.WriteLine("Insert list into number list: " + string.Join(", ", numbers));

            Console.ReadKey();
        }
    }
}



