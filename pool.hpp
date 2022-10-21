#ifndef POOL_H
#define POOL_H

#include <iostream>
#include <string>
#include "attraction.hpp"
using namespace std;

class Pool : public Attraction
{
public: // parametry bazowe
    Pool(string name = "pool", double ticketPrice = 15, int timeUnits = 15, bool forKids = true);
};

#endif
