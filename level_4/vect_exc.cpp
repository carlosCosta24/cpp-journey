#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void VectorFiller(vector<int> &vNumber) {
    int Num = 0;
    cout << "Please enter numbers: ";
    cin >> Num;
    vNumber.push_back(Num);
}

void VectorPrinter(vector<int> & vect) {
    size_t index = 0;
    for (int &Num : vect) {
        printf("Number %lu is: %d \n", index+1,Num);
        index++;
    }
}

int main() {
    char Yes = 'Y';
    vector<int> vUser;
    do {
        VectorFiller(vUser);
        cout << "do you want to continue? (y/n): ";
        cin>> Yes;
    } while (Yes == 'Y' || Yes == 'y' );
        VectorPrinter(vUser);
        system("clear");

    return 0;
}