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

/*
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    // Loop through the array to check for the number.
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;  // Return the index if the number is found.
    }
    // If the loop completes, the number was not found.
    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    // Use FindNumberPositionInArray and check if the result is not -1.
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}
*/
bool ArrayElementFounder(int arr[100], int Length, int Target)
{

    for (int i = 0; i <= Length; i++)
    {
        if (arr[i] == Target)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    srand((unsigned)time(NULL));
    int Random[100];
    int UserInput = ReadNumber("Enter the number of elements in array: ");

    RandomArray(Random, UserInput);
    ArrPrinter(Random, UserInput);

    int Target = ReadNumber("Enter number to search for: ");

    if (ArrayElementFounder(Random, UserInput, Target))
        cout << "Yes, the number is in the array :-)" << endl;
    else
        cout << "No, the number isn't in the array :-(" << endl;

    return 0;
}