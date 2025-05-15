#include <iostream>
using namespace std;

int main() {

    void *p;
    int x= 50;
    float y = 10.25;
    p = &y;

    cout << p << endl;
    cout<< *(static_cast<float*>(p))<<endl;


}