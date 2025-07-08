#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ReadInput(short& Year){

    cout << "Please enter a Year? ";
    cin >> Year;
}
bool YearChecker(int Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
short DayFinder(int Year, int Month, int Day ) {
    const int A = (14 - Month) / 12;
    const int Y = Year - A;
    const int M = Month + (12 * A) - 2;
    const int D = (Day + Y + (Y/4)-(Y/100)+(Y/400)+ ((31 * M)/ 12 )) % 7;
    return  D ;
}
bool IsLongMonth(int month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
short NumberOfDays(int Year , int Month) {

    if (Month < 1 || Month > 12) return 0;
    return(Month == 2)
    ?(YearChecker(Year)?  29 : 28)
    : ((IsLongMonth(Month))? 31: 30);
}

void MonthCalenderPrinter(int Year , int Month) {
    const string Months [12] = {"Jan", "Feb", "Mar", "Apr","May",
        "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec"};
    int CurrentDay = DayFinder(Year, Month, 1);
    short Days = NumberOfDays(Year, Month);

    printf("\n________________%s_________________\n",
        Months[Month-1].c_str());
    printf("\n");
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int Start = CurrentDay % 7;
    for (Start =0; Start < CurrentDay ; Start++ ) {
        printf("     ");
    }

    for (int i = 1; i <= Days ; i++) {
        printf("%5d", i);
        Start ++;
        if (Start == 7) {
            Start = 0;
            printf("\n");
        }
    }
    if (Start != 0) {
        printf("\n");
    }
    printf("\n ___________________________________\n");

}

void YearCalenderPrinter(int Year) {
    printf("\n___________________________________\n");
    printf("\t\t Calendar - %d ", Year);
    printf("\n___________________________________\n");

    for (short Month = 1; Month <= 12; Month++) {
        MonthCalenderPrinter(Year, Month);
        printf("\n");
    }

}

int main() {
    short Year;
    ReadInput(Year);
    YearCalenderPrinter(Year);
    return 0;

}