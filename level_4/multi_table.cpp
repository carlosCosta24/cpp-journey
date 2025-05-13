#include <array>
#include <iostream>
#include <iomanip>
using namespace std;

int TableCreator(int arr[10][10]) {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = (i+1) * (j+1);
        }
    }
    return arr[10][10];

}
void TablePrint(int arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf( "%0*d " , 2,arr[i][j]);

        }
        cout << endl;
    }
}

int main() {
    int arr[10][10];
    TableCreator(arr);
    TablePrint(arr);
    return 0;

}