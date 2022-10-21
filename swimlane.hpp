#ifndef SWIMLANE_H
#define SWIMLANE_H

#include <iostream>
#include <string>
#include "pool.hpp"
using namespace std;

class Swimlane : public Pool
{
    double depth = 0;

protected:
    // constructors
    Swimlane();
    Swimlane(string n, double tP, int tU, bool fK, double depth);

public:
    virtual double getDepth();
    virtual void setDepth(double newDepth);
};

#endif