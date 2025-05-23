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
            arr[i][j] = RandomGenerator(1,10);
        }
    }

}
void MiddleRowPrinter(int arr[3][3]) {

    for (int i =1; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %0*d ", 2,arr[i][j]);
        }
        cout << endl;
    }
    cout << "--------------------------------"<<endl;
}
/*void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2;
    for (short j = 0; j < Cols; j++)
    {
        printf(" %0*d ", 2, arr[MiddleRow][j]);
    }
    cout << "\n";
}*/
void MiddleColumnPrinter(int arr[3][3]) {

    for (int i =0; i < 3; i++) {
        for (int j = 1; j < 2; j++) {
            printf(" %0*d ", 2,arr[i][j]) ;
        }
    }
    cout << endl;
    cout << "--------------------------------"<<endl;
}
/*void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
short MiddleCol = Cols / 2;
for (short j = 0; j < Rows; j++)
{
printf(" %0*d ", 2, arr[j][MiddleCol]);
}
cout << "\n";
}*/
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
    int First[3][3];
    MatrixFiller(First);
    MatrixPrinter(First);


    cout << "Matrix Middle Column:" << endl;
    MiddleColumnPrinter(First);

    cout<< "Matrix Middle Row:" << endl;
    MiddleRowPrinter(First);





    return 0;
}