#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vNum{1,2,3,4,5};

    try {
        cout << vNum.at(8) << endl;
    } catch (...) {
        cout << "Out of bound????"<< endl;

    }
    return 0;
}