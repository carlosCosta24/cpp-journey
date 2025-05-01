#include <iostream>
using namespace std;

enum enWeekComponent
{
    Sat,
    Sun,
    Mon,
    Tus,
    Wed,
    Thu,
    Fri,
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

string Daychoose(enWeekComponent day)

{

    switch (day)
    {
    case enWeekComponent::Sat:
        return "Sat";

    case enWeekComponent::Sun:
        return "Sun";

    case enWeekComponent::Mon:
        return "Mon";

    case enWeekComponent::Tus:
        return "Tue";

    case enWeekComponent::Wed:
        return "Wed";

    case enWeekComponent::Thu:
        return "Thu";

    case enWeekComponent::Fri:
        return "Fri";

    default:
        return "Not a week day!!";
    }
}

enWeekComponent ReadDay()

{
    return (enWeekComponent)ReadNumbers("Enter the number of the day: ", 0, 6);
}

int main()
{
    cout << Daychoose(ReadDay()) << endl;
}