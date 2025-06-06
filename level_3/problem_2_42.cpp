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
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void RandomArray(int arr[100], int &Num)
{
    for (int i = 0; i < Num; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}
bool CheckOdd(int Target)
{
    if (Target % 2 != 0)
        return true;
    else
        return false;
}
void OddCounter(int arr[100], int Length, int &counter)
{
    for (int i = 0; i < Length; i++)
    {
        if (CheckOdd(arr[i]))
            counter++;
    }
}
void ArrPrinter(int arr[100], int Length)
{
    cout << "Array Elements: ";
    for (int i = 0; i < Length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int Array[100];
    int Number = ReadNumber("Enter the number of elements:");
    int counter = 0;

    RandomArray(Array, Number);
    ArrPrinter(Array, Number);
    OddCounter(Array, Number, counter);

    cout << "Odd Numbers count is: " << counter << endl;
}