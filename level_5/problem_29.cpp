#include <iostream>
#include <string>
using namespace std;

int SmallCount(string String){
    int Count=0;
    for(int i =0 ; i <String.length(); i ++){
        if( islower(String[i])) Count ++ ;
    }
    return Count;
}
int UpperCount(string String){
    int Count=0;
    for(int i =0 ; i < String.length(); i ++){
        if(isupper(String[i])) Count ++;
    }
    return Count;
}

int main()
{
    string UserInput;
    cout<< "Please Enter a string: ";
    getline(cin, UserInput);
    cout << "length of the string is: " << UserInput.length() << endl;
    cout << "The Small letter Count is: " << SmallCount(UserInput)<< endl;
    cout << "The Captial letter count is: " << UpperCount(UserInput)<<endl;

    return 0;
}
