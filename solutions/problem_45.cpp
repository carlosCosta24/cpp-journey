#include <iostream>
using namespace std;

enum enYearComponent
{
    Jan = 1,
    Feb = 2,
    Mar = 3,
    Apr = 4,
    May = 5,
    Jun = 6,
    Jul = 7,
    Agt = 8,
    Sep = 9,
    Oct = 10,
    Nov = 11,
    Dec = 12,
};

int ReadNumbers(string Message, int Start, int To)
{

    int Num;
    do
    {
        cout << Message;
        cin >> Num;

    } while (Num < Start || Num > To);

    return Num;
}

string Monthchoose(enYearComponent Month)

{

    switch (Month)
    {
    case enYearComponent::Jan:
        return "Jan";

    case enYearComponent::Feb:
        return "Feb";

    case enYearComponent::Mar:
        return "Mar";

    case enYearComponent::Apr:
        return "Apr";

    case enYearComponent::May:
        return "May";

    case enYearComponent::Jun:
        return "Jun";

    case enYearComponent::Jul:

        return "Jul";
    case enYearComponent::Agt:

        return "Agt";
    case enYearComponent::Sep:

        return "Sep";
    case enYearComponent::Oct:

        return "Oct";
    case enYearComponent::Nov:

        return "Nov";
    case enYearComponent::Dec:

        return "Dec";

    default:
        return "Not a year day!!";
    }
}

enYearComponent ReadMonth()

{
    return (enYearComponent)ReadNumbers("Enter the number of the month: ", 1, 12);
}

int main()
{
    cout << Monthchoose(ReadMonth()) << endl;
}