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
void ArrayCopier(int arr[100], int Length, int Copy[100])
{
    for (int i = 0; i < Length; i++)
    {
        Copy[i] = arr[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100];
    int Copy[100];
    int Number = ReadNumber("Enter the number of elements:");
    cout << endl;
    RandomArray(Array, Number);
    cout << "Array 1 elements: ";
    ArrPrinter(Array, Number);
    ArrayCopier(Array, Number, Copy);
    cout << "Array 2 elements: ";
    ArrPrinter(Copy, Number);
}