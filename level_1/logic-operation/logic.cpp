#include <iostream>
using namespace std;

int main()
{
    short A, B;
    cout << "Give me the first number: ";
    cin >> A;
    cout << "Give me the second number: ";
    cin >> B;

    // first operation
    cout << A << " >= " << B << " is " << (A >= B) << endl;
    cout << A << " > " << B << " is " << (A > B) << endl;
    cout << A << " <= " << B << " is " << (A <= B) << endl;
    cout << A << " < " << B << " is " << (A < B) << endl;
    cout << A << " = " << B << " is " << (A == B) << endl;
    // second operation
    cout << A << " not >= " << B << " is " << !(A >= B) << endl;
    cout << A << " not > " << B << " is " << !(A > B) << endl;
    cout << A << " not <= " << B << " is " << !(A <= B) << endl;
    cout << A << " not < " << B << " is " << !(A < B) << endl;
    cout << A << " not = " << B << " is " << !(A == B) << endl;
    // third operation
    cout << "1" << " and " << "1" << " is " << (1 && 1) << endl;
    cout << "true" << " and" << "0" << " is " << (true && 0) << endl;
    cout << "0 " << " or " << "1" << " is " << (A || B) << endl;
    cout << "0 " << " or" << "0" << " is " << (0 || 0) << endl;
    cout << "!0 " << " = " << " is " << !0 << endl;
    cout << "!(1 or 0) " << " is " << !(1 || 0) << endl;

    // fourth operation

    cout << "(7 = 7) and (7 > 5)" << " is " << ((7 == 7) && (7 > 5)) << endl;
    cout << "(7 = 7) and (7 < 5)" << " is " << ((7 == 7) && (7 < 5)) << endl;
    cout << "(7 = 7) or (7 < 5)" << " is " << ((7 == 7) || (7 < 5)) << endl;
    cout << "(7 < 7) or (7 > 5)" << " is " << ((7 < 7) || (7 > 5)) << endl;
    cout << "not (7 = 7) and (7 > 5)" << " is " << !((7 == 7) && (7 > 5)) << endl;
    cout << "(7 = 7) and not(7 < 5)" << " is " << ((7 == 7) && !(7 < 5)) << endl;

    // final operation
    cout << "(5 > 6 and 7 = 7) or (1 or 0)" << " is " << ((5 > 6 && 7 == 7) || (1 || 0)) << endl;
    cout << "not(5 > 6 and 7 = 7) or (1 or 0)" << " is " << !((5 > 6 && 7 == 7) || (1 || 0)) << endl;
    cout << "not (5 > 6 or 7 = 7 ) or not (1 or 0) " << " is " << (!(5 > 6 || 7 == 7) || !(1 || 0)) << endl;
    cout << "not (5 > 6 or 7 = 7 ) and not (1 or 0) " << " is " << (!(5 > 6 || 7 == 7) && !(1 || 0)) << endl;
    cout << "((5 > 6 and 7 <= 8) or (8 > 1 and 4 <= 3)) and true" << " is " << (((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3)) && true) << endl;
    cout << "((5 > 6 and not(7 < 8)) and (8 > 1 or 4 <= 3 )) or true" << " is " << (((5 > 6 && !(7 < 8)) && (8 > 1 || 4 <= 3)) || true) << endl;

    return 0;
}