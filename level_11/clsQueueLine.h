#pragma once
#include "queue"
#include "stack"
#include <iostream>
#include "clsDate.h"
using namespace std;


class clsQueueLine {
private:
    int _TicketsCount = 0;
    int _ServingTime = 0 ;
    string _pref = "";

    class clsTicket {
    private:
        short _Order = 0;
        string _pref;
        string _DateTime;
        short _WaitingClients;
        short _WaitingTime = 0;
        short _ExpectedServingTime;
        public:
        clsTicket(string Pref, short Number, short WatingClients, short WatingTime) {
            clsMyDate Date;
            _pref = Pref;
            _Order = Number;
            _DateTime = to_string(Date.GetDay()) + "/"
            + to_string(Date.GetMonth()) + "/"
            + to_string(Date.GetYear())
            + " - " + to_string(Date.GetHour())
            + ":" + to_string(Date.GetMinute())
            + ":" + to_string(Date.GetSecond());;
            _WaitingClients = WatingClients;
            _WaitingTime = WatingTime;

        }
        string Pref() {
            return _pref;
        }
        short Order() {
            return _Order;
        }
        string TicketName() {
            return _pref + " " + to_string(_Order);
        }
        string TicketDate() {
            return _DateTime;
        }
        short WatingClients() {
            return _WaitingClients;
        }
        short ExpectedServingTime() {
            return _WaitingTime * _WaitingClients;
        }
        void Print() {
            cout << "\t\t\t\************************************";
            cout << "\t\t\t\ " << TicketName();
            cout << "\t\t\t\ " << TicketDate();
            cout << "\t\t\t\ " << "Waiting Clients: " << WatingClients();
            cout << "\t\t\t\ " << "Serve in Time: "
            << ExpectedServingTime()
            << "Minutes." << endl;
            cout << "\t\t\t\************************************";
        }
    };

    public:

    queue<clsTicket> Queue;
    clsQueueLine(string Pref, short WaitingTime) {
        _pref = Pref;
        _TicketsCount = 0;
        _ServingTime = WaitingTime;
    };
    //IssueTicket Method
    void IssueTicket() {
        _TicketsCount ++;
        clsTicket Ticket(_pref, _TicketsCount, WaitingClients(), _ServingTime);
        Queue.push(Ticket);
    };
    short WaitingClients() {
        return Queue.size();
    }
    //PrintAllTickets
    string WhoIsNext() {
        if (Queue.empty()) {
            return "No client to serve";
        }
        else {
            return Queue.front().TicketName();
        }
    }
    bool ServeNext() {
        if (Queue.empty()) {
            return false;
        }else {
            Queue.pop();
            return true;
        }
    }
    short ServedClients() {
        return _TicketsCount - WaitingClients();
    }


    void PrintInfo() {
        cout << "*************************************"<<endl;
        cout << "\t\t Queue Info "<<endl;
        cout << "*************************************"<<endl;
        cout << "\t\tPrefix: " << _pref << endl;
        cout << "\t\tTotal Tickets : " << _TicketsCount << endl;
        cout << "\t\tServed Clients: " << ServedClients() << endl;
        cout << "\t\tWaiting Clients: " << WaitingClients() << endl;
        cout << "*************************************"<<endl;
    }
    //PrintTicketsLineRTL
    void PrintTicketsLineRTL() {

        if (Queue.empty()) {
            cout << "Tickets: No current tickets";
        }else {
            cout << "Tickets: ";
        }

            queue <clsTicket> Tickets = Queue;
            while (!Tickets.empty()) {
                clsTicket Ticket = Tickets.front();
                cout << Ticket.TicketName() << " <-- ";
                Tickets.pop();
            }
    }
    //PrintTicketsLineLTR
    void PrintTicketsLineLTR() {
        queue <clsTicket> Tickets = Queue;
        stack <clsTicket> ReversedTickets;
        if (Queue.empty()) {
          cout << "Tickets: No current tickets";
        }
        else {
            cout << "Tickets: ";
        }
        while (!Tickets.empty()) {
            ReversedTickets.push(Tickets.front());
            Tickets.pop();
        }
        while (!ReversedTickets.empty()) {
            cout << ReversedTickets.top().TicketName() << " --> ";
            ReversedTickets.pop();
        }
        cout << endl;
    }

    void PrintAllTickets() {
            cout << "\t\t\t\t   ----Tickets----";
        if (Queue.empty()) {
            cout << "\t\tNo current tickets";
        }else {
            queue <clsTicket> Tickets = Queue;
            while (!Tickets.empty()) {
                Tickets.front().Print();
                Tickets.pop();
            }
        }
    }
};