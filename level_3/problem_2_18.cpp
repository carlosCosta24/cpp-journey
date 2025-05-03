#include <iostream>
#include <string>
using namespace std;

string ReadName(string Message)
{
    string Password;

    cout << Message;
    getline(cin, Password);

    return Password;
}

string Encryption(string Word)
{
    string result = "";
    for (int i = 0; i < Word.length(); i++)
    {
        result += char(Word[i]) + 5;
    }
    return result;
}
string Decryption(string Encrypted)
{

    string decrypted = "";
    for (int i = 0; i < Encrypted.length(); i++)
    {
        decrypted += char(Encrypted[i]) - 5;
    }
    return decrypted;
}

void ResultPrinter()
{
    string Name = ReadName("Please Enter your name: ");
    cout << "Text Befor Encryption: " << Name << endl;
    cout << "Text After Encryption: " << Encryption(Name) << endl;
    cout << "Text After Decryption: " << Decryption(Encryption(Name)) << endl;
}

int main()
{
    ResultPrinter();
    return 0;
}