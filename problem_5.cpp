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
            arr[i][j] = RandomGenerator(0, 100);
        }
    }

}
void MatrixPrinter(int arr[3][3]) {

    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(3) <<arr[i][j] << " ";
        }
        cout << endl;
    }
}

void ColumnSummerToArray(int arr[3][3], int result [3]) {
    for (int i =0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr[j][i];
            result[i] = sum;
        }
    }
}
void ArrayPrinter(int arr[3]) {
    for (int i =0; i < 3; i++) {
        cout << "Column " << i+1 << " sum: "<< endl;
        cout<< arr[i] << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    int arr[3];
    MatrixFiller(Matrix);
    MatrixPrinter(Matrix);
    ColumnSummerToArray(Matrix,arr);
    ArrayPrinter(arr);

    return 0;
}