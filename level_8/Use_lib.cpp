#include <iostream>
#include "string_lib.h"
using namespace std;

int main() {
    clsString MyString ("Carlos costa ");

    //string.InvertAllStringLettersCase();
    cout << clsString::CapitalString("carlos costa ") << endl;
    clsString Second  ("Ali Ahmed");

    cout << "String = " << MyString.GetValue() << endl;
    cout << "String2 = " << Second.GetValue() << endl;
   
    cout << "Number of words: " << MyString.CountWord() <<endl;

    cout << "Number of words: " << clsString::CountWords("Fadi ahmed rateb omer") << endl;

    cout << "Number of words: " <<
        clsString::CountWords("Mohammed Saqer Abu-Hadhoud") << endl;

    //----------------
    clsString String3("hi how are you?");
    
    cout << "String 3 = " << String3.GetValue() << endl;

    cout << "String Length = " <<String3.Length() << endl;

    String3.CapitalFirstLetter();
    cout << String3.GetValue() << endl;

    //----------------

    String3.LowerFirstLetter();
    cout << String3.GetValue() << endl;

    //----------------

    String3.CapitalString();
    cout << String3.GetValue() << endl;

    //----------------

    String3.LowerString();
    cout << String3.GetValue() << endl;

    //----------------

    cout << "After inverting a : "
        << clsString::CaseInverter('a') << endl;

    //----------------

    String3.GetValue() = "AbCdEfg";
    
    String3.InvertAllLetterCase();
    cout << String3.GetValue() << endl;

    String3.InvertAllLetterCase();
    cout << String3.GetValue() << endl;

    //----------------

    cout << "Capital Letters count : "
        << clsString::CaseLetterCounter("Mohammed Abu-Hadhoud",clsString::CapitalLetters)
        << endl<<endl;

    //----------------

    String3.GetValue() = "Welcome to Jordan";
    cout << String3.GetValue() << endl;

    cout << "Capital Letters count :" << String3.CountCapitalLetters() << endl;

    //----------------

    cout << "Small Letters count :" << String3.CountSmallLetters() << endl;

    //----------------

    cout << "vowels count :" << String3.VowelCount() << endl;

    //----------------

    cout << "letter E count :" << String3.CountSpecificLetter('E',false) << endl;

    //----------------

    cout << "is letter u vowel? " << clsString::IsVowel('u')
         << endl;

    //----------------

    cout << "Words Count" << String3.CountWord()
        << endl;

    //----------------


    vector<string> vString;

    vString = String3.StringSplit(" ");

    cout << "\nTokens = " << vString.size() << endl;

    for (string& s : vString)
    {
        cout << s << endl;
    }

    //----------------

    //Tirms
    String3.GetValue()=  "    Mohammed Abu-Hahdoud     ";
    cout << "\nString     = " << String3.GetValue();
    
    String3.GetValue() = "    Mohammed Abu-Hahdoud     ";
    String3.LeftTrimmedString();
    cout << "\n\nTrim Left  = " << String3.GetValue();

    //----------------

    String3.GetValue() = "    Mohammed Abu-Hahdoud     ";
    String3.RightTrimmedString();
    cout << "\nTrim Right = " << String3.GetValue();

    //----------------

    String3.GetValue() = "    Mohammed Abu-Hahdoud     ";
    String3.TrimmedString();
    cout << "\nTrim       = " << String3.GetValue();

    //----------------

    //Joins
    vector<string> vclsString = { "Mohammed","Faid","Ali","Maher" };
    
    cout << "\n\nJoin String From Vector: \n";
    cout << clsString::JoinString(vclsString, " ");


    string arrString[] = { "Mohammed","Faid","Ali","Maher" };

    cout << "\n\nJoin String From array: \n";
    cout << clsString::JoinString(arrString, 4, " ");

    //----------------

    String3.GetValue() = "Mohammed Saqer Abu-Hahdoud";
    cout << "\n\nString     = " << String3.GetValue();

    String3.StringReverser();
    cout << "\nReverse Words : " << String3.GetValue()
        << endl;
    
    //---------------

    String3.GetValue() = "Mohammed Saqer Abu-Hahdoud";
   // cout << "\nReplace : " << String3.StringReplacer("Mohammed", "Sari")
      //  << endl;
    
    //---------------

    String3.GetValue() = "This is: a sample text, with punctuations.";
    cout << "\n\nString     = " << String3.GetValue();

    String3.PunctuationRemove();
    cout << "\nRemove Punctuations : " << String3.GetValue()
        << endl;

    //---------------
    return 0;
}