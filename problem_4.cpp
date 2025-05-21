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
            arr[i][j] = RandomGenerator(0, 10);
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

void ColumnSummer(int arr[3][3]) {
    for (int i =0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += arr[j][i];
        }
        cout << sum << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    MatrixFiller(Matrix);
    MatrixPrinter(Matrix);
    ColumnSummer(Matrix);
    return 0;
}