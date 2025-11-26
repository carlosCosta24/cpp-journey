#pragma once
#include <iostream>
#include <sstream>
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
    static short Length(string S1)
    {
        return S1.length();
    };
    short Length()
    {
        return _Value.length();
    };
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
        return CountWords(_Value);
    }
    static string LowerFirstLetter(const string& Str ) {
        string Result = Str;
        bool IsFirstLetter = true;
        for (int i =0; i < Result.length(); i++) {
            if (Result[i] != ' ' && IsFirstLetter) {
                Result[i] = tolower(Result[i]);
            }
            IsFirstLetter = (Result[i] == ' ' ? true : false);
        }
        return Result;
    }
    void LowerFirstLetter() {
        _Value = LowerFirstLetter(_Value);
    }
    static string CapitalFirstLetter(const string& Str ) {
        string Result = Str;
        bool IsFirstLetter = true;
        for (int i =0; i < Result.length(); i++) {
            if (Result[i] != ' ' && IsFirstLetter) {
                Result[i] = toupper(Result[i]);
            }
            IsFirstLetter = (Result[i] == ' ' ? true : false);
        }
        return Result;
    }
    void CapitalFirstLetter() {
         _Value = CapitalFirstLetter(_Value);
    }
    static string CapitalString(string String ) {
        for (int i =0; i < String.length(); i++) {
            String[i] = toupper(String[i]) ;
        }
        return String ;
    }
    void CapitalString() {
        _Value = CapitalString(_Value);
    }
    static string LowerString(string String ) {
        for (int i =0; i < String.length(); i++) {
            String[i] =tolower(String[i]) ;
        }
        return String ;
    }
    void LowerString() {
        _Value = LowerString(_Value);
    }
    static char CaseInverter(char Chr ) {

        return isupper(Chr) ? Chr = tolower(Chr): Chr = toupper(Chr) ;

    }
    static string InvertAllLetterCase(string Str) {
        string Result = Str;
        for (int i =0; i < Result.length(); i++) {
            Result += isupper(Result[i]) ? tolower(Result[i]) : toupper(Result[i]);
        }
        return Result;
    }
    void InvertAllLetterCase() {
        _Value = InvertAllLetterCase(_Value);
    }
    enum enWhatToCount {SmallLetters = 0, CapitalLetters = 1, All =3};
    static short CaseLetterCounter(string Str, enWhatToCount Choice = enWhatToCount::All) {
        if (Choice == enWhatToCount::All) {
            return Str.length();
        }
        short Counter = 0;
        for(int i =0 ; i <Str.length(); i++){

            if(Choice == enWhatToCount::CapitalLetters && isupper(Str[i]))
                Counter ++ ;
            if (Choice == enWhatToCount::SmallLetters && islower(Str[i]))
                Counter++ ;
        }
        return Counter;
    }
    static short CountCapitalLetters(string Str) {
        short Counter = 0;
        for (int i =0; i < Str.length(); i++) {
            if(isupper(Str[i])) Counter++;
        }
        return Counter;
    }
    short CountCapitalLetters() {
        return CountCapitalLetters(_Value);
    }
    static short CountSmallLetters(string Str) {
        short Counter = 0;
        for (short i =0; i < Str.length(); i++) {
            if(islower(Str[i])) Counter++;
        }
        return Counter;
    }
    short CountSmallLetters() {
        return CountSmallLetters(_Value);
    }
    static short CountSpecificLetter(string Str, char Chr, bool MatchCase = false) {
        short Counter = 0;
        if (MatchCase == true) {
            for (short i =0; i < Str.length(); i++) {
                if( Str[i] == Chr )Counter++;
            }
        }else {
            for (short i =0; i < Str.length(); i++) {
                char Current = tolower(Str[i]);
                Chr = tolower(Chr);
                if (Current == Chr) {
                    Counter++;
                }
            }
        }
        return Counter;
    }
    short CountSpecificLetter(char Letter, bool Match = true) {
        return CountSpecificLetter(_Value,Letter,Match);
    }
    static bool IsVowel(char Letter) {
        char Vowels[5] = {'A', 'E', 'I', 'O', 'U'};
        char Cur = toupper(Letter);

        for (char Vowel : Vowels) {
            if (Cur == Vowel ) return true;
        }
        return false;
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
    static vector<string> StringSplitter(string S, string Splitter = "/*/") {
        vector<string> vResult;
        short Pos = 0;
        string Word;

        while ((Pos = S.find(Splitter)) != string::npos) {
            Word = S.substr(0,Pos);
            if (Word != "") vResult.push_back(Word);
            S.erase(0, Pos + Splitter.length());
        }
        if (S != "") vResult.push_back(S);
        return vResult;
    }
    vector<string> StringSplit(string Splitter) {
        return StringSplitter(_Value, Splitter);
    }
    static string PunctuationRemover(string S) {
        string Result = "";
        for (int i = 0; i < S.length(); i++) {
            if(!ispunct(S[i])) Result += S[i];
        }
        return Result;
    }
    void PunctuationRemove() {
        _Value = PunctuationRemover(_Value);
    }
    static string LeftTrimmer(string Sentence) {
        for (int i =0; i < Sentence.length(); i++) {
            if (Sentence[i] != ' ') {
                return Sentence.substr(i,Sentence.length()-i);
            }
        }
        return "";
    }
    void LeftTrimmedString() {
        _Value = LeftTrimmer(_Value);
    }
    static string RightTrimmer(string Sentence) {

        for (int i =Sentence.length()-1; i >= 0; i--) {
            if (Sentence[i] != ' ') {
                return Sentence.substr(0,i + 1);
            }
        }
        return "";

    }
    void RightTrimmedString() {
        _Value = RightTrimmer(_Value);
    }
    static string Trimmer(string Sentence) {
        return LeftTrimmer(RightTrimmer(Sentence));
    }
    void TrimmedString() {
        _Value = Trimmer(_Value);
    }
    static string JoinString(vector<string> &S, string Splitter) {
        string Str = "";
        ostringstream oss;
        for (string &Word : S ) {
            oss << Word << Splitter;
        }
        Str = oss.str();
        if (S.size() > 0) {
            return Str.substr(0, Str.length()-Splitter.length());
        }else {
            return Str;
        }
    }
    static string JoinString(string arrString[], short Length, string Splitter) {
        string Result = "";
        for (int i =0; i < Length; i++) {
            Result += arrString[i] + Splitter;
        }
        return Result.substr(0, Result.length() - Splitter.length());
    }
    static string StringReverser(string Input) {
        string Reversed ="";
        vector<string>vWords;

        vWords = StringSplitter(Input," ");
        // declare the iterator
        vector<string>::iterator it = vWords.end();

        while (it != vWords.begin()) {
            --it ;
            Reversed += *it + " ";
        }
        Reversed = Reversed.substr(0, Reversed.length() - 1);
        return Reversed;
    }
    void  StringReverser() {
        _Value = StringReverser(_Value);
    }
    static string StringReplacer(string S, string Target, string Replacement, bool Match = true ) {
        vector<string>vWords;
        vWords = StringSplitter(S, " ");

        for (string &Word : vWords) {

            if (Match && Target == Word) {
                Word = Replacement;
            }
            else
            {

                if (LowerString(Word) == LowerString(Target))
                {
                    Word = Replacement;
                }
            }
        }
        return JoinString(vWords," ");
    }
    string StringReplacer(string Target, string& Replacement) {
        return StringReplacer(_Value, Target, Replacement);
    }
    static char Capitalize(char & Character) {
        Character = toupper(Character);
        return Character;
    }
    static string Capitalize(string & sentence) {

        for(char & C : sentence) {
            C = Capitalize(C);
        }
        return sentence;
    }

    // static void SplittedStringPrinter(string Splitter = " ") {
    //     vector <string> Result = StringSpliter(GetValue(), Splitter);
    //     for (short i = 0; i < Result.size(); i++) {
    //         cout << Result[i] << endl;
    //     }
    // }
    /*
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
        WordPrinter(_Value);
   }
   */
    /*
static void FirstLetterPrinter(string String ) {
    bool IsFirstLetter = true;

    for (int i =0; i < String.length(); i++) {
        if (String[i] != ' ' && IsFirstLetter) {
            cout << String[i]<< endl;
            break;
        }
        IsFirstLetter = (String[i] == ' ' ? true : false);
    }
}
void FirstLetterPrinter() {
     _Value = FirstLetterPrinter(_Value);
}
*/


    // static void TokenPrinter(vector<string> &vVector) {
    //     cout << "Tokens = " << vVector.size() << endl;
    //     for (string &s : vVector) {
    //         cout << s << endl;
    //     }
    // }
    // void TokenPrinter() {
    //     TokenPrinter(StringSpliter(_Value));
    // }
    // static string WordCap(string Input ){
    //     string OutPut;
    //     for (int i = 0; i < Input.length(); i++) {
    //         OutPut += toupper(Input[i]);
    //     }
    //     return OutPut;
    // }
    // string WordCap() {
    //     return WordCap(_Value);
    // }

};