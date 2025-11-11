#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsUtil {
    public:
    enum enChar
    {
    enSmall = 1,
    enCapital = 2,
    enDigit = 3,
    enMix = 4,
    };
    static void Srand() {
        srand((unsigned)time(NULL));
    }
    static int RandomNumber(int From, int To ){
        int RandNum = rand() % (To - From + 1) + From;
        return RandNum;
    }
    static char GetRandomChar(enChar Char){
        if (Char == enMix) {
            Char = (enChar) RandomNumber(1,3);
        }
        switch (Char)
        {
            case enChar::enSmall:
                return char(RandomNumber(97, 122));
                break;
            case enChar::enCapital:
                return char(RandomNumber(65, 90));
                break;
            case enChar::enMix:
                return char(RandomNumber(33, 47));
                break;
            case enChar::enDigit:
                return char(RandomNumber(48, 57 ));
            default:
                return char(RandomNumber(65, 90));
                break;
        }
}
    static string WordGenerator(enChar Char, short Num)
    {
        string Word;
        for (int i = 0; i <= Num; i++)
        {
            Word += GetRandomChar(Char);
        }
        return Word;
    }
    static string KeyGenerator(enChar Option = enCapital)
    {
        string Key = "";

        Key =  WordGenerator(Option, 4) + "-";
        Key += WordGenerator(Option, 4) + "-";
        Key += WordGenerator(Option, 4) + "-";
        Key += WordGenerator(Option, 4);

        return Key;
    }
    static void KeysGenerator(int Length, enChar Option)
    {
        for (int i = 0; i <= Length; i++)
        {
             cout << "Key [" << i << "]" << KeyGenerator(Option);
        }
    }
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }
    static void FillArrayWithRandomWords(string Arr[100], short ArrLength, enChar Option, short WordLength) {
        for (int i = 0; i < ArrLength; i++) {
            Arr[i] = WordGenerator(Option, WordLength);
        }
    }
    static void FillArrayWithRandomKeys(string Arr[100], short ArrLength, enChar Option) {
        for (int i = 0; i < ArrLength; i++) {
            Arr[i] = KeyGenerator(Option);
        }
    }
    static void Swap(int &N1, int &N2)
    {
        int temp;
        temp = N1;
        N1 = N2;
        N2 = temp;
    }
    static void Swap(double &N1, double &N2)
    {
        double temp;
        temp = N1;
        N1 = N2;
        N2 = temp;
    }
    static void Swap(bool &N1, bool &N2)
    {
        bool temp;
        temp = N1;
        N1 = N2;
        N2 = temp;
    }
    static void Swap(char &N1, char &N2)
    {
        char temp;
        temp = N1;
        N1 = N2;
        N2 = temp;
    }
    static void Swap(string &N1, string &N2)
    {
        string temp;
        temp = N1;
        N1 = N2;
        N2 = temp;
    }
    static void Swap(clsMyDate& FirstDate, clsMyDate& SecondDate)
    {
        clsMyDate temp;
        temp = FirstDate;
        FirstDate = SecondDate;
        SecondDate = temp;
    }
    static void ShuffleArray(int arr[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            swap(arr[RandomNumber(1, length) - 1], arr[RandomNumber(1, length) - 1]);
        }
    }
    static void ShuffleArray(string arr[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            swap(arr[RandomNumber(1, length) - 1], arr[RandomNumber(1, length) - 1]);
        }
    }
    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t +="\t";
            cout << t;
        }
        return t;

    }
    static string Encryption(string Word, short EncryptionKey = 10)
    {
        string result = "";
        for (int i = 0; i < Word.length(); i++)
        {
            result += char((int)Word[i] + EncryptionKey);
        }
        return result;
    }
    static string Decryption(string Encrypted, short DecryptionKey = 10)
    {

        string decrypted = "";
        for (int i = 0; i < Encrypted.length(); i++)
        {
            decrypted += (char((int)Encrypted[i]) - DecryptionKey);
        }
        return decrypted;
    }
    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

    static char Capitalize(const char & Character) {
        return toupper(Character);
    }

    };