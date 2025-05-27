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
// other approach to check;
/*int IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}*/

bool IsPalindrome(int arr[3][3]) {
    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != arr[i][2-j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand((unsigned)time(NULL));
    int arr[3][3]= {{1,2,1},{5,5,6},{7,3,7}};
    //MatrixFiller(arr);
    MatrixPrinter(arr);
    (IsPalindrome(arr))? cout << "Matrix is Palindrome": cout<< "Matrix is not Palindrome";
    return 0;
}