#include <iostream>
using namespace std;

int main()
{

    float Grades[3], avg;

    cout << "Enter the first grade1? ";
    cin >> Grades[0];

    cout << "Enter the first grade2? ";
    cin >> Grades[1];

    cout << "Enter the first grade3? ";
    cin >> Grades[2];

    avg = (Grades[0] + Grades[1] + Grades[2]) / 3;

    cout << "********************************\n";
    cout << "The avarage of grades is: " << avg << endl;

    return 0;
}