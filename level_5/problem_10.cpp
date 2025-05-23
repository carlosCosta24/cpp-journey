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
    int arr[3][3];
    MatrixFiller(arr);
    MatrixPrinter(arr);
    cout<< "Sum of Matrix is: " << MatrixSum(arr) <<  endl;
    return 0;
}