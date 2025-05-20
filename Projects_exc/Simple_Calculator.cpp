#include <iostream>
using namespace std;

enum enOperation{add=1,sub=2,mul=3,divs=4};
//"Welcome to your terminal based calculator. let's get started !!"
void Messanger(const string& Message){

cout << Message << endl;

}

void TakinUserInput(float &FirstNumber,float& SecondNumber) {
    cout << "Please enter your first number: ";
    cin >> FirstNumber;

    cout << "Please enter your second number: ";
    cin >> SecondNumber;

}

float Calculator(float FirstNUmber,float SecondNumber,  enOperation OperationCode) {
    float result = 0;
    switch(OperationCode) {

        case enOperation::add:
             result = FirstNUmber + SecondNumber;
            break;
        case enOperation::sub:
             result =FirstNUmber - SecondNumber;
            break;
        case enOperation::mul:
             result=FirstNUmber * SecondNumber;
            break;
        case enOperation::divs:
            if (SecondNumber == 0) {
                cout << "Division by zero is not allowed!!"<< endl;
                return 0;
            }else {
                 result= FirstNUmber / SecondNumber;
            break;
        default:
             result = FirstNUmber + SecondNumber;

            }
    }
    return result;
}

void Printer(float Number) {
    cout << "Result: " << Number << endl;
}

void CalculatorRunner() {
    string Answer = "";
    Messanger("Let's calculate some numbers :-) ");
    do {
    float FirstNumber, SecondNumber;
    TakinUserInput(FirstNumber, SecondNumber);

    int Options;
    Messanger("Please enter the operation type(1:addition, 2:subtraction, 3:division, 4:multiplication)? ");
    cin >> Options;
        enOperation Operation = static_cast<enOperation>(Options);
        float Result = Calculator(FirstNumber, SecondNumber, Operation);

        Printer(Result);
        Messanger("Do you want to continue? (y/n): ");
        cin >>  Answer;

    }while (Answer[0] == 'Y' || Answer[0] == 'y');
    Messanger("Bye!");
}

int main() {

    CalculatorRunner();
    return 0;

}



