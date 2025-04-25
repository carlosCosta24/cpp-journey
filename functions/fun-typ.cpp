#include <iostream>
using namespace std;

void MySumProcedure()
{
    int N1, N2;
    cout << "please enter the first number: ";
    cin >> N1;

    cout << "please enter the second number: ";
    cin >> N2;

    cout << "********************************" << endl;
    cout << N1 + N2 << endl;
}

int SumFunction()
{
    int N1, N2;
    cout << "please enter the first number: ";
    cin >> N1;
    cout << "please enter the second number: ";
    cin >> N2;
    return N1 + N2;
}

int main()
{
    MySumProcedure();
    cout << endl;
    cout << SumFunction() << endl;
    return 0;
}