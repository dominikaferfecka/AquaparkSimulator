#ifndef SAUNA_H
#define SAUNA_H

#include <iostream>
#include <string>
#include "attraction.hpp"

using namespace std;

class Sauna : public Attraction
{

public:
    Sauna(string name = "sauna", double ticketPrice = 10, int timeUnits = 10, bool forKids = false);
};

#endif
