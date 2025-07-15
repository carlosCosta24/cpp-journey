#include <iostream>
using namespace std;
struct stDate {
    short Year;
    short Month;
    short Day;
};
bool YearChecker(short Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
bool IsLongMonth(short month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
short NumberOfDays(short Year , short Month) {

    if (Month < 1 || Month > 12) return 0;
    return(Month == 2)
    ?(YearChecker(Year)?  29 : 28)
    : ((IsLongMonth(Month))? 31: 30);
}
bool IsLastDay(short Year, short Month, short Day) {
    short NumberOfDaysInMonth = NumberOfDays(Year, Month);
    return (NumberOfDaysInMonth == Day) ? true : false;
}
bool IsLastMonth(short Month) {
    return (Month == 12 ) ? true : false;
}
stDate ReadDate() {
    stDate Date;
    cout << "Please enter a day: ";
    cin >> Date.Day;
    cout << "Please enter a month: ";
    cin >> Date.Month;
    cout << "Please enter a year: ";
    cin >> Date.Year;
    return Date;
}
stDate DecreaseDayByOne(stDate Date) {
    if (Date.Day == 1 ) {
        if (Date.Month == 1) {
            Date.Year --;
            Date.Month = 12;
            Date.Day = 31;
        }else {
            Date.Month --;
            Date.Day = NumberOfDays(Date.Year, Date.Month);
        }
    }else {
        Date.Day --;
    }
    return Date;
}
stDate DecreaseDateByXDays(stDate Date, short XDays) {
    for (int i = XDays; i > 0 ; i--) {
         Date = DecreaseDayByOne(Date);
    }
    return Date;
}
stDate DecreaseDateByOneWeek(stDate Date) {
    for (int i = 7; i >0 ; i--) {
        Date = DecreaseDayByOne(Date);
    }
    return Date;
}
stDate DecreaseDateByXWeeks(stDate Date, short XWeeks) {
    for (int i = XWeeks; i > 0 ; i--) {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate DecreaseDateByOneMonth(stDate Date ) {
    //important note: check for the month, and the year in case of the last day of the year,
    //or in the case where the next month has a different number of days
    if (Date.Month == 1 && Date.Day == 1) {
        Date.Month = 12;
        Date.Year --;
    }else {

        Date.Month --;
    }

    short NumberOfDaysInMonth = NumberOfDays(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInMonth) {
        Date.Day = NumberOfDaysInMonth;
    }
    return Date;
}
stDate DecreaseDateByXMonths(stDate Date, short XMonths) {
    for (int i = XMonths; i > 0; i--) {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate DecreaseDateByOneYear(stDate Date) {
    Date.Year--;
    return Date;
}
stDate DecreaseDateByXYears(stDate Date, short XYears) {
    for (int i = XYears; i > 0 ; i--) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;

}
stDate DecreaseDateByXYearsFaster(stDate Date, short XYears) {
    Date.Year -= XYears;
    return Date;

}
stDate DecreaseDateByOneDecade(stDate Date) {
    Date = DecreaseDateByXYears(Date, 10);
    return Date;
}
stDate DecreaseDateByXDecades(stDate Date, short XDecades) {
    for (int i = XDecades; i > 0  ; i--) {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}
stDate DecreaseDateByXDecadesFaster(stDate Date, short XDecades) {
    Date.Year -= (XDecades * 10);
    return Date;
}
stDate DecreaseDateByOnceCentury(stDate Date) {
    Date = DecreaseDateByXDecades(Date, 10);
    return Date;
}
stDate DecreaseDateVyOneMillennium(stDate Date) {
    for (int i = 10; i > 0; i--) {
        Date = DecreaseDateByOnceCentury(Date);
    }
    return Date;
}

int main() {
    stDate Date= ReadDate();
    cout << "Date After:" << endl;

    Date =  DecreaseDayByOne(Date);
    cout <<"01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date= DecreaseDateByXDays(Date, 10);
    cout <<"02-Subtracting 10 days is: "<< Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date = DecreaseDateByOneWeek(Date);
    cout <<"03-Subtracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date = DecreaseDateByXWeeks(Date, 10);
    cout <<"04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date = DecreaseDateByOneMonth(Date);
    cout <<"05-Subtracting one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date = DecreaseDateByXMonths(Date, 5);
    cout <<"06-Subtracting 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date = DecreaseDateByOneYear(Date);
    cout <<"07-Subtracting one year is: " <<Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date = DecreaseDateByXYears(Date, 10);
    cout <<"08-Subtracting 10 years is: " <<Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout <<"09-Subtracting 10 years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout <<"10-Subtracting one decade is: " <<Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecades(Date, 10);
    cout <<"11-Subtracting 10 decade is: " <<Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "12-Subtracting 10 decades (faster) is: " << Date .Day << "/" << Date.Month << "/" <<Date.Year << endl;

    Date = DecreaseDateByOnceCentury(Date);
    cout << "13-Subtracting one century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateVyOneMillennium(Date);
    cout << "14-Subtracting one millennium is: " << Date.Day << "/" << Date.Month << "/" <<Date.Year << endl;
    return 0;


}