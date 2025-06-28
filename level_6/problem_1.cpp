#include <iostream>
#include <string>
using namespace std;

int ReadInput(){
int Input;
cout << "Please enter a number? ";
cin >> Input;
return Input;
}

string NumberToText(int Number){

    if(Number == 0){
        return "";
    }if(Number >= 1 && Number <= 19){
        string Teen [] = {"", "One","Two","Three","Four","Five","Six","Seven", "Eight",
        "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen",
        "Seventeen","Eighteen","Nineteen"};
        return Teen[Number] + " ";
    }if(Number >= 20 && Number <= 99){
        string tens [] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return tens[Number / 10] + " " + NumberToText(Number % 10) ;

    }if(Number >= 100 && Number <= 199) {
        return " one Hundred " + NumberToText(Number % 100);
    }if(Number >= 200 && Number <= 999){
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100) ;
    }if(Number >= 1000 && Number <= 1999){
        return " One Thousand " + NumberToText(Number % 1000) ;
    }if(Number >= 2000 && Number <= 999999){
        return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000) ;
    }if(Number >= 1000000 && Number <= 1999999){
        return " One Milon " + NumberToText(Number % 1000000) ;
    }if(Number >= 2000000 && Number <= 999999999){
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }if(Number >= 1000000000 && Number <= 1999999999){
        return "One Billion " + NumberToText(Number % 1000000000) ;
    }else{
        return NumberToText(Number /10000000000) + "Billions" + NumberToText(Number % 1000000000) ;
    }
}



int main(){
cout << NumberToText(ReadInput());
return 0;
};