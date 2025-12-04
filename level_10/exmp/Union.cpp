#include <iostream>
using namespace std;

union First {
    int IntFirst;
    float FltSecond;
    char CThird;
};

int main() {
    First CarlosUnion;


    CarlosUnion.IntFirst = 10;
    cout << CarlosUnion.IntFirst << endl;

    CarlosUnion.FltSecond = 10.25f;
    cout << CarlosUnion.FltSecond << endl;

    CarlosUnion.CThird = 'A';
    cout << CarlosUnion.CThird << endl;

    return 0;
}
