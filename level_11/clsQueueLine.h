#pragma once
#include "clsMyQueueArr.h"
#include <iostream>
#include "clsDate.h"
using namespace std;


class clsQueueLine {
    private:
    class clsTicket {
    public:
        clsMyDate IssueDate;
        int Order;
        int ServeTime;
        string Id;
    };
    //date and time class
    clsMyDate _Date = clsMyDate();
    string _pref;
    int _Time;
    clsMyQueueArr<clsTicket> _Queue;
    int _QueueLength = 0;
    int _Served = 0;
    int _Waiting = 0;
    int _TicketsCount = 0;

    public:
    clsQueueLine(string Pref, int WaitingTime) {
        _pref = Pref;
        _Time = WaitingTime;
    };
    //IssueTicket Method
    void IssueTicket() {
        clsTicket Ticket;
        Ticket.Id = to_string(_QueueLength) + " " + _pref;
        Ticket.IssueDate = to_string(_Date.GetDay()) + "/"
        + to_string(_Date.GetMonth()) + "/"
        + to_string(_Date.GetYear())
        + " - " + to_string(_Date.GetHour())
        + ":" + to_string(_Date.GetMinute())
        + ":" + to_string(_Date.GetSecond());
        Ticket.Order = _QueueLength + 1;
        Ticket.ServeTime = Ticket.Order * _Time;
        _Queue.Push(Ticket);
        _QueueLength++;

    };
    //PrintAllTickets
    void TicketInfo(clsTicket Ticket) {
        cout << Ticket.Id << endl;
        cout << Ticket.IssueDate << endl;
        cout << "Waiting Clients: " << Ticket.QueueLength -1 << endl;
        cout << "Serving Time: " << Ticket.ServeTime << " Minutes."<< endl;
    }
    void QueueInfo() {
        cout << "Prefix: " << _pref << endl;
        cout << "Total Tickets : " << _QueueLength << endl;
        cout << "Served Clients: " << _Served << endl;
        cout << "Waiting Clients: " << _Waiting << endl;
    }
    void PrintInfo() {
        cout << "*******************************";
        cout << "\t\t\t\t Queue Infor ";
        cout << "*******************************";
        QueueInfo();
        clsMyQueueArr <clsTicket> Tickets = _Queue;
        if (Tickets.empty()) {
            TicketInfo(Tickets.front());
            Tickets.pop();
        }
    }
    //PrintTicketsLineRTL
    void PrintTicketsLineRTL() {
        clsMyQueueArr <clsTicket> Tickets;

        while (Tickets.Size() != 0) {
            TicketInfo(Tickets.Front().Id);
            cout << "--> ";
            Tickets.Pop();
        }
    }
    //PrintTicketsLineLTR
    void PrintTicketsLineLTR() {
        clsMyQueueArr <clsTicket> Tickets;
        Tickets.Reverse();
        while (Tickets.Size() != 0) {
            TicketInfo(Tickets.Front().Id);
            cout << "<-- ";
            Tickets.Pop();
        }
    }
    //ServeNextClient
    void ServeNewClient() {
        if (_QueueLength == 0) {
            return;
        }
            _Queue.Pop();
            _QueueLength--;
            _Served++;
            _Waiting
    }

};