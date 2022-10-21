#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include "employee-interface.h"
#include "empty_name_exception.h"
#include "negative_argument_exception.h"
using namespace std;

class Employee : public IEmployee
{
    protected:
        string name;
        double base_salary;
        int working_days=0;
        int working_hours_per_day=0;
        int id;

    public:
        //constructors
        Employee();
        Employee(string new_name, int new_id);

    
 
        //getters
        string get_name();
        int get_id();
        virtual string get_class_name() = 0;

        //setters
        void set_name(string new_name);
        void set_id(int new_id);

        //operator wypisywania

        friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};

std::ostream& operator<<(std::ostream& os, const Employee& employee);

#endif