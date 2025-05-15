#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> vNumber = {1,2,3,4,5,6,7,8,9,10};

    //access methods for vectors.
    cout<< vNumber.size() << endl;
    cout << vNumber[0]<< endl;
    cout << vNumber[1] << endl;
    cout << vNumber.at(2) << endl;

    //editing the elements inside the vector

    vNumber[0] = 10;
    vNumber.at(2) = 20;

    cout << "vector elements after edit " << endl;
    for (int & i : vNumber) {
        cout << i << endl;
    }

    //print the vector using iterator
    cout << "print the vector using iterator"<< endl;
    for (vector<int>::iterator vPointer = vNumber.begin(); vPointer != vNumber.end(); ++vPointer) {
        cout<< *vPointer << endl;
    }


    return 0;
}