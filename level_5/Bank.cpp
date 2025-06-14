#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

void Menu() {
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\t\t\t\tMain Menu" << endl;
    cout << "\t\t\t================================"<<endl;
    cout<< "\t\t\t[1] Show Client List."<< endl;
    cout<< "\t\t\t[2] Add New Client."<<endl;
    cout<< "\t\t\t[3] Delete Client."<<endl;
    cout<< "\t\t\t[4] Update Client Info."<<endl;
    cout<< "\t\t\t[5] Find Client."<<endl;
    cout<< "\t\t\t[6] Exit."<<endl;
    cout << "\t\t\t================================"<<endl;
    cout << "\t\t\tChoose What to do? [1 - 6]"<<endl;
    system("pause");

}
/*system(pause)*/

int main() {
    Menu();
}