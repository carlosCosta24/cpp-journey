using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program { 
        static void Main(string[] args)
        {

            // date and time
            DateTime dt = new DateTime();

            DateTime dt1 = new DateTime(2023, 12, 12);

            DateTime dt2 = new DateTime(2025, 12, 30, 5, 10, 26);

            DateTime dt3 = new DateTime();

            // ticks
            Console.WriteLine(DateTime.MinValue.Ticks);
            Console.WriteLine(DateTime.MaxValue.Ticks);


            Console.WriteLine(dt);       
            Console.WriteLine(dt1);
            Console.WriteLine(dt2);

            DateTime Current = DateTime.Now;
            DateTime Today = DateTime.Today;
            DateTime CurrentZone = DateTime.UtcNow;
            DateTime Max = DateTime.MaxValue;
            DateTime Min = DateTime.MinValue;

            Console.WriteLine("currentDateTime: " + Current);
            Console.WriteLine("Today: " + Today);
            Console.WriteLine("currentDateTimeUTC: " + CurrentZone);
            Console.WriteLine("minDateTimeValue: " + Min);
            Console.WriteLine("maxDateTimeValue: " + Max);

            Console.WriteLine("\nTime Spane:");
            DateTime Date = new DateTime(2026, 1, 1);

            TimeSpan ts = new TimeSpan(24,24,24);
            Console.WriteLine(ts);
            Console.WriteLine(ts.Days);
            Console.WriteLine(ts.Hours);
            Console.WriteLine(ts.Minutes);
            Console.WriteLine(ts.Seconds);
            //Adding the timw spane to the date
            DateTime newDate = Date.Add(ts);
            Console.WriteLine(newDate);






            Console.ReadKey();


        }
    }
}
