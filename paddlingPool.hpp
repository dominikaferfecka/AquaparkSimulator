#ifndef PADDLING_POOL_H
#define PADDLING_POOL_H
#include <iostream>
#include <string>
#include "pool.hpp"
using namespace std;

class PaddlingPool : public Pool
{
public:
    PaddlingPool(string name = "paddling pool", double ticketPrice = 12, int timeUnits = 12, bool forKids = true);
};
#endif