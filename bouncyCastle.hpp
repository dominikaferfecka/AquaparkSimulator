#ifndef BOUNCYCASTLE_H
#define BOUNCYCASTLE_H

#include <iostream>
#include <string>
#include "attraction.hpp"
using namespace std;

class BouncyCastle : public Attraction
{
public:
    BouncyCastle(string name = "bouncy castle", double ticketPrice = 15, int timeUnits = 15, bool forKids = true);
};

#endif