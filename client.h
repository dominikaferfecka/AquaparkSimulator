#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "attraction.hpp"
#include "attractionsDB.hpp"
#include "employees_list.h"
#include "receipt.h"
#include "draw_number.h"
using namespace std;

class Client
{
private:
    string name;
    int swimming_skills;
    int age;
    int time_units;
    int time_attraction = 0; // ile zostało mu time units na danej atrakcji
    Receipt receipt;
    bool instructor_taken = false;
    int to_validate = 0;

public:
    // getters
    string get_name();
    int get_age();
    int get_swimming_skills();
    int get_time_units();
    int get_time_attraction();
    Receipt get_receipt();
    bool get_instructor_taken();

    // setters
    void set_name(string new_name);
    void set_age(int new_age);
    void set_swimming_skills(int new_swimming_skills);
    void set_time_units(int new_time_units);
    void set_time_attraction(int new_time_attraction);

    // constructors
    Client();
    Client(string new_name);
    Client(string new_name, int new_age, int new_swimming_skills, int new_time_units);

    // functions

    string add_attraction(AttractionsDB &attractions_database);
    string choose_attraction(AttractionsDB &attractions_database, bool for_kids);
    string add_instructor(EmployeesList &employees_database);
    string choose_instructor(EmployeesList &employees_database);
};

#endif
