#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
enum enPriority{Low=0, Medium=1, High=2};
struct stTask {
    short id;
    string name;
    string description;
    string Start_date;
    string End_date;
    bool IsFinished = false;
    enPriority priority = enPriority::Low;

};

int MenuPrinter() {
    int choice;
    cout << "Please choose action:" << endl;
    cout<< "[1] Add Task";
    cout<< "[2] List Tasks";
    cout<< "[3] Delete Task";
    cout<< "[4] Mark Complete";
    cout<< "[5] Save & Exit";
    cin >> choice;
}

void AddTask(vector<stTask>&Tasks) {
    stTask NewTask;
    enPriority TaskPriority;
    //adding id using time
    cout<< "Please choose a task name: " << endl;
    getline(cin, NewTask.name);
    cout << "Please choose a description: " << endl;
    getline(cin, NewTask.description);
    cout<< "Please enter start date: " << endl;
    getline( cin,NewTask.Start_date);
    cout << "Please enter end date";
    getline(cin, NewTask.End_date);
    cout << "Please enter priority(1-low, 2-Medium, 3-High): " << endl;
    cin >> TaskPriority;
    Tasks.push_back(NewTask);
}

void ListTasks(vector<stTask>&List) {
    for (item : List) {
    cout << cout << item.name << " " << item.description << endl;
}
}

void DeleteTask(vector<stTask>&List, int Id) {
    for (Item : List) {
        if (Item.id == Id ) {
            List.pop_back(Item);
        }
    }

}
