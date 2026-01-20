using System;
using System.Dynamic;

namespace FirstConsoleProj
{
    internal class Program

    {
        enum enWeekDays
        { 
            Monday,
            Tuesday, 
            Wednesday, 
            Friday,
            Saturday,
            Sunday,

        }
        //when setting an value, every member after will be auto number
        enum enCateg{
            food,//0
            art,//1
            fashion = 3 // 3,
            electronics//4,
        }
        //enums with numarical

        enum enCategoriesNumerical : byte 
        {
            Electronics = 1,
            Food = 2,
            Art = 3,
            Fashion = 4,

        }

        static void Main(string[] args)
        {


            enCateg myCat;
            enCategoriesNumerical myCategoriesNumerical;
            enWeekDays enWeekDays

            Console.ReadKey();


        }
    }
}
