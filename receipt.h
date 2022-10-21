#ifndef RECEIPT_H
#define RECEIPT_H
#include <iostream>
#include <vector>
#include "attraction.hpp"
#include "attractionsDB.hpp"
#include "employees_list.h"
using namespace std;

class Receipt
{
private:
    vector<string> client_attractions;
    double total_price;

public:
    Receipt();
    Receipt(double new_total_price);
    double get_total_price();
    void add_attraction(AttractionsDB &attraction_database, string attraction_name);
    void add_instructor(EmployeesList &employee_database, string instructor_name);
    string print();
};

#endif
