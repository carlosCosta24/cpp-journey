#pragma once
#include "clsDate.h"
#include "string_lib.h"
using namespace std;

class clsInputValidate{

    public:

    static bool IsNumberBetween(int Number, int MinNumber, int MaxNumber){
        return ((Number >= MinNumber) && (Number <= MaxNumber));
    }
    static bool IsNumberBetween(double Number, int MinNumber, double MaxNumber){
        return ((Number >= MinNumber) && (Number <= MaxNumber));
    }
    static float IsNumberBetween(float Number , float MinNumber, float MaxNumber) {
        return ((Number >= MinNumber) && (Number <= MaxNumber));

    }
    static bool IsDateBetween(clsMyDate Date, clsMyDate From, clsMyDate To) {
        if (clsMyDate::DateIsLessThan(To, From)) {
            swap(From, To);
        }
        return clsMyDate::DateIsLessThanOrEqual(From,Date) && clsMyDate::DateIsLessThanOrEqual(Date,To);
    }


};