#include<iostream>
using namespace std;

int rec_pow(int a,int b) {
    int Result = 1;
    if (b == 0) {
        return Result;
    }else {
        return Result = a * rec_pow(a,b-1);
    }
    return Result;
}

int main() {
    cout << rec_pow(2,10) << endl;
    return 0;

}
