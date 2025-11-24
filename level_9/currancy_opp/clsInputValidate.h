#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"
#include <limits>
using namespace std;

class clsInputValidate{

    public:


     template <typename T> static bool IsNumberBetween(T Number,T MinNumber, T MaxNumber) {
        return ((Number >= MinNumber) && (Number <= MaxNumber));
    }
    template <typename T> static T ReadNumber() {
         T Number = 0;
         while (!(cin>> Number)) {
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(),'\n');
             cout << "Invalid Number entered. Enter Number: " << endl;
         }
         return Number;
     }

    static bool IsDateBetween(clsMyDate Date, clsMyDate From, clsMyDate To) {
        if (clsMyDate::DateIsLessThan(To, From)) {
            swap(From, To);
        }
        return clsMyDate::DateIsLessThanOrEqual(From,Date) && clsMyDate::DateIsLessThanOrEqual(Date,To);
    }
    static bool IsValidDate(clsMyDate Date) {
        return clsMyDate::IsValidDate(Date);
    }

    template <typename T> static T ReadIntNumberBetween(T Start, T End)
    {
         T Number = ReadNumber<T>();
        while (!IsNumberBetween( Number,Start, End)) {
                Number = ReadNumber<T>();
            }
            return Number;
    }

    static string ReadString(string Message = "")
    {
        string  S1="";
        // Usage of std::ws will extract all the whitespace character
        cout << Message;
        getline(cin >> ws, S1);
        return S1;
    }

};