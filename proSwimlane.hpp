#ifndef PROSWIMLANE_H
#define PROSWIMLANE_H

#include <iostream>
#include <string>
#include "swimlane.hpp"
using namespace std;

class ProSwimlane : public Swimlane
{

public:
    ProSwimlane(string name = "pro swimlane", double tP = 19.99, int tU = 20, bool fK = true, double depth = 1.8);
};

#endif