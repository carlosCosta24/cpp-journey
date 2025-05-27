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
            arr[i][j] = RandomGenerator(0,100);
        }
    }

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

void MinMaxPrinter(int arr[3][3]) {
    short Max = arr[0][0];
    short Min = arr[0][0];
    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] > Max) {
            Max = arr[i][j];
        }
            if (arr[i][j] < Min) {
            Min = arr[i][j];
        }
        }
    }
    cout << "Max is: " << Max << endl;
    cout << "Min is: " << Min << endl;

}

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3];
    MatrixFiller(arr);
    MatrixPrinter(arr);
    MinMaxPrinter(arr);
    return 0;
}