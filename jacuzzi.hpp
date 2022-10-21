#ifndef JACUZZI_H
#define JACUZZI_H

#include <iostream>
#include <string>
#include "pool.hpp"
using namespace std;

class Jacuzzi : public Pool
{
public: // parametry bazowe
    Jacuzzi(string name = "jacuzzi", double ticketPrice = 8, int timeUnits = 8, bool forKids = false);
};

#endif