#include <iostream>
#include <string>
#include "swimlane.hpp"
#include "pool.hpp"

using namespace std;

Swimlane::Swimlane(string name, double tP, int tU, bool fK, double depth) : Pool(name, tP, tU, fK)
{
    this->depth = depth;
}

double Swimlane::getDepth()
{
    return this->depth;
}

void Swimlane::setDepth(double newDepth)
{
    this->depth = newDepth;
}