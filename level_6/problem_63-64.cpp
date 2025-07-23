#include <iostream>
#include <vector>
using namespace std;
struct stDate {
    short Year;
    short Month;
    short Day;
};
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
bool IsLongMonth(int month) {

    return month == 1 || month == 3 || month == 5 ||
           month == 7 || month == 8 || month == 10 || month == 12;
}
bool YearChecker(int Input) {

    return (Input % 4 == 0 && Input % 100 != 0) || (Input % 400 == 0);
}
short NumberOfDays(int Year , int Month) {

    if (Month < 1 || Month > 12) return 0;
    return(Month == 2)
    ?(YearChecker(Year)?  29 : 28)
    : ((IsLongMonth(Month))? 31: 30);
}

bool IsDateValid(stDate Date) {
    short Days= NumberOfDays(Date.Year, Date.Month);
    return (Date.Day >= 1 && Date.Day <= Days &&
            Date.Month >= 1 && Date.Month <= 12 );

}
string ReadDateString() {
    string DateString;
    cout << "Please Enter Date dd/mm/yyyy?"<<endl;
    // omit white space
    getline(cin >> ws ,DateString );
    return DateString;
}
vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}
stDate StringToDate(string DateString) {
    stDate Date;
    vector<string> StringFormDate = SplitString(DateString, "/");
    Date.Day = stoi(StringFormDate[0]) ;
    Date.Month = stoi(StringFormDate[1]);
    Date.Year = stoi(StringFormDate[2]);
    return Date;

}
string DateToString(stDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main() {
    stDate Date;
    string DateString = ReadDateString();
    Date = StringToDate(DateString);
    cout << "Day: "<<Date.Day <<endl;
    cout << "Month: "<<Date.Month <<endl;
    cout << "Year: "<<Date.Year <<endl;
    cout << "You entered: " << DateToString(Date) << endl;

    return 0;
}
