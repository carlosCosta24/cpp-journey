using System;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObservableColl
{
    public class clsCreate    {
        public ObservableCollection<string> Employees = new ObservableCollection<string>();

        public void PrintContent() 
        {
            Employees.Add("Carlos");
            Employees.Add("Ricardo");
            Employees.Add("Max");
            Employees.Add("Felipe");

            Console.WriteLine("Print ObservableCollection Items: \n");
            foreach (string Name in Employees) 
            {
                Console.WriteLine(Name);
            }

            Console.ReadKey();

        }
    }
}
