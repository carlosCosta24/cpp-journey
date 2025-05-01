#include <iostream>
using namespace std;

struct stInfo
{
    int Age;
    bool HasDrivingLicense;
    bool HasRecommendation;
};

stInfo ReadInfo()
{
    stInfo person;

    cout << "Do you have a driving recommendation?? (0 for no / 1 for yes): " << endl;
    cin >> person.HasDrivingLicense;

    cout << "Enter your age: " << endl;
    cin >> person.Age;

    cout << "Do you have a driving licence?? (0 for no / 1 for yes): " << endl;
    cin >> person.HasDrivingLicense;

    return person;
}

bool IsHired(stInfo Info)
{
    if (Info.HasRecommendation)
    {
        return true;
    }
    else
    {

        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
}

void PrintResult(stInfo info)
{

    if (IsHired(info))
        cout << "You are hired!! " << endl;
    else
        cout << "You are rejected " << endl;
}

int main()
{
    PrintResult(ReadInfo());

    return 0;
}
