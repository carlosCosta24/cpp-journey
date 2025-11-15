#include <iostream>
#include "clsCurrency.h"
using namespace std;

void _Print(clsCurrency Currency) {
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.GetCountry();
    cout << "\nCode       : " << Currency.GetCurrencyCode();
    cout << "\nName       : " << Currency.GetCurrencyName();
    cout << "\nRate(1$) = : " << Currency.GetRate();

    cout << "\n_____________________________\n";

}
int main() {
    clsCurrency C = clsCurrency::FindCurrencyByCode("usd");
    if (C.IsEmpty()) {
        cout << "\n Currency isn't exist "<< endl;
    }
    else {
        _Print(C);
    }
    clsCurrency C2 = clsCurrency::FindCurrencyByName("egypt");
    if (C2.IsEmpty()) {
        cout << "\n Currency isn't exist "<< endl;
    }
    else {
        _Print(C2);
    }

    C2.UpdateRate(95);
    _Print(C2);

}