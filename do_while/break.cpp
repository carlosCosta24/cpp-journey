#include <iostream>
using namespace std;

int main()
{

    int arr[10] = {10, 20, 44, 55, 33, 22, 99, 88, 99, 100};
    int length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i <= length; i++)
    {
        if (arr[i] == 20)
        {
            cout << arr[i] << endl;
            break;
        }
    }
}