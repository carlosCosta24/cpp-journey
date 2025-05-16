#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void LoadToFile(const string &Filename, vector<string> &vVector) {

    fstream file;
    file.open(Filename, ios::out);

    if (file.is_open()) {

        for (string &Line : vVector) {

            if (Line != "") {
                file<< Line << endl;
            }
        }
        file.close();
    }

}

void DeleteLine(vector<string> &vVector, const string Item) {

    for (string &line : vVector) {
        if (line == Item) {
            line = "";
        }
    }

}
void VectorPrinter(vector<string> &vVector) {



    for (string &Line : vVector) {
        cout << Line << "\n";


    }

}

int main() {
    vector<string> vMyVector{"carlos", "costa","age:", "25"};

    LoadToFile("file.txt", vMyVector);
    DeleteLine(vMyVector, "age:");
    VectorPrinter(vMyVector);
    return 0;
}
