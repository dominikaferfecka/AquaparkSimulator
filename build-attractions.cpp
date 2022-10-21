#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <sstream>
#include <algorithm>
#include "attractionsDB.hpp"
#include "draw_number.h"
#include "build-attractions.hpp"
#include "jacuzzi.hpp"
#include "paddlingPool.hpp"
#include "sauna.hpp"
#include "slide.hpp"
#include "beginnerSwimlane.hpp"
#include "standardSwimlane.hpp"
#include "proSwimlane.hpp"
#include "bouncyCastle.hpp"
#include "pontoonRide.hpp"
#include "aquaBar.hpp"

using namespace std;

vector<string> split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

BuildAttractions::BuildAttractions(string filename, int m, const AttractionsDB &adb) : adb(adb)
{
    this->filename = filename;
    this->m = m;
}

void BuildAttractions::work()
{
    this->openFile();
    this->countLines();
    this->build();
    this->closeFile();
}

void BuildAttractions::openFile()
{
    f.open(filename);
    if (f.fail())
    {
        cout << "Blad otwarcia pliku." << endl;
    }
}

void BuildAttractions::countLines()
{
    while (f.peek() != EOF)
    {
        getline(f, line);
        this->lines++;
    }
}

void BuildAttractions::closeFile()
{
    f.close();
}

void BuildAttractions::build()
{
    int counter = 0;
    vector<int> indices;
    while (counter < m)
    {

        int randIdx = draw_number(0, lines);

        if (find(indices.begin(), indices.end(), randIdx) == indices.end())
        {
            f.clear();            // reset
            f.seekg(0, ios::beg); // powrot do pierwszej linijki
            indices.push_back(randIdx);
            for (int lineNumber = 0; lineNumber < lines; lineNumber++)
            {
                getline(f, line);
                if (lineNumber == randIdx)
                {
                    vector<string> splitted = split(line, ',');
                    string typ = splitted.at(0);
                    string nazwa = splitted.at(1);
                    if (typ == "Slide")
                    {
                        Attraction w = Slide(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                    }
                    else if (typ == "Sauna")
                    {
                        Attraction w = Sauna(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "BouncyCastle")
                    {
                        Attraction w = BouncyCastle(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "AquaBar")
                    {
                        Attraction w = AquaBar(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "PontoonRide")
                    {
                        Attraction w = PontoonRide(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "Jacuzzi")
                    {
                        Attraction w = Jacuzzi(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "PaddlingPool")
                    {
                        Attraction w = PaddlingPool(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "BeginnerSwimlane")
                    {
                        Attraction w = BeginnerSwimlane(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "StandardSwimlane")
                    {
                        Attraction w = StandardSwimlane(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else if (typ == "ProSwimlane")
                    {
                        Attraction w = ProSwimlane(nazwa);
                        if (!adb.addAttraction(w))
                            cout << "nie dodano " << nazwa << endl;
                        ;
                    }
                    else
                    {
                        cout << "nie ma typu " << typ << endl;
                    }
                }
            }
            counter++;
        }
        else
        {
            continue;
        }
    }
}
