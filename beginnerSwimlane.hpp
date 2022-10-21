#ifndef BEGINNERSWIMLANE_H
#define BEGINNERSWIMLANE_H

#include <iostream>
#include <string>
#include "swimlane.hpp"
using namespace std;

class BeginnerSwimlane : public Swimlane
{
public:
    BeginnerSwimlane(string name = "beginner swimlane", double tP = 9.99, int tU = 10, bool fK = true, double depth = 1);
};

#endif