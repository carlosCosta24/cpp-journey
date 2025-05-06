#include <iostream>
using namespace std;

int ReadNumber()
{

    int num;

    cout << "Enter A number: " << endl;
    cin >> num;

    return num;
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

void ArrayReverser(int FirstArray[100], int SecondArray[100], int &Length)
{
    for (int i = 0; i < Length; i++)
    {
        SecondArray[i] = FirstArray[Length - i - 1];
    }
}

/*bool IsPalindromeArray(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {

        if (arr[i] != arr[Length - i - 1])
        {
            return false;
        }
    }

    return true;
}
*/
bool IsPalindrome(int First[100], int Second[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (First[i] != Second[i])
            return false;
    }
    return true;
}
void ReadArrayData(int Arr1[100], int Length)
{

    for (int i = 0; i <= Length - 1; i++)
    {

        cout << "Please enter Number " << i + 1 << endl;
        cin >> Arr1[i];
    }
}
int main()
{
    int FirstArr[100];
    int SecondArr[100];
    int Length = ReadNumber();

    ReadArrayData(FirstArr, Length);

    ArrayReverser(FirstArr, SecondArr, Length);

    if (IsPalindrome(FirstArr, SecondArr, Length))
        cout << "Yes, this Array is palindrome!" << endl;
    else
        cout << "No, this Array is not palindrome!" << endl;
}