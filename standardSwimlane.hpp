#ifndef STANDARDSWIMLANE_H
#define STANDARDSWIMLANE_H

#include <iostream>
#include <string>
#include "swimlane.hpp"
using namespace std;

class StandardSwimlane : public Swimlane
{
public:
    StandardSwimlane(string name = "standard swimlane", double tP = 14.99, int tU = 15, bool fK = true, double depth = 1.5);
};

#endif