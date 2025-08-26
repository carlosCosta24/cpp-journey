#include <iostream>
using namespace std;

class clsCalculator {
    private:
    float _Result = 0;
    float _Number = 0;
    string _Opp = "";

    public:
    short Add(short Input) {
        _Number = Input;
        _Result += _Number;
        _Opp = "Adding";
        return _Result;
    };
    short Subtract(short Input ){
        _Number = Input;
        _Result -= _Number;
        _Opp = "Subtracting";
        return _Result;
    };
    short Multiply(short Input){
        _Number = Input;
        _Result *= _Number;
        _Opp = "Multiplying";
        return _Result;
    };
    short Divide(short Input) {
        Input == 0 ? (cout << "divide by 0 is prohibited !!!!! "<< endl, Input = 1) : Input;
        _Number = Input;
        _Result /= _Number;
        _Opp = "Dividing by";
        return _Result;
    };
    void Clear() {
        _Number = 0;
        _Result = 0;
        _Opp = "";
    };
    float GetFinalResults() {
         return _Result;
    };
    void PrintResult() {
        cout <<"Result after " << _Opp << " " << _Number << " is: " << _Result<< endl;
    };

};

int main() {
    clsCalculator calc;
    calc.Clear();

    calc.Add(10);
    calc.PrintResult();

    calc.Add(100);
    calc.PrintResult();

    calc.Subtract(20);
    calc.PrintResult();

    calc.Divide(0);
    calc.PrintResult();

    calc.Divide(2);
    calc.PrintResult();

    calc.Multiply(3);
    calc.PrintResult();

    calc.Clear();
    calc.PrintResult();


}