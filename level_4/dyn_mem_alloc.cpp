#include <iostream>
using namespace std;

int main() {
    int *pX;
    float *pY;

    pX = new int;
    pY = new float;

    *pX = 25;
    *pY = 27;

    cout << *pX << endl;
    cout << *pY << endl;

    delete pX;
    delete pY;

    return 0;
}