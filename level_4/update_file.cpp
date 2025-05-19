#include <iostream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;

void LoadToVector(string File , vector<string> &vVec) {

    fstream file;
    file.open(File, ios::in);

    if (file.is_open()) {

        string Line;
        while (getline(file, Line)) {
            vVec.push_back(Line);
        }
        file.close();
    }


}
void SaveVectorToFile(string FileName, vector <string> vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (string Line : vFileContent)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

void EditFile(string File , string From, string To ,vector<string> vVec) {
    fstream file;
    file.open(File, ios::in);
    if (file.is_open()) {
        string Line;
        while (getline(file, Line)) {
            for (string &Item : vVec) {

                if (Item == From) {
                    Item = To;
                    vVec.push_back(Item);

                }
            }
        }
        file.close();
    }
    SaveVectorToFile(File, vVec);
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

    vector<string> vTemp;
    LoadToVector("file.txt", vTemp);
    EditFile("file.txt", "megahed", "carlos",vTemp);
    PrintFileContent("file.txt");
}