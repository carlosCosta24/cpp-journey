#include <iostream>
using namespace std;

enum enGrade
{
    A = 65,
    B = 66,
    C = 67,
    D = 68,
    E = 69,
    F = 70,
};

void ReadGrade(float &Num)
{

    do
    {
        cout << "Enter the number: ";
        cin >> Num;

    } while (Num < 0 || Num > 100);
}

enGrade GradeChecker(float Grade)
{

    if (Grade <= 100 && Grade >= 90)
    {
        return enGrade::A;
    }
    else if (Grade <= 89 && Grade >= 80)
    {
        return enGrade::B;
    }
    else if (Grade <= 79 && Grade >= 70)
    {
        return enGrade::C;
    }
    else if (Grade <= 69 && Grade >= 60)
    {
        return enGrade::D;
    }
    else if (Grade <= 59 && Grade >= 50)
    {

        return enGrade::E;
    }
    else
    {
        return enGrade::F;
    }
}

void ResultPrinter(float Num)
{
    cout << "Yor grade is: " << char(GradeChecker(Num)) << endl;
}

int main()
{

    float Grade;
    ReadGrade(Grade);
    ResultPrinter(Grade);
    return 0;
}
