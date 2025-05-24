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
            arr[i][j] = RandomGenerator(0,5);
        }
    }

}
bool IsNumberInMatrix(int Matrix1[3][3], int Number)
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            };
        }
    }
    return false;
}


void CommonNumberPrinter(int First[3][3], int Second[3][3] ){
    int Ref;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Ref = First[i][j];
            if (IsNumberInMatrix(Second, Ref)) {
                cout<< Ref << " ";
            }
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

int main(){
    srand((unsigned)time(NULL));
    int arr_1[3][3];
    int arr_2[3][3];
    MatrixFiller(arr_1);
    MatrixFiller(arr_2);
    cout << "Matrix one: "<<endl;
    MatrixPrinter(arr_1);
    cout << "Matrix two: "<<endl;
    MatrixPrinter(arr_2);
    CommonNumberPrinter(arr_1, arr_2);
    return 0;
}