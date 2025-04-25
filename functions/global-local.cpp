#include <iostream>
using namespace std;

int Global_Number = 100;

void My_Fun()
{

    int Local_Number = 200;
    cout << "the value of the local value is: " << Local_Number << endl;
}
int main()
{
    int Local_Number = 300;
    cout << "the value of the local value is: " << Local_Number << endl;

    cout << endl;
    My_Fun();

    cout << "the global value is: " << Global_Number << endl;
}