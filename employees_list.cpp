#include "employees_list.h"
#include "employee.h"
#include "lifeguard.h"
#include "cashier.h"
#include "instructor.h"
#include <sstream>
#include <iostream>



void EmployeesList::add_lifeguard(string new_name, int new_id, int new_working_years)
{
    unique_ptr<Employee> added_lifeguard = make_unique<Lifeguard>(new_name, new_id, new_working_years);
    employees.push_back(move(added_lifeguard));
    //cout << "adding: " + new_name << endl;
}

void EmployeesList::add_instructor(string new_name, int new_id, int new_skill_level)
{
    unique_ptr<Employee> added_instructor = make_unique<Instructor>(new_name, new_id, new_skill_level);
    employees.push_back(move(added_instructor));
    //cout << "adding: " + new_name << endl;
}

void EmployeesList::add_cashier(string new_name, int new_id, int new_cash_register)
{
    unique_ptr<Employee> added_cashier = make_unique<Cashier>(new_name, new_id, new_cash_register);
    employees.push_back(move(added_cashier));
    //cout << "adding: " + new_name << endl;
}

int EmployeesList::get_length_list()
{
    return employees.size();
}


vector<unique_ptr<Employee>>* EmployeesList::get_list()
{
    return &employees;
}


vector<unique_ptr<Employee>>* EmployeesList::getEmployeesList()
{
    return &employees;
};

string EmployeesList::get_name_at_index(int index)
{
    return employees[index]->get_name();
}

string EmployeesList::print_employees()
{
    stringstream msg;
    if (this->employees.size() == 0)
    {
        msg << "Brak pracowników" << endl;
        return msg.str();
    }
    int counter = 1;
    for (auto &&pointer : this->employees)
    {
        msg << counter << ". " << pointer->get_name() << endl;
        counter++;
    }
    return msg.str();
}



void EmployeesList::delete_lifeguard(string name, int id, int working_years)
{
    bool not_find = 1;
    for (vector<unique_ptr<Employee>>::iterator it = employees.begin(); it != employees.end(); )
    {
        auto& employee_ptr = *it;
        bool if_name, if_years;
        if_name = employee_ptr -> get_name() == name;
        if_years = employee_ptr -> get_id() == id;
        if (if_name && if_years)
        {
            auto ptr = employee_ptr.release();
            delete ptr;
            it = employees.erase(it);
            not_find = 0;
        }
    }
    if (not_find)
        throw CannotFindEmployeeException();
}


void EmployeesList::delete_instructor(string name, int id, int swimming_track)
{
    bool not_find = 1;
    for (vector<unique_ptr<Employee>>::iterator it = employees.begin(); it != employees.end(); )
    {
        auto& employee_ptr = *it;
        bool if_name, if_years;
        if_name = employee_ptr -> get_name() == name;
        if_years = employee_ptr -> get_id() == id;
        if (if_name && if_years)
        {
            auto ptr = employee_ptr.release();
            delete ptr;
            it = employees.erase(it);
            not_find = 0;
        }
    }
    if (not_find)
        throw CannotFindEmployeeException();
}


void EmployeesList::delete_cashier(string name, int id, int cash_register)
{   
    bool not_find = 1;
    for (vector<unique_ptr<Employee>>::iterator it = employees.begin(); it != employees.end(); )
    {
        auto& employee_ptr = *it;
        bool if_name, if_years;
        if_name = employee_ptr -> get_name() == name;
        if_years = employee_ptr -> get_id() == id;
        if (if_name && if_years)
        {
            auto ptr = employee_ptr.release();
            delete ptr;
            it = employees.erase(it);
            not_find = 0;
        }
    }
    if (not_find)
        throw CannotFindEmployeeException();
}

void EmployeesList::remove_all_employees()
{
    employees.clear();
}