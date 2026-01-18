#include <iostream>
#include "clsQueueLine.h"
using namespace std;

int main() {
    clsQueueLine PayPills("A0", 10);

    PayPills.IssueTicket();
    PayPills.IssueTicket();
    PayPills.IssueTicket();


    cout << "Pay Bills Queue Info: " << endl;
    PayPills.PrintInfo();
    PayPills.PrintTicketsLineLTR();
    PayPills.PrintTicketsLineRTL();

;
    return 0;
}