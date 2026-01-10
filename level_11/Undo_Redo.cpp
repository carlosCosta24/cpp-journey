#include "clsMyString.h"
#include <iostream>
using namespace std;

int main() {
    clsMyString S1;

    cout << "\t\t\t\t Undo / Do Project using Stack" << endl;

    cout << " S1 Value: " ;
    cout << S1.Get()<< endl;

    S1.SetValue("Carlos");

    cout << " S1 Value: " ;
    cout << S1.Get()<< endl;

    S1.SetValue("Marcos");

    cout << " S1 Value: " ;
    cout << S1.Get()<< endl;

    S1.SetValue("Ricardo");

    cout << " S1 Value: " ;
    cout << S1.Get()<< endl;

    cout << "\n\n Undo: " << endl;
    cout << "------------------"<< endl;

    S1.Undo();

    cout << " S1 Value: " ;
    cout << S1.Get() << endl;

    S1.Undo();

    cout << " S1 Value: " ;
    cout << S1.Get()<< endl;

    S1.Undo();

    cout << " S1 Value: " ;
    cout << S1.Get()<< endl;

    cout << "\n\n Redo: " << endl;
    cout << "------------------"<< endl;

    S1.Redo();

    cout << " S1 Value: " ;
    cout << S1.Get()<< endl;

    S1.Redo();

    cout << " S1 Value: ";
    cout << S1.Get()<< endl;

    S1.Redo();

    cout << " S1 Value: ";
    cout << S1.Get()<< endl;


    return 0;




}