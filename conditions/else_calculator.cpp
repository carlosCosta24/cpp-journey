#include <iostream>
using namespace std;

float Calculator(float num_1, float num_2, string operation)
{
    if (operation == "add")
    {
        return num_1 + num_2;
    }
    else if (operation == "sub")
    {
        return num_1 - num_2;
    }
    else if (operation == "mult")
    {
        return num_1 * num_2;
    }
    else if (operation == "div")
    {
        return num_1 / num_2;
    }
    else
    {
        return 0.00;
    }
}

int main()
{
    float num_1, num_2;
    string operand;

    cout << "Enter the first number: ";
    cin >> num_1;

    cout << "Enter the second number: ";
    cin >> num_2;

    cout << "Enter type of operation (add / sub / mult / div); ";
    cin >> operand;

    cout << "the result is: " << Calculator(num_1, num_2, operand) << endl;

    return 0;
}