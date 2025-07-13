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
stDate IncreaseDayByOne(stDate Date) {
    if (IsLastDay(Date.Year, Date.Month, Date.Day) && IsLastMonth(Date.Month)) {
        Date.Year ++;
        Date.Month = 1;
        Date.Day = 1;
    }else {
        short TotalDaysInMonth = NumberOfDays(Date.Year, Date.Month);
        if (Date.Day < TotalDaysInMonth) {
            Date.Day ++;
        }else {
            Date.Month ++;
            Date.Day = 1;
        }
    }
    return Date;
}
stDate IncreaseDateByXDays(stDate Date, short XDays) {
    for (int i = 1; i <= XDays; i++) {
         Date = IncreaseDayByOne(Date);
    }
    return Date;
}
stDate IncreaseDateByOneWeek(stDate Date) {
    for (int i = 1; i <= 7; i++) {
        Date = IncreaseDayByOne(Date);
    }
    return Date;
}
stDate IncreaseDateByXWeeks(stDate Date, short XWeeks) {
    for (int i = 1; i <= XWeeks; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}
stDate IncreaseDateByOneMonth(stDate Date ) {
    //important note: check for the month, and the year in case of the last day of the year,
    //or in the case where the next month has a different number of days
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year ++;
    }else {

        Date.Month ++;
    }

    short NumberOfDaysInMonth = NumberOfDays(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInMonth) {
        Date.Day = NumberOfDaysInMonth;
    }
    return Date;
}
stDate IncreaseDateByXMonths(stDate Date, short XMonths) {
    for (int i = 1; i <= XMonths; i++) {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}
stDate IncreaseDateByOneYear(stDate Date) {
    Date.Year++;
    return Date;
}
stDate IncreaseDateByXYears(stDate Date, short XYears) {
    for (int i = 1; i <= XYears; i++) {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;

}
stDate IncreaseDateByXYearsFaster(stDate Date, short XYears) {
    Date.Year += XYears;
    return Date;

}
stDate IncreaseDateByOneDecade(stDate Date) {
    Date = IncreaseDateByXYears(Date, 10);
    return Date;
}
stDate IncreaseDateByXDecades(stDate Date, short XDecades) {
    for (int i = 1; i <= XDecades ; i++) {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}
stDate IncreaseDateByXDecadesFaster(stDate Date, short XDecades) {
    Date.Year += (XDecades * 10);
    return Date;
}
stDate IncreaseDateByOnceCentury(stDate Date) {
    Date = IncreaseDateByXDecades(Date, 10);
    return Date;
}
stDate IncreaseDateVyOneMillennium(stDate Date) {
    for (int i = 1; i <= 10; i++) {
        Date = IncreaseDateByOnceCentury(Date);
    }
    return Date;
}

int main() {
    stDate Date1 = ReadDate();
    cout << "Date After:" << endl;

    Date1 =  IncreaseDayByOne(Date1);
    cout <<"01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1= IncreaseDateByXDays(Date1, 10);
    cout <<"02-Adding 10 days is: "<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1 = IncreaseDateByOneWeek(Date1);
    cout <<"03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1 = IncreaseDateByXWeeks(Date1, 10);
    cout <<"04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1 = IncreaseDateByOneMonth(Date1);
    cout <<"05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1 = IncreaseDateByXMonths(Date1, 5);
    cout <<"06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1 = IncreaseDateByOneYear(Date1);
    cout <<"07-Adding one year is: " <<Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1 = IncreaseDateByXYears(Date1, 10);
    cout <<"08-Adding 10 years is: " <<Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

    Date1 = IncreaseDateByXYearsFaster(Date1, 10);
    cout <<"09-Adding 10 years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneDecade(Date1);
    cout <<"10-Adding one decade is: " <<Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXDecades(Date1, 10);
    cout <<"11-Adding 10 decade is: " <<Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXDecadesFaster(Date1, 10);
    cout << "12-Adding 10 decades (faster) is: " << Date1 .Day << "/" << Date1.Month << "/" <<Date1.Year << endl;

    Date1 = IncreaseDateByOnceCentury(Date1);
    cout << "13-Adding one century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateVyOneMillennium(Date1);
    cout << "14-Adding one millennium is: " << Date1.Day << "/" << Date1.Month << "/" <<Date1.Year << endl;

}

