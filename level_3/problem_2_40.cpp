#include <iostream>
#include <cstdlib>
using namespace std;

void ArrPrinter(int arr[100], int Length)
{
    int counter = 0;
    for (int i = 0; i < Length; i++)
    {
        cout << arr[i] << " ";
        counter++;
        if (counter == 10)
        {

            cout << endl;
            counter = 0;
        }
    }
    cout << endl;
}

void DynamiclyAdding(int &Length, int Arr[100], int Number)
{
    Arr[Length] = Number;
    Length++;
}
bool CheckUnique(int arr[100], int length, int value)
{

    for (int i = 0; i < length; i++)
    {
        if (arr[i] == value)
            return true;
    }

    return false;
}
void AddingElementToArray(int First[100], int Second[100], int &Length, int &SecondLength)
{
    for (int i = 0; i < Length; i++)
    {
        if (!CheckUnique(Second, SecondLength, First[i]))
            DynamiclyAdding(SecondLength, Second, First[i]);
    }
}

int main()
{
    int arr[100] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};
    int Unique[100];
    int Firstlength = 10, SecondLength = 0;

    cout << "array 1 elements: " << endl;
    ArrPrinter(arr, Firstlength);

    AddingElementToArray(arr, Unique, Firstlength, SecondLength);

    cout << "distinct element array: " << endl;
    ArrPrinter(Unique, SecondLength);
}