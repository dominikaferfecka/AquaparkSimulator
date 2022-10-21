#ifndef ATTRACTION_H
#define ATTRACTION_H
#include <iostream>
#include <string>
#include "attraction-interface.hpp"
using namespace std;

class Attraction : public IAttraction
{
    string name = "";
    double ticketPrice = 0;
    int timeUnits = 0; // max time customer can spend there acc. to ticket
    bool forKids = false;

protected:
    Attraction();
    Attraction(string n, double tP, int tU, bool fK);

public:
    // virtual ?

    // getters
    string getName();
    double getTicketPrice();
    int getTimeUnits();
    bool ifForKids();
    // setters
    void setName(string nNa);
    void setTicketPrice(double nTP);
    void setTimeUnits(int nTU);
    void setForKids(bool nfK);
};

#endif