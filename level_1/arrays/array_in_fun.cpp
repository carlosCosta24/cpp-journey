#include <iostream>
using namespace std;

void ReadArray(float arr[3])
{
    cout << "Enter your grade1?: ";
    cin >> arr[0];

    cout << "Enter your grade2?: ";
    cin >> arr[1];

    cout << "Enter your grade3?: ";
    cin >> arr[2];
}

float CalculateAvg(float arr[3])
{
    return (arr[0] + arr[1] + arr[2]) / 3;
}
int main()
{
    float info[3];

    ReadArray(info);
    cout << "Average is: " << CalculateAvg(info) << endl;

    return 0;
}