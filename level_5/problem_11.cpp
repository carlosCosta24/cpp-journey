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
            arr[i][j] = RandomGenerator(1,100);
        }
    }

}

int  MatrixSum(int arr[3][3]) {
    short sum=0;
    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j] ;
        }
    }
    return sum;
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

int main() {
    srand((unsigned)time(NULL));
    int ArrOne[3][3];
    int ArrTow[3][3];

    MatrixFiller(ArrOne);
    MatrixFiller(ArrTow);

    cout << "Array One: "<< endl;
    MatrixPrinter(ArrOne);
    cout << "Array Tow: "<< endl;
    MatrixPrinter(ArrTow);

    cout << "Matrix One sum: "<< MatrixSum(ArrOne) <<endl;
    cout << "Matrix Tow sum: "<< MatrixSum(ArrTow) << endl;
    (MatrixSum(ArrOne) == MatrixSum(ArrTow))? cout << "The tow matrices are equal !!":
    cout << "The tow matrices aren't equal !!"<< endl;
    return 0;
}