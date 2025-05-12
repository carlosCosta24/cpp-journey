#include <iostream>
#include <limits>
using namespace std;


int ValidateInput() {
    int Num;
    cout << "Enter a number: " << endl;
    cin >> Num;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid input. Please try again." << endl;

        cin >> Num;

    }
    return Num;
}
int main() {
    int Number = ValidateInput();
    cout << "Your Number is: " <<Number<<  endl;
    return 0;

}