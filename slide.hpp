#ifndef SLIDE_H
#define SLIDE_H

#include <iostream>
#include <string>
#include "attraction.hpp"
using namespace std;

class Slide : public Attraction
{
public: // parametry bazowe
    Slide(string name = "slide", double ticketPrice = 5, int timeUnits = 5, bool forKids = true);
};

#endif