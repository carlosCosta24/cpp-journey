#include <iostream>
using namespace std;

enum enOperation
{
    ADD = '+',
    SUB = '-',
    MULT = '*',
    DIV = '/',
};

float ReadNumber(string Message)
{

    float Number = 0;

    cout << Message << endl;
    cin >> Number;

    return Number;
}

enOperation ChoseOperation()
{
    char operation = '+';

    cout << "Please enter an operation (+ , - , * , /)? " << endl;
    cin >> operation;

    return (enOperation)operation;
}

float Calculate(float Num1, float Num2, enOperation Operation)
{

    switch (Operation)
    {
    case enOperation::ADD:

        return Num1 + Num2;
    case enOperation::SUB:
        return Num1 - Num2;
    case enOperation::MULT:
        return Num1 * Num2;
    case enOperation::DIV:
        return Num1 / Num2;

    default:
        return Num1 + Num2;
    }
}

int main()
{
    float Number1 = ReadNumber("Please enter the first number:");
    float Number2 = ReadNumber("Please enter the second number:");

    enOperation operation = ChoseOperation();

    cout << "Result = " << Calculate(Number1, Number2, operation) << endl;

    return 0;
}