#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Read() {
    string S;
    cout << "Enter a sentence: ";
    getline(cin, S);
    return S;
}

string LeftTrimmer(string Sentence) {
    for (int i =0; i < Sentence.length(); i++) {
        if (Sentence[i] != ' ') {
            return Sentence.substr(i,Sentence.length()-i);
        }
    }
    return "";
}

string RightTrimmer(string Sentence) {

for (int i =Sentence.length()-1; i > 0; i--) {
    if (Sentence[i] != ' ') {
        return Sentence.substr(0,i+1);
    }
}
    return "";

}


string Trimmer(string Sentence) {
    return LeftTrimmer(RightTrimmer(Sentence));
}

int main() {
    string Sentence = "      Hi my name is carlos costa      ";
    cout<<"Sentence: " <<Sentence << endl;
    cout << "Left Trimming:  "<< LeftTrimmer(Sentence)<<endl;
    cout << "Right Trimming: "<< RightTrimmer(Sentence)<<endl;;
    cout << "Space Trimming:  "<< Trimmer(Sentence)<<endl;
    return 0;
}