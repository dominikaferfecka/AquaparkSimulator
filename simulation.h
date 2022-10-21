#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include "attractionsDB.hpp"
#include "employees_list.h"
#include "clientDB.hpp"
#include "logger.hpp"
using namespace std;

class Simulation
{
private:
    int n, m, units_time;
    AttractionsDB attractions_database;
    EmployeesList employees_database;
    ClientDB clients_database = ClientDB();
    Logger logger = Logger("simulation_log.txt");

public:
    void simulate();
    void create_attractions_database();
    void create_employees_database();
    Simulation(int new_n, int new_m, int new_units_time);
    ~Simulation();
};

#endif