#include <iostream>
#include <cstdlib>
using namespace std;
int ReadNumber()
{

    int Number;

    cout << "Enter a number? " << endl;
    cin >> Number;

    return Number;
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
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void RandomArray(int arr[100], int Length)
{
    for (int i = 0; i <= Length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void DynamiclyAdding(int &Length, int Arr[100], int Number)
{
    Length++;
    Arr[Length - 1] = Number;
}
bool CheckOdd(int Target)
{
    if (Target % 2 != 0)
        return true;
    else
        return false;
}

void AddingElementToArray(int First[100], int Second[100], int &Length, int &SecondLength)
{
    for (int i = 0; i < Length; i++)
    {
        if (CheckOdd(First[i]))
            DynamiclyAdding(SecondLength, Second, First[i]);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr[100];
    int Arr2[100];
    int Length = ReadNumber();
    int Length2 = 0;

    RandomArray(Arr, Length);
    cout << endl;

    cout << "Array 1 elements: ";
    ArrPrinter(Arr, Length);

    AddingElementToArray(Arr, Arr2, Length, Length2);

    cout << "Array 2 off odd elements: ";
    ArrPrinter(Arr2, Length2);

    return 0;
}