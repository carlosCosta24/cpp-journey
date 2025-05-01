#include <iostream>
using namespace std;

enum enOperations
{
    add,
    sub,
    mult,
    dv,

};

float Calculator(float num_1, float num_2, enOperations operation)
{

    switch (operation)
    {
    case enOperations::add:
        return num_1 + num_2;
        break;

    case enOperations::sub:
        return num_1 - num_2;
        break;

    case enOperations::mult:
        return num_1 * num_2;
        break;

    case enOperations::dv:
        return num_1 / num_2;
        break;

    default:
        return 0.0;
    }
}

int main()
{
    float num_1, num_2;
    int operand;

    cout << "Enter the first number: ";
    cin >> num_1;

    cout << "Enter the second number: ";
    cin >> num_2;

    cout << "Enter type of operation (0 = add / 1 = sub / 2 = mult / 3 = div); ";
    cin >> operand;

    cout << "the result is: " << Calculator(num_1, num_2, (enOperations)operand) << endl;

    return 0;
}