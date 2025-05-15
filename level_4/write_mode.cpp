#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file;
    //to start from skratch usw ios::out , to keep the old data use ios::out | ios::app
    file.open("file.txt", ios::out | ios::app);

    if (file.is_open()) {
        file<< "Hi here is carlos costa, I am working to master the c++, and build application.\n ";
        file.close();
    }
    //to print the content of the file

    file.open("file.txt", ios::in);

    if (file.is_open()) {
        string line;

        while (getline(file, line )) {

        cout << line << endl;
        }
        file.close();
    }


    return 0;
}