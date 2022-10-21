#include "attraction.hpp"
#include <iostream>
#include <string>

using namespace std;

// constructors
Attraction::Attraction(){};
Attraction::Attraction(string n, double tP, int tU, bool fK)
{
    this->name = n;
    this->ticketPrice = tP;
    this->timeUnits = tU;
    this->forKids = fK;
};

// getters
string Attraction::getName()
{
    return this->name;
};
double Attraction::getTicketPrice()
{
    return this->ticketPrice;
};
int Attraction::getTimeUnits()
{
    return this->timeUnits;
};
bool Attraction::ifForKids()
{
    return this->forKids;
};

// setters
void Attraction::setName(string nN)
{
    this->name = nN;
};
void Attraction::setTicketPrice(double nTP)
{
    this->ticketPrice = nTP;
};
void Attraction::setTimeUnits(int nTU)
{
    this->timeUnits = nTU;
};

void Attraction::setForKids(bool nFK)
{
    this->forKids = nFK;
};
