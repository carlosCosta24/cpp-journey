#include <iostream>
using namespace std;

char MarkChecker(float mark)
{

    if (mark <= 100 && mark >= 90)
    {
        return 'A';
    }
    else if (mark <= 89 && mark >= 80)
    {
        return 'B';
    }
    else if (mark <= 79 && mark >= 70)
    {
        return 'C';
    }
    else if (mark <= 69 && mark >= 60)
    {
        return 'D';
    }
    else if (mark <= 59 && mark >= 50)
    {

        return 'E';
    }
    else
    {
        return 'F';
    }
}

int main()
{

    float Mark;

    cout << "Enter your Mark: ";
    cin >> Mark;

    cout << "Your score is: " << MarkChecker(Mark) << endl;

    return 0;
}
