using System;


namespace Boxing
{
    internal class Program
    {
        static void Main()
        {
            
            int ValueType = 500; 
            // boxing the value type into refrance type
            object RefranceType = ValueType; 

            Console.WriteLine("Boxing");
            Console.WriteLine($"Value Type: {ValueType}");
            Console.WriteLine($"Refrance Type: {RefranceType}");

            // unboxing 
            int Unboxing = (int)RefranceType;
            Console.WriteLine("Unboxing");
            Console.WriteLine(Unboxing);


            Console.ReadKey();
        }
    }
}
