#include <iostream>
#include "attractionsDB.hpp"
#include <vector>
#include <sstream>
#include <algorithm>
#include <memory>
using namespace std;

AttractionsDB::AttractionsDB(){};
bool AttractionsDB::addAttraction(Attraction &attr) const
{
    try
    {
        this->getAttraction(attr.getName());
        return false;
    }
    catch (bad_exception e)
    {
        try
        {

            this->attractions.push_back(make_unique<Attraction>(attr));
        }
        catch (exception e)
        {
            cout << "Not added !!! " << e.what() << endl;
        }
    }
    return true;
};
bool AttractionsDB::removeAttraction(string name)
{
    unique_ptr<Attraction> &found = this->getAttraction(name);
    auto pos = find(this->attractions.begin(), this->attractions.end(), found);
    if (!found)
    {
        return false;
    }
    else
    {
        this->attractions.erase(pos);
    }
    return true;
};
unique_ptr<Attraction> &AttractionsDB::getAttraction(string name) const
{
    for (auto &&pointer : this->attractions)
    {
        if (pointer->getName() == name)
            return pointer;
    }
    throw bad_exception();
};
unique_ptr<Attraction> &AttractionsDB::getAttraction(int index)
{
    return this->attractions.at(index);
};

string AttractionsDB::printAllAttractions()
{
    stringstream msg;
    if (this->attractions.size() == 0)
    {
        msg << endl << "Brak atrakcji" << endl;
        return msg.str();
    }
    int counter = 1;
    for (auto &&pointer : this->attractions)
    {
        string forKids = pointer->ifForKids() ? "TAK" : "NIE";
        msg << counter << ". " << pointer->getName() << " dla dzieci?: " << forKids << endl;
        counter++;
    }
    return msg.str();
}

int AttractionsDB::getAttractionsLength()
{
    return this->attractions.size();
};

vector<unique_ptr<Attraction>> *AttractionsDB::getAttractionsList()
{
    return &attractions;
};

void AttractionsDB::removeAllAttractions()
{
    attractions.clear();
}