#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

int RandomGenerator(int From, int To ){
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

void MatrixFiller(int arr[3][3]) {

    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = RandomGenerator(0,4);
        }
    }

}

bool NumberFinder(int Arr[3][3], short Target){

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Arr[i][j] == Target) {
                return true;
            }
        }
    }

    return false;
}

void MatrixPrinter(int arr[3][3]) {

    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %0*d ", 2,arr[i][j]) ;

        }
        cout << endl;
    }
    cout << "--------------------------------"<<endl;
}

int main(){
    srand((unsigned)time(NULL));
    int arr[3][3];
    short Target;
    MatrixFiller(arr);
    MatrixPrinter(arr);
    cout << "Enter the number to look for? "<<endl;
    cin >> Target;
    (NumberFinder(arr, Target))? cout << "Number is in array :-)" : cout<< "Number is not in array :-(" <<endl;
    return 0;
}