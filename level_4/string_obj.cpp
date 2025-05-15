#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentance = "My name is carlos cost i love programming. working on mastering c++ basics ";

    cout << sentance.length() << endl;
    cout << sentance.at(2) << endl;
    cout << sentance.append(", I will soon .") << endl;
    cout << sentance.insert(10,"Mr.") << endl;
    cout << sentance.substr(10,11) << endl;
    sentance.push_back('t');
    cout << sentance << endl;
    sentance.pop_back();
    cout << sentance << endl;
    cout << sentance.find("carlos") << endl;
    if (sentance.find("Carlos") == sentance.npos) {
        cout << "Not found"<< endl;
    }
    sentance.clear();

    return 0;





}