#include <iostream>
#include <string>
using namespace std;

int ReadInput(){
int Input;
cout << "Please enter a number?";
cin >> Input;
return Input;
}

string NumberToText(int Number){
    if(Number == 0){
    return "Zero";
}if(Number >= 1 && Number <= 19){
    string Teen [] = {"", "One","Two","Three","Four","Five","Six","Seven", "Eight",
    "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen",
    "Seventeen","Eighteen","Nineteen"};
    return Teen[Number];
}if(Number >= 20 && Number <= 99){
    string Arr [] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
    return Arr[Number / 10] + " " + NumberToText(Number % 10) ;

}if(Number >= 100 && Number <= 9999) {
    return " Hundred " + NumberToText(Number % 100);
}
    return "";
};




int main(){
cout << NumberToText(ReadInput());
return 0;
};