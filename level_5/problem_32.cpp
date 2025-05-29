#include <iostream>
#include <string>
using namespace std;
char Read() {
    char Char;
    cout << "Enter a character: ";
    cin>> Char ;
    return Char;
}

/*
 *second method
IsVowel(char Ch1)
{
Ch1 = tolower(Ch1);
return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
== 'o') || (Ch1 == 'u'));
}
 */
bool IsVowel(char Letter) {
    char Vowels[5] = {'A', 'E', 'I', 'O', 'U'};
    char Cur = toupper(Letter);

    for (char Vowel : Vowels) {
    if (Cur == Vowel ) return true;
    }
    return false;
}

int main() {
    char Char = Read();
    IsVowel(Char) ? cout << "Vowel" : cout << "Not Vowel";
    return 0;
}