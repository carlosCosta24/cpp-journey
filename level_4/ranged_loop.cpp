#include <iostream>
using namespace std;

void RangedLoop() {
    int Array[] = {1,2,3,4,5,6,7,8,8};
    for (int i : Array) {
        for (int j = 0 ; j < i ; j++) {
            cout << "*" ;
        }
    cout << endl;
    }
}

int main() {
    RangedLoop();

}