#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

using namespace std;

struct stStudent {
    string FirstName;
    string LastName;
    float Grades[3];
    float TotalGrades;
    float AverageGrades;
    char Grade;

};

float InputChecker(float Input) {

     while(Input < 0.0 || Input > 100.0) {
        cout<< "Invalid Input, Please Enter a Number Between 0 and 100"<< endl;
         cin >> Input;
    }
        return Input;

}

stStudent StudentFiller() {
    stStudent temp;
    float UserInput;

    cout<< "Enter Student First Name:"<< endl;
    cin>> temp.FirstName;

    cout << "Enter Student Last Name:" << endl;
    cin>> temp.LastName;

    for (int i = 0; i < 3; i++) {
        cout<< "Enter Grade For Subject " << i+1 << ": "  <<endl;
        cin>> UserInput;
        temp.Grades[i] = InputChecker(UserInput);
    }
    return temp;
}

void GradeCalculator(float arr[3], float &totalGrades, float &averageGrades) {
    totalGrades = 0;
    for(int i = 0; i < 3; i++) {
        totalGrades += arr[i];
    }
    averageGrades = totalGrades / 3;
}

char GradeLetter(float Avg) {
    if (Avg >= 90) {
        return 'A';
    }
    else if (Avg >= 80) {
        return 'B';
    }
    else if (Avg >= 70) {
        return 'C';
    }
    else if (Avg >= 60) {
        return 'D';
    }
    else if (Avg >= 0) {  // Explicitly handle valid F grades
        return 'F';
    }
    else {
        return ' ';  // Invalid case (negative average)
    }

}


void ResultPrinter(const string &First, const string &Second, float Avg, char Grade) {

    cout << setw(14) << left << First << "| "
         << setw(17) << left << Second << "|"
         << setw(12) << left << fixed << setprecision(2) << Avg << "|"
         << setw(12) << left << Grade << "\n";

}

void Starter() {
    vector<stStudent> Students;
    int StudentNum;


    cout << "Welcome, Please Enter The Number of Students:" << endl;
    cin>> StudentNum;
    while(true) {
        cin>> StudentNum;
        if (cin.fail() || StudentNum< 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Enter Number Of Students: "<<endl;
        }else {
            break;
        }
    }

    for(int i = 0; i < StudentNum; i++) {
        cout << "Student [" << i +1<< "] " << endl;
        Students.push_back(StudentFiller());
    }
    for (stStudent &s : Students) {
        GradeCalculator(s.Grades, s.TotalGrades, s.AverageGrades);
        s.Grade = GradeLetter(s.AverageGrades);
    }
    cout << "--------------|-----------------|-------------|-------------\n";
    cout << "  FirstName   |   LastName      |   Average   |    Grade    \n";
    cout << "--------------|-----------------|-------------|-------------\n";
    for (stStudent &s : Students) {
        ResultPrinter(s.FirstName, s.LastName, s.AverageGrades, s.Grade);
    }
    cout << "--------------|-----------------|-------------|-------------\n";
}

int main() {
    Starter();
    return 0;

}
