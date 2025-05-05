#include <iostream>
#include <cstdlib>
using namespace std;
int ReadNumber(string Message)
{

    int Number;

    cout << Message;
    cin >> Number;

    return Number;
}

void ArrayReader(int arr[100], int &Num)
{
    for (int i = 0; i < Num; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arr[i];
    }
}

void ElementFinder(int Num, int arr[100])
{
    cout << arr[Num];
}

void ArrPrinter(int arr[100], int Length)
{
    cout << "Original Array: ";
    for (int i = 0; i < Length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int ElementFrequency(int arr[100], int Num, int length)
{
    int counter = 0;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] == Num)

            counter++;
    }
    return counter;
}

int main()
{
    int arr[100];
    int UserInput = ReadNumber("Enter the size of array: ");
    ArrayReader(arr, UserInput);
    int ElementToFind = ReadNumber("Enter the number to check: ");
    ArrPrinter(arr, UserInput);
    cout << "Number " << ElementToFind << " is repeated " << ElementFrequency(arr, ElementToFind, UserInput) << " Times." << endl;
    return 0;
}