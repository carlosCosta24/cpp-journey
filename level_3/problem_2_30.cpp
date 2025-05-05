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
void ArraySummer(int arr1[100], int arr2[100], int Result[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        Result[i] = arr1[i] + arr2[i];
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Array1[100], Array2[100], Sum[100];
    int Number = ReadNumber("Enter the number of elements:");
    cout << endl;

    RandomArray(Array1, Number);
    RandomArray(Array2, Number);
    cout << endl;

    cout << "Array 1 elements: ";
    ArrPrinter(Array1, Number);
    cout << endl;

    cout << "Array 2 elements: ";
    ArrPrinter(Array2, Number);
    cout << endl;

    ArraySummer(Array1, Array2, Sum, Number);
    cout << "Sum of 2 arrays is: ";

    ArrPrinter(Sum, Number);
}