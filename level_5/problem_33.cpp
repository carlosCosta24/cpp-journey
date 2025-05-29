#include <iostream>
#include <string>
using namespace std;
string Read() {
    string S;
    cout << "Enter a sentence: ";
    getline(cin, S);
    return S;
}
bool IsVowel(char Letter) {
    char Vowels[5] = {'A', 'E', 'I', 'O', 'U'};
    char Curr = toupper(Letter);

    for (char Vowel : Vowels) {
        if (Curr == Vowel ) return true;
    }
    return false;
}
int VowelCount(string Frase) {
    int Count = 0;
    for (int i = 0 ; i < Frase.length() ; i++) {
        if(IsVowel(Frase[i])) {
            Count++;
        }
    }
    return Count;
}

int main() {
    string Sentence = Read();
    cout << "Number of vowel is: " << VowelCount(Sentence) << endl;
    return 0;
}
