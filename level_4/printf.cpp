#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main() {
    int Mark =98 , Max = 100;
// print string and intg
    printf("Your mark is %d from %d. \n", Mark, Max);
//width specific format
    for (int i =1; i<= 10; i++) {

    printf("Number: %0*d \n",2, i);

    }
    //float formating
    float pi = 3.14159265;
    printf("pi is %.*f \n",1, pi);
    printf("pi is %.*f \n",2, pi);
    printf("pi is %.*f \n",3, pi);
    printf("pi is %.*f \n",4, pi);
    printf("pi is %.*f \n",5, pi);

    //digit after comma
float x =7.50 , y = 10.50;

    printf("The result of dividing %.3f / %.3f = %.3f \n", x,y,x/y);

    //string formating

    char Name[] = "Carlos costa";
    char Project[] = "Learning c++";

    printf("Good evening Mr. %s, you are now working on %s project.\n", Name, Project);

    char c = 'C';

    printf("Width of one %*c \n", 1, c);
    printf("Width of two %*c \n", 2, c);
    printf("Width of three %*c \n", 3, c);
    printf("Width of four %*c \n", 4, c);
    printf("Width of five %*c \n", 5, c);

    cout<< "---------|--------------------------------|------------"<< endl;
    cout<< "    Code |           Name                 |     Mark   "<< endl;
    cout<< "---------|--------------------------------|------------"<< endl;

    cout <<setw(9) << "C101 " << "|" << setw(32) << "introduction to Programming 1 " << "|" << setw(9) << "95" << endl;
    cout <<setw(9) << "C102 " << "|" << setw(32) << "Computer Hardware " << "|" << setw(9) << "88"  << endl;
    cout <<setw(9) << "C1033 " << "|" << setw(32) << "Network " << "|" << setw(9) <<"75"  << endl;
    cout<< "---------|--------------------------------|------------"<< endl;

    return 0;

}