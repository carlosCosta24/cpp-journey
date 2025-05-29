#include <iostream>
#include <string>
using namespace std;

string Read() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str) ;
    return str;
}
void CaseLetterCounter(string Str, char Target, int &CaseCount, int &AllMatches){
    for(int i =0 ; i <Str.length(); i ++){
        if((Str[i]) == (Target)) CaseCount ++ ;
        if (tolower(Str[i]) == tolower(Target)) AllMatches++ ;
    }
}
//second method ;
/*short CountLetter(string S1, char Letter, bool MatchCase = true)
{
short Counter = 0;
for (short i = 0; i < S1.length(); i++)
{
if (MatchCase)
{
if (S1[i] == Letter)
Counter++;
}
else
{
if (tolower(S1[i]) == tolower(Letter))
Counter++;
}
}
return Counter;
}
*/

int main() {
    string UserInput = Read();
    char Target;
    cout << "Enter a Letter to Search for: ";
    cin>> Target;
    int CaseCount=0, AllMatches=0;
    CaseLetterCounter(UserInput, Target, CaseCount,AllMatches);
    (CaseCount == 0 && AllMatches == 0)?
    cout<< "No match " :
    cout << "The letter " << Target << " count is: " << CaseCount << endl << "Letter "<< char(toupper(Target)) << " or "<<
        char(tolower(Target)) << " is " << AllMatches<< endl;
    return 0;


}