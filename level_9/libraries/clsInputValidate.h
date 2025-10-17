#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "string_lib.h"
#include <limits>
using namespace std;

class clsInputValidate{

    public:

    static bool IsNumberBetween(int Number, int MinNumber, int MaxNumber){
        return ((Number >= MinNumber) && (Number <= MaxNumber));
    }
    static bool IsNumberBetween(double Number, int MinNumber, double MaxNumber){
        return ((Number >= MinNumber) && (Number <= MaxNumber));
    }
    static bool IsNumberBetween(float Number , float MinNumber, float MaxNumber) {
        return ((Number >= MinNumber) && (Number <= MaxNumber));

    }
    static int ReadIntNumber(string Error = "Invalid number") {
        int Number = 0;
        while (!(cin>> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << Error;
        }
        return Number;
    }
    static double ReadDNumber(string Error = "Invalid number") {
        double Number = 0;
        while (!(cin>> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << Error;
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

    static bool ReadIntNumberBetween( int Start, int End, string Message) {
        cout << "Please enter a number in the range " << Start << ":" << End << "\n";
        int Number = ReadIntNumber();
        while (!IsNumberBetween(Number,Start, End)) {
                cout << Message << "\n";
                Number = ReadIntNumber();
            }
            return true;
        }

};