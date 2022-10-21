#ifndef ATTRACTIONS_DB_H
#define ATTRACTIONS_DB_H
#include <iostream>
#include "attraction.hpp"
#include "slide.hpp"
#include <vector>
#include <memory>
using namespace std;

class AttractionsDB
{
    mutable vector<unique_ptr<Attraction>> attractions;

public:
    AttractionsDB();
    bool addAttraction(Attraction &attr) const;
    bool removeAttraction(string name);
    unique_ptr<Attraction> &getAttraction(string name) const;
    unique_ptr<Attraction> &getAttraction(int index);
    string printAllAttractions();
    int getAttractionsLength();
    vector<unique_ptr<Attraction>> *getAttractionsList();
    void removeAllAttractions();
};

#endif