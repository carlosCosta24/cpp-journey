#include <iostream>
using namespace std;

class clsA
{
private:
    // only accessible inside this class, neither derived classes nor outside class
    string _Name;
    void NamePrinter()
    {
        cout << _Name << endl;
    }

protected:
    // only accessible inside his class and all derived classes, but not outside class
    double Salary;
    void setSalary(double salary)
    {
        Salary = salary;
    }
public:
    string Name;
    void setName(string name) {
        Name = name;
    }
    string GetName() {
        return Name;
    }
};


class clsB : private clsA
{
public:

   void SayHi() {
       cout << "Hello from class B"<< endl;
   }
};

class clsC : public clsB {
    public:
    void SayGoodbye() {
        cout << "goodbye from class C"<< endl;
    }
};

int main()
{
    clsC c;
    clsB b;

    b.SayHi();
    c.SayGoodbye();
    return 0;
}
