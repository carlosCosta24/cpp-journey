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
string VowelPrinter(string Frase) {
    string Sentence = "";
    for (int i = 0 ; i < Frase.length() ; i++) {
        if(IsVowel(Frase[i])) {
            Sentence+= toupper(Frase[i]);
        }
    }
    return Sentence;
}

int main() {
    string Sentence = Read();
    cout << "Sentence of vowel is: " << VowelPrinter(Sentence) << endl;
    return 0;
}
