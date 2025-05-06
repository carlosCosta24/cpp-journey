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

void DynamiclyAdding(int &Length, int Arr[100], int Number)
{
    Length++;
    Arr[Length - 1] = Number;
}

void AddingElementToArray(int Arr[100], int &Length)
{
    bool AddMore = true;
    do
    {

        DynamiclyAdding(Length, Arr, ReadNumber());
        cout << "DO you want to add more number? [0]No, [1]Yes?? ";
        cin >> AddMore;

    } while (AddMore);
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int Length = 0;

    AddingElementToArray(arr, Length);

    cout << "Array length is: " << Length << endl;
    cout << "Array elements is: ";
    ArrPrinter(arr, Length);

    return 0;
}