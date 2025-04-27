#include <iostream>
using namespace std;

int EvenCalculator(int N)
{
    int sum = 0;
    for (int i = 0; i <= N; i += 2)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    cout << EvenCalculator(num) << endl;

    return 0;
}