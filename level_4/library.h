#pragma once
#include <iostream>
using namespace std;

namespace MyLib
{
    void Print()
    {
        cout << "first message from the first library :-)" << endl;
    }
    int Calculator(int First, int Second) {
        return First + Second;
    }
}