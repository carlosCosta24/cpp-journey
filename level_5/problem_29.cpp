#include <iostream>
#include <string>
using namespace std;
//generic fun

enum enWhatToCount { SmallLetters=0, CapitalLetters=1,All=3};
short CountLetters(string S1, enWhatToCount
WhatToCount=enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount==enWhatToCount::CapitalLetters &&
        isupper(S1[i]))
            Counter++;
        if (WhatToCount == enWhatToCount::SmallLetters &&
        islower(S1[i]))
            Counter++;
    }
    return Counter;
}


string Read() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str) ;
    return str;
}

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
    string UserInput = Read();
    cout << "length of the string is: " << UserInput.length() << endl;
    cout << "The Small letter Count is: " << SmallCount(UserInput)<< endl;
    cout << "The Capital letter count is: " << UpperCount(UserInput)<<endl;

    cout << "Second Method:" << endl;
    cout << "\nString Length = " << CountLetters(UserInput);
    cout << "\nCapital Letters Count= " << CountLetters(UserInput,
    enWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count= " <<
    CountLetters(UserInput,enWhatToCount::SmallLetters );

    return 0;
}
