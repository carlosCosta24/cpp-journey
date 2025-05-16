#include <iostream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;

void LoadDataToVector(string File, vector<string> &vDestination) {

    fstream file;

    file.open(File, ios::in);//read mode
    if (file.is_open()) {
        string Line;
        while (getline(file, Line)) {
            vDestination.push_back(Line);
        }
    }
    file.close();
}

void SaveDataToVector(string File, vector<string> &vSource) {

    fstream file;

    file.open(File, ios::out);//writ mode

    if (file.is_open()) {

        for (string &Line: vSource) {

           if (Line != "") file<< Line<<endl;
        }
    }
    file.close();
}

void EditFile(string File, vector<string> &vSource, string From , string To) {

    fstream file;

    file.open(File, ios::out);//writ mode

    if (file.is_open()) {

        for (string &Line: vSource) {

            if (From == To) Line = To;
        }
    }
    file.close();
}

void PrintFileContent(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }
        MyFile.close();
    }
}

int main() {
    vector<string> vDestination;
    PrintFileContent("file.txt");
    EditFile("file.txt", vDestination, "carlos", "cost");
    PrintFileContent("file.txt");
    return 0;
}