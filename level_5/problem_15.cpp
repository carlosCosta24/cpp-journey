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
            arr[i][j] = RandomGenerator(0,9);
        }
    }

}

short RepeaterCounter(int Arr[3][3], int Target) {
    short Counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Arr[i][j] == Target) {
                Counter++;
            }
        }
    }
    return Counter;
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
    short Number;
    int arr[3][3];
    MatrixFiller(arr);
    MatrixPrinter(arr);
    cout << "Enter the Number to count? ";
    cin >> Number;
    cout << "Number "<< Number << " count int matrix is " << RepeaterCounter(arr, Number);
    return 0;
}