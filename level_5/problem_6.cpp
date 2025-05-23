#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

void MatrixFiller(int arr[3][3]) {
    short order = 0;
    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = order+1;
            order++;
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
    int arr[3][3];
    MatrixFiller(arr);
    MatrixPrinter(arr);
    return 0;
}