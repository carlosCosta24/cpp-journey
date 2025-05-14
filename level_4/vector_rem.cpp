#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> vIntgers ;

    vIntgers.push_back(10);
    vIntgers.push_back(20);
    vIntgers.push_back(30);
    //To clear one by one
    vIntgers.pop_back();


    cout << "First element: " << vIntgers.front() << endl;
    cout <<"Last element: "<< vIntgers.back() << endl;
    cout <<"Size: "<< vIntgers.size() << endl;
    cout <<"Capacity: "<< vIntgers.capacity() << endl;

    vIntgers.push_back(10);


    cout << "Removing one element: \n";
    for (int &N : vIntgers) {
        cout << N << " ";
    }
    cout << "\n";

    //TO clear all the stack
    vIntgers.clear();

    cout << "Removing all elements: \n";
    for (int &N : vIntgers) {
        cout << N << " ";
    }

}