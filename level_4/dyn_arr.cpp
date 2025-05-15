#include <iostream>
using namespace std;

int main() {
 int num ;
 cout << "Enter the number of elements in array: ";
 cin>> num;

 float *p = new float[num];

 cout << "Enter the grade of students. "<< endl;

 for (int i =0 ; i < num ; i++) {
  cout << "Enter the grade of student "<< i+1<<" : ";
  cin >> *(p + i);
 }

 cout << "Printing the grades of students: "<<endl;

 for (int i =0 ; i < num ; i++) {
  cout << "Degree of student " << i+1 << " :" << *(p + i) << endl;
 }

 delete [] p;

 return 0;
}