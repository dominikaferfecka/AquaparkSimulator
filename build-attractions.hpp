#ifndef BUILD_ATTRACTIONS_H
#define BUILD_ATTRACTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include "attractionsDB.hpp"
#include "draw_number.h"
using namespace std;

class BuildAttractions
{
    ifstream f;
    string filename;
    int m = 0;
    const AttractionsDB &adb;
    int lines = 0;
    string line;

    void openFile();
    void countLines();
    void build();
    void closeFile();

public:
    BuildAttractions(string filename, int m, const AttractionsDB &adb);
    void work();
};

#endif
