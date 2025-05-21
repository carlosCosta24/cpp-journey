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

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3];
    MatrixFiller(arr);
    cout << "Random 3x3 matrix: "<< endl;
    MatrixPrinter(arr);

}