#include <iostream>
using namespace std;

int OddCalculator(int N)
{
    int sum = 0;
    for (int i = 1; i <= N; i += 2)
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

    cout << OddCalculator(num) << endl;

    return 0;
}