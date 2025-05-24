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

bool ScalarChecker(int arr[3][3]) {

    int reference = arr[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && arr[i][j] != reference)
            {
                return false;
            }
            else if (i != j && arr[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
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
    //int arr[3][3];
    int arr[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
    //MatrixFiller(arr);
    MatrixPrinter(arr);
    (ScalarChecker(arr))? cout<< "Its a scalar Matrix :-)": cout << "It's Not a scalar Matrix :-("<<endl;
}