#include <iostream>
using namespace std;

void RevPrint(int N, int M) {

    if (N >= M) {
        cout<< N<< endl;
        RevPrint(N-1, M);
    }
}

int main() {
    RevPrint(10,1);
    return 0;
}