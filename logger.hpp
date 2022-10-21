#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "client.h"
#include "receipt.h"
using namespace std;

class Logger
{
    fstream f;

public:
    Logger(string fileName);
    void logStartSimulation();
    void logUnitTime(int time_units);
    void logLoadingAttractions(string attractions_list);
    void logLoadingEmployees(string employees_list);
    void logVisitStart(Client client);
    void logAttractionVisit(Client client, string attractionName);
    void logInstructor(Client client, string instructorName);
    void logVisitEnd(string instructorName, Receipt receipt);
    void log(string msg);
    void logEndSimulation();
    ~Logger();
};


#endif