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

void RandomArray(int arr[100], int Length)
{
    for (int i = 0; i <= Length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void ReverseArray(int arr[100], int rev[100], int length)
{

    for (int i = 0; i < length; i++)
    {
        rev[i] = arr[length - i - 1];
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Ordered[100];
    int Reversed[100];
    int UserInput = ReadNumber("Enter the length of an array: ");

    RandomArray(Ordered, UserInput);

    cout << "Array elements: " << endl;
    ArrPrinter(Ordered, UserInput);

    ReverseArray(Ordered, Reversed, UserInput);

    cout << "Array elements after reverse: " << endl;
    ArrPrinter(Reversed, UserInput);
}
