#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vNumbers ={100,200,300,400,500};

    cout << "Numbers in vector: ";

    for (const int &num : vNumbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;

}