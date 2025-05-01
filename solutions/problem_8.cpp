#include <iostream>
using namespace std;

enum enStatus
{
    pass = 1,
    fail = 2
};

float ReadNumber()
{

    float num;

    cout << "Enter the number: " << endl;
    cin >> num;

    return num;
}

enStatus PassCheck(float num)
{
    if (num >= 50)
        return enStatus::pass;
    else
        return enStatus::fail;
}

void PrintResult(float num)
{
    if (PassCheck(num) == enStatus::pass)
        cout << "congratulations you have passed " << endl;
    else
        cout << "you failed !!";
}

int main()
{
    PrintResult(ReadNumber());
    return 0;
}