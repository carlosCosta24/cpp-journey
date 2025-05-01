#include <iostream>
using namespace std;

enum color
{
    black,
    white,
    gray
};

int main()
{
    color color;

    cout << color::white << endl;

    return 0;
}