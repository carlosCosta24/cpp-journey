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
void ShuffleArray(int arr[100], int Shuffled[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        int RandomIndex = RandomNumber(1, length);
        Shuffled[i] = arr[RandomIndex];
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

void OrderedArray(int ordered[100], int Length)
{
    for (int i = 0; i <= Length; i++)
    {
        ordered[i] = i + 1;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Ordered[100];
    int Shuffled[100];
    int UserInput = ReadNumber("Enter the length of an array: ");

    OrderedArray(Ordered, UserInput);

    cout << "Array elements before shuffle: ";
    ArrPrinter(Ordered, UserInput);

    ShuffleArray(Ordered, Shuffled, UserInput);

    cout << "Array after shuffle: ";
    ArrPrinter(Shuffled, UserInput);
}
