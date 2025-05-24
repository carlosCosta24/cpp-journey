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
            arr[i][j] = RandomGenerator(0,4);
        }
    }

}

bool SparceChecker(int Arr[3][3]) {
    short ZeroCounter = 0;
    short NumberCounter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Arr[i][j] == 0) {
                ZeroCounter++;
            }else {
                NumberCounter++;
            }
        }
    }

    return (ZeroCounter > NumberCounter);
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
/*
bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
{
short MatrixSize = Rows * Cols;
return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= ceil((float)
MatrixSize / 2));
}*/


int main(){
    srand((unsigned)time(NULL));
    int arr[3][3];
    MatrixFiller(arr);
    MatrixPrinter(arr);
    (SparceChecker(arr))? cout << "matrix is sparce :-)" : cout<< "matrix is not sparce :-(" <<endl;
    return 0;
}