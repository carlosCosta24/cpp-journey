//
// Created by carlos on 5/12/25.
//
#pragma once
#include <iostream>
using namespace std;
#ifndef MY_INPUT_H
#define MY_INPUT_H

#endif //MY_INPUT_H

namespace MyInput {
    int ReadNum(string Message) {
        int Num;
        cout<< Message;
        cin >> Num;
        return Num;

    }

}
