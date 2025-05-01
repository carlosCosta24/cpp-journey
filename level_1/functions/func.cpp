#include <iostream>
using namespace std;

void CardPrinter()
{

    cout << "**************************************" << endl;
    cout << "Name : carlos costa " << endl;
    cout << "Age : 26 " << endl;
    cout << "City : aracaju " << endl;
    cout << "Country : Brazil " << endl;
    cout << "**************************************" << endl;
}

void AstrikePrinter()
{
    cout << "****************" << endl;
    cout << "****************" << endl;
    cout << "****************" << endl;
    cout << "****************" << endl;
}

void PrintParagraph()
{

    cout << "I love programming!" << endl
         << endl;
    cout << "I promise to be the best developer ever!" << endl
         << endl;
    cout << "I know it will take sone time to practice,but i " << endl;
    cout << "will achieve my goal" << endl
         << endl;
    cout << "Best regards," << "carlos costa" << endl;
}
void PriintH()
{
    cout << "*        *" << endl;
    cout << "*        *" << endl;
    cout << "**********" << endl;
    cout << "*        *" << endl;
    cout << "*        *" << endl;
}

int main()
{
    CardPrinter();
    cout << endl;
    AstrikePrinter();
    cout << endl;
    PrintParagraph();
    cout << endl;
    PriintH();
    cout << endl;
    return 0;
}