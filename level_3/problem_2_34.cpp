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
void ArrayElementFounder(int arr[100], int Length, int Target)
{
    int Position = 0;
    int Order = 0;
    for (int i = 0; i <= Length; i++)
    {
        if (arr[i] == Target)
        {

            Position = i;
            Order = i + 1;
        }
    }
    if (Order != 0)
    {

        cout << "The number found at position: " << Position << endl;
        cout << "The order of number is: " << Order << endl;
    }
    else
        cout << "The number is not found: -( " << endl;
}

int main()
{

    srand((unsigned)time(NULL));
    int Random[100];
    int UserInput = ReadNumber("Enter the number of elements in array: ");

    RandomArray(Random, UserInput);
    ArrPrinter(Random, UserInput);

    int Target = ReadNumber("Enter number to search for: ");

    ArrayElementFounder(Random, UserInput, Target);

    return 0;
}