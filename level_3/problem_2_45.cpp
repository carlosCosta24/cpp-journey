
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
        arr[i] = RandomNumber(-100, 100);
    }
}
bool CheckNegative(int Target)
{
    if (Target <= 0)
        return true;
    else
        return false;
}
void ArrayCounter(int arr[100], int Length, int &counter)
{
    for (int i = 0; i < Length; i++)
    {
        if (CheckNegative(arr[i]))
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
    ArrayCounter(Array, Number, counter);

    cout << "Negative Numbers count is: " << counter << endl;
}