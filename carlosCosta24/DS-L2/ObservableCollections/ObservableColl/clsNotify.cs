using System;
using System.Collections.ObjectModel;

namespace ObservableColl
{
    public class clsNotify
    {
        public ObservableCollection<string> Employees = new ObservableCollection<string>()
        {
            "Carlos",
            "Ricardo",
            "Max",
            "Felipe",

        };
        public void NotifyAfterChange()
        {

            Console.WriteLine("Observable Collection Content: \n");
            foreach (string Name in Employees)
            {
                Console.WriteLine($"Employee Name: {Name}");
            }
            Employees.CollectionChanged += Notify;

            Console.WriteLine("\n");
            Employees.Add("Aloha");
            Employees.Remove("Max");
            Employees.RemoveAt(1);
            Employees.Insert(1, "CarlosCosta");
            Employees.Move(3, 1);
            Console.WriteLine("\n");

            Console.WriteLine("Observable Collection Content After Modification: \n");
            foreach (string Name in Employees)
            {
                Console.WriteLine($"Employee Name: {Name}");
            }

            Console.ReadKey();
        }
        public void Notify(object sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
        {
            Console.WriteLine("Collection Changed: ");

            switch (e.Action)
            {
                case System.Collections.Specialized.NotifyCollectionChangedAction.Add:
                    Console.WriteLine("Added: ");
                    foreach (string Items in e.NewItems)
                    {
                        Console.WriteLine("-" + Items);
                    }
                    break;
                case System.Collections.Specialized.NotifyCollectionChangedAction.Remove:
                    Console.WriteLine("Removed: ");
                    foreach (string Items in e.OldItems)
                    {
                        Console.WriteLine("-" + Items);
                    }
                    break;
                case System.Collections.Specialized.NotifyCollectionChangedAction.Replace:
                    Console.WriteLine("Replaced: ");
                    foreach (string Items in e.OldItems)
                    {
                        Console.WriteLine("-" + Items);
                    }
                    Console.WriteLine("With: ");
                    foreach (string Items in e.NewItems)
                    {
                        Console.WriteLine("-" + Items);
                    }
                    break;
                case System.Collections.Specialized.NotifyCollectionChangedAction.Move:
                    Console.WriteLine("Moved: ");


                    Console.WriteLine($"- From index: {e.OldStartingIndex} to {e.NewStartingIndex}");

                    break;


            }

        }
    }
}
