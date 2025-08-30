#include <iostream>
using namespace std;
#include "clsEmployee.h"
#include "clsPerson.h"

int main() {

    clsEmployee Employee1("carlos", "costa", "carlos@mail.com", "7952583465",
        105, "junior SWE", "Development", 500);
    Employee1.PrintData();

    return 0;
}