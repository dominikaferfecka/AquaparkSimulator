#ifndef AQUABAR_H
#define AQUABAR_H

#include <iostream>
#include <string>
#include "attraction.hpp"
using namespace std;

class AquaBar : public Attraction
{
public:
    AquaBar(string name = "aqua bar", double ticketPrice = 20, int timeUnits = 10, bool forKids = false);
};

#endif