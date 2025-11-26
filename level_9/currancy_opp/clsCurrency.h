#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsCurrency {
  private:

  enum enMood {enEmpty = 0, enUpdate =1 };
  enMood _Mood;
  string _Country;
  string _CurrencyCode;
  string _CurrencyName;
  float _CurrencyRate;

  static clsCurrency _ConvertLineToCurrencyObj(string Line, string Delimiter = "/*/") {
   // clsCurrency Currency;
    vector <string> vCurrencyElements = clsString::StringSplitter(Line);
    // this is my code, its ok but not optimal
    // Currency._Country = vCurrencyElements[0];
    // Currency._CurrencyCode = vCurrencyElements[1];
    // Currency._CurrencyName = vCurrencyElements[2];
    // Currency._CurrencyRate = stod(vCurrencyElements[3]);
    return clsCurrency(enMood::enUpdate, vCurrencyElements[0],
      vCurrencyElements[1],vCurrencyElements[2],stod(vCurrencyElements[3]));

  };
  static string _ConvertCurrencyObjToLine(clsCurrency Currency, string Delimiter = "/*/") {
    string Line = "";
    Line += Currency._Country + Delimiter;
    Line += Currency._CurrencyCode + Delimiter;
    Line += Currency._CurrencyName + Delimiter;
    Line += to_string(Currency._CurrencyRate);
    return Line;
  };
  static vector <clsCurrency> _LoadCurrenciesData() {
    vector <clsCurrency> vCurrenciesList;
    fstream file;
    file.open("CurrenciesList.txt", ios::in); //read mode;
    if (file.is_open()) {
      string Line;
      while (getline(file, Line)) {
        clsCurrency Currency = _ConvertLineToCurrencyObj(Line);
        vCurrenciesList.push_back(Currency);
      }
      file.close();
    }
    return vCurrenciesList;
  }
  static void _SaveCurrencyData(vector <clsCurrency> vCurrencyList) {

    fstream file;
    file.open("CurrenciesList.txt", ios::out); //edit mode
    string NewCurrencyLine;

    if (file.is_open()) {
      for (clsCurrency C : vCurrencyList) {
        NewCurrencyLine = _ConvertCurrencyObjToLine(C);
        file << NewCurrencyLine << endl;
      }
    }
    file.close();
  }
  void _Update() {
    vector <clsCurrency> vCurrencyList = _LoadCurrenciesData();
    for (clsCurrency & C : vCurrencyList) {
      if (C.GetCurrencyCode() == GetCurrencyCode()) {
        C = *this;
        break;

      }
    }
    _SaveCurrencyData(vCurrencyList) ;
  }

  static clsCurrency _GetEmptyCurrencyObj() {
    return clsCurrency(enMood::enEmpty,"","","",0);
  }

public:
  clsCurrency(enMood Mood, string Country, string currencyCode,
    string CurrencyName, float Rate) {
    _Mood = Mood;
    _Country = Country;
    _CurrencyCode = currencyCode;
    _CurrencyName = CurrencyName;
    _CurrencyRate = Rate;
  }

  bool IsEmpty() {
    return (_Mood == enMood::enEmpty);
  }
  string GetCountry() {
    return _Country;
  }
  string GetCurrencyCode() {
    return _CurrencyCode;
  }
  string GetCurrencyName() {
    return _CurrencyName;
  }
  void UpdateRate(float NewRate) {
    _CurrencyRate = NewRate;
    _Update();
  }
  float GetRate() {
    return _CurrencyRate;
  }
  static clsCurrency FindCurrencyByCode(string Code) {
    Code = clsString::CapitalString(Code);
    fstream file;
    file.open("CurrenciesList.txt", ios::in);
    if (file.is_open()) {
      string Line;
      while (getline(file, Line)) {
        clsCurrency Currency = _ConvertLineToCurrencyObj(Line);
        if (Currency._CurrencyCode == Code) {
          file.close();
          return Currency;
        }
      }
    file.close();
    }
    return _GetEmptyCurrencyObj();
  }

  static clsCurrency FindCurrencyByName(string Name) {
    fstream file;
    file.open("CurrenciesList.txt", ios::in);
    if (file.is_open()) {
      string Line;
      while (getline(file, Line)) {
        clsCurrency Currency = _ConvertLineToCurrencyObj(Line);
        if (clsString::CapitalString(Currency._Country) == clsString::CapitalString(Name)) {
          file.close();
          return Currency;
        }
      }
      file.close();
    }
    return _GetEmptyCurrencyObj();
  }
  static bool IsCurrencyExist(string Code) {
    clsCurrency Curency = clsCurrency::FindCurrencyByCode(Code);
    return (!Curency.IsEmpty());
  }
  static vector <clsCurrency> GetCurrencyList() {
    return _LoadCurrenciesData();
  }


};

