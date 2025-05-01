#include <iostream>
using namespace std;

void Swab(int &N1, int &N2)
{
    int temp;
    temp = N1;
    N1 = N2;
    N2 = temp;
    cout << "After swaping inside the function First number is: " << N1 << " Second number is: " << N2 << endl;
}

int main()
{

    int firstNumber, SecondNumber;

    cout << "Enter the first number: ";
    cin >> firstNumber;

    cout << "Enter the second number: ";
    cin >> SecondNumber;

    cout << "Befor swaping First number = " << firstNumber << " Second number =  " << SecondNumber << endl;
    Swab(firstNumber, SecondNumber);
    cout << "After swaping inside the main function First number is: " << firstNumber << " Second number is: " << SecondNumber << endl;
}