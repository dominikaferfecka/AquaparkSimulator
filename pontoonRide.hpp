#ifndef PONTOONRIDE_H
#define PONTOONRIDE_H

#include <iostream>
#include <string>
#include "attraction.hpp"
using namespace std;

class PontoonRide : public Attraction
{
public:
    PontoonRide(string name = "pontoon ride", double ticketPrice = 7, int timeUnits = 7, bool forKids = true);
};

#endif