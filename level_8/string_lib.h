#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString {
    private:

    string _Value;

    public:

    clsString() {
        _Value = "";
    }
    clsString(string Value) {
        _Value = Value;
    }
    void SetValue(string Value) {
        _Value = Value;
    }
    string GetValue() {
        return _Value;
    }
    //under construction
    static short CountWords(string S) {
        string delim = " ";
        short count = 0;
        short pos = 0;
        string sWord = "";
        while ((pos = S.find(delim, 0)) != string::npos) {
            sWord = S.substr(0, pos);
            if (sWord != "") {
                count++;
            }
            S.erase(0, pos + delim.length());
        }
        if (sWord != "") {
            count++;
        }
        return count;

    }
    short CountWord() {
        return CountWord(_Value);
    }
    static void LowerFirstLetter(string String ) {
        bool IsFirstLetter = true;

        for (int i =0; i < String.length(); i++) {
            if (String[i] != ' ' && IsFirstLetter) {
                String[i] = tolower(String[i]);
            }
            IsFirstLetter = (String[i] == ' ' ? true : false);
            cout << String[i] ;
        }
    }
    void LowerFirstLetter() {
        return LowerFirstLetter(_Value);
    }
    static void CapitalFirstLetter(string String ) {
        bool IsFirstLetter = true;

        for (int i =0; i < String.length(); i++) {
            if (String[i] != ' ' && IsFirstLetter) {
                String[i] = toupper(String[i]);
            }
            IsFirstLetter = (String[i] == ' ' ? true : false);
            cout << String[i] ;
        }
    }
    void CapitalFirstLetter() {
        return CapitalFirstLetter(_Value);
    }
    static void FirstLetterPrinter(string String ) {
        bool IsFirstLetter = true;

        for (int i =0; i < String.length(); i++) {
            if (String[i] != ' ' && IsFirstLetter) {
                cout << String[i]<< endl;
            }
            IsFirstLetter = (String[i] == ' ' ? true : false);
        }
    }
    void FirstLetterPrinter() {
        return FirstLetterPrinter(_Value);
    }
    static string CapitalString(string String ) {
        for (int i =0; i < String.length(); i++) {
            String[i] = toupper(String[i]) ;
        }
        return String ;
    }
    string CapitalString() {
        return CapitalString(_Value);
    }
    static string LowerString(string String ) {
        for (int i =0; i < String.length(); i++) {
            String[i] =tolower(String[i]) ;
        }
        return String ;
    }
    string LowerString() {
        return LowerString(_Value);
    }
    static string CaseInverter(string String ) {

        for (int i =0; i < String.length(); i++) {
            (isupper(String[i])) ? String[i] = tolower(String[i]): String[i] = toupper(String[i]) ;
        }
        return String ;
    }
    string CaseInver(){
        return CaseInverter(_Value);
    }
    static char InvertLetterCase(char char1) {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }
    char InvertLetterCase() {
        return InvertLetterCase(_Value);
    }
    static string InvertAllStringLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }
    string InvertAllStringLettersCase() {
        return InvertAllStringLettersCase(_Value);
    }
    static void CaseLetterCounter(string Str, char Target, int &CaseCount, int &AllMatches){
        for(int i =0 ; i <Str.length(); i ++){
            if((Str[i]) == (Target)) CaseCount ++ ;
            if (tolower(Str[i]) == tolower(Target)) AllMatches++ ;
        }
    }
    void CaseLetterCounter() {
        return CaseLetterCounter(_Value);
    }
    static bool IsVowel(char Letter) {
        char Vowels[5] = {'A', 'E', 'I', 'O', 'U'};
        char Cur = toupper(Letter);

        for (char Vowel : Vowels) {
            if (Cur == Vowel ) return true;
        }
        return false;
    }
    bool IsVowel() {
        IsVowel(_Value);
    }
    static short VowelCount(string Frase) {
        short Count = 0;
        for (short i = 0 ; i < Frase.length() ; i++) {
            if(IsVowel(Frase[i])) {
                Count++;
            }
        }
        return Count;
    }
    short VowelCount() {
        return VowelCount(_Value);
    }
    static string VowelPrinter(string Frase) {
        string Sentence = "";
        for (int i = 0 ; i < Frase.length() ; i++) {
            if(IsVowel(Frase[i])) {
                Sentence+= toupper(Frase[i]);
            }
        }
        return Sentence;
    }
    string VowelPrinter() {
        return VowelPrinter(_Value);
    }
    static void WordPrinter(string Frase) {
        string Space = " ";
        string Word;
        int StartPosition = 0;

        while ((StartPosition = Frase.find(Space)) != string::npos) {
            Word = Frase.substr(0,StartPosition);
            if (Word != "") {
                cout << Word<< endl;
            }
            Frase.erase(0, StartPosition + Space.length());
        }
        if (Frase != "") {
            cout << Frase<< endl;
        }
    }
    void WordPrinter() {
        return WordPrinter(_Value);
    }
    vector<string> StringSpliter(string S, string Splitter) {
        vector<string> vResult;
        int Pos = 0;
        string Word;

        while ((Pos = S.find(Splitter)) != string::npos) {
            Word = S.substr(0,Pos);
            if (Word != "") vResult.push_back(Word);
            S.erase(0, Pos + Splitter.length());
        }
        if (S != "") vResult.push_back(S);
        return vResult;
    }
    static void SplittedStringPrinter(string Splitter = " ") {
        vector <string> Result = StringSpliter(_Value, Splitter);
        for (short i = 0; i < Result.size(); i++) {
            cout << Result[i] << endl;
        }
    }
    static string LeftTrimmer(string Sentence) {
        for (int i =0; i < Sentence.length(); i++) {
            if (Sentence[i] != ' ') {
                return Sentence.substr(i,Sentence.length()-i);
            }
        }
        return "";
    }
    string LeftTrimmedString() {
        return LeftTrimmer(_Value);
    }
    static string RightTrimmer(string Sentence) {

        for (int i =Sentence.length()-1; i > 0; i--) {
            if (Sentence[i] != ' ') {
                return Sentence.substr(0,i+1);
            }
        }
        return "";

    }
    string RightTrimmedString() {
        return RightTrimmer(_Value);
    }
    static string Trimmer(string Sentence) {
        return LeftTrimmer(RightTrimmer(Sentence));
    }
    string TrimmedString() {
        return Trimmer(_Value);
    }
    static void TokenPrinter(vector<string> &vVector) {
        cout << "Tokens = " << vVector.size() << endl;
        for (string &s : vVector) {
            cout << s << endl;
        }
    }
    void TokenPrinter() {
        return TokenPrinter(StringSpliter(_Value));
    }
    string StringJoin(vector<string> &S, string Splitter) {
        string String = "";
        for (string &Word : S ) {
            String += Word + Splitter;
        }
        return String.substr(0, String.length()-Splitter.length());
    }
    static string StringJoiner() {
        return StringJoin(StringSpliter(_Value, string Spliter = " "), string Splitter = " ");
    }
    string StringReverser(vector<string> &vIn) {
        string Reversed ="";
        for (int i = vIn.size()-1; i >= 0; i--) {
            Reversed += vIn[i];
            if (i != 0) Reversed += " ";
        }
        return Reversed;
    }
    static string StringReverser() {
        return StringReverser(StringSpliter(_Value));
    }
    static void StringReplacer(vector<string> &S, string Target, string Replacement ) {
        for (string &Word : S) {
            if (Word == Target) Word = Replacement;
        }
    }
    //need edit
    void StringReplacer() {
         StringReplacer(StringSpliter(_Value, string Spliter = " "), _Value, _Value);
    }
    static string WordCap(string Input ){
        string OutPut;
        for (int i = 0; i < Input.length(); i++) {
            OutPut += toupper(Input[i]);
        }
        return OutPut;
    }
    string WordCap() {
        return WordCap(_Value);
    }
    static string PunctuationRemover(string S) {
        string Result = "";
        for (int i = 0; i < S.length(); i++) {
            if(!ispunct(S[i])) Result += S[i];
        }
        return Result;
    }
    string PunctuationRemint() {
        return PunctuationRemover(_Value);
    }
};