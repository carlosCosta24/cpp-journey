#include <iostream>
#include <string>
using namespace std;

class clsAgent {
    private:

    string _Name;
    int _ID;
    string _Secret_Message;

    protected:

    string _Session;

    public:
    string SetSecretMessage(string Private) {
         return _Secret_Message = Private;
    };
    void SecretMessage() {
        cout << _Secret_Message;
    }

    void setName(string name) {
        _Name = name;
    }
    string Name() {
        return _Name;
    }
    int ID() {
        return _ID;
    }

    void Print() {
        cout << Name();
    }

    friend class clsSpy;
};

class clsSpy {
    public:
    void PrintSecretMessage(clsAgent Agent) {
        cout << "This is the secret message from our inside agent:\n " << Agent._Secret_Message << endl;
    }

};

int main() {
    clsAgent Agent;
    clsSpy Spy;

    Agent.SetSecretMessage("The nuclear project is coming to the end !");

    Spy.PrintSecretMessage(Agent);

    return 0;
}