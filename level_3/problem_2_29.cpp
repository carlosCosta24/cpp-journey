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
        if (arr[i] != 0)
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
bool isPrime(int Num)
{
    if (Num < 2)
    {
        return false;
    }
    for (int i = 2; i < Num / 2; i++)
    {
        if (Num % i == 0)
        {
            return false;
        }
    }
    return true;
}
void PrimeArray(int arr[100], int Length, int prime[100])
{
    int PrimaryCounter = 0;
    for (int i = 0; i < Length; i++)
    {
        if (isPrime(arr[i]))
        {

            prime[PrimaryCounter] = arr[i];
            PrimaryCounter++;
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int Array[100];
    int prime[100];
    int Number = ReadNumber("Enter the number of elements:");
    cout << endl;
    RandomArray(Array, Number);
    cout << "First Array elements: ";
    ArrPrinter(Array, Number);
    cout << "Prime Array elements: ";
    PrimeArray(Array, Number, prime);
    ArrPrinter(prime, Number);
}
/*
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int Number)
{

    int M = round(Number / 2);


    for (int Counter = 2; Counter <= M; Counter++)
    {

        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }

    return enPrimNotPrime::Prime;
}

int RandomNumber(int From, int To)
{

    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArray(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Length)
{
    int Counter = 0;


    for (int i = 0; i < arrLength; i++)
    {

        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }

    arr2Length = --Counter;
}

void PrintArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int main() {

    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength;


    FillArray(arr, arrLength);

    int arr2[100];
    int arr2Length = 0;


    CopyOnlyPrimaryNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nPrime Numbers in Array2:\n";
    PrintArray(arr2, arr2Length);

    return 0;
} */