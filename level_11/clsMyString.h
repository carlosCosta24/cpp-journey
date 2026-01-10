#pragma once
#include <stack>
#include <iostream>
using namespace std;

class clsMyString {
private:
    stack <string> _MyMainStack;
    stack <string> _MyTempStack;
    string _S = "";
public:

    void SetValue(string New) {
        _MyTempStack.push(_S);
        _S = New;
    }
    string Get() {
     return _S;

    }
    void Undo() {
        if (!_MyMainStack.empty()) {
            _MyTempStack.push(_S);
            _S = _MyMainStack.top();
            _MyMainStack.pop();
        }
    }
    void Redo() {
        if (!_MyTempStack.empty()) {
            _MyMainStack.push(_S);
            _S = _MyTempStack.top();
            _MyTempStack.pop();
        }
    }




};
