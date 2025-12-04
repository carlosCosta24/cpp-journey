#include <iostream>
#include <map>
using namespace std;

int main() {

    map<string , bool> CheckList;

    CheckList["study programming"] = true;
    CheckList["study Management"] = false;
    CheckList["Reed book "] = false;
    CheckList["Cook"] = false;
    CheckList["Cycling"] = true;
    //Printing the map
    cout << "Printing CheckList: " << endl;
    for (const auto& pair: CheckList) {
        cout << "Task: " << pair.first << ", Status: "<< pair.second << endl;
    }

    //Find item in the map

    string Task = "cycling";
    if (CheckList.find(Task) != CheckList.end()) {
        cout << "Task was found : ";
        cout << "Task: " << Task << ", Status: " << CheckList[Task] << endl;
    }else {
        cout << "Task is not in the map"<<endl;
    }
    string Task2 = "Cook";
    if (CheckList.find(Task2) != CheckList.end()) {
        cout << "Task was found : ";
        cout << "Task: " << Task2 << ", Status: " << CheckList[Task] << endl;
    }else {
        cout << "Task is not in the map"<<endl;
    }
    return 0;
}