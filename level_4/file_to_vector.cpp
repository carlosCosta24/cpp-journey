#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void LoadToVector(const string& Filename, vector<string> & vFile) {

    fstream File;
    File.open(Filename, ios::in);


    if (File.is_open()) {
        string Line;
        while (getline(File,Line)) {

        vFile.push_back(Line);
        }
        File.close();
    }

}

int main() {

    vector<string> vFile;

    LoadToVector("file.txt", vFile);

    for (string &Line : vFile) {
        cout << Line << endl;

    }

}