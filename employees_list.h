#ifndef EMPLOYEES_LiST_H
#define EMPLOYEES_LiST_H
#include "employee.h"
#include "cashier.h"
#include "lifeguard.h"
#include "instructor.h"
#include "cannot_find_employee_exception.h"
#include <vector>
#include <memory>
using namespace std;


class EmployeesList
{
    private:
        vector<unique_ptr<Employee>> employees;
    
    public:
        // void add_employee(string new_name, int new_id);
        void add_lifeguard(string new_name, int new_id, int new_working_years);
        void add_instructor(string new_name,  int new_id, int new_skill_level);
        void add_cashier(string new_name,  int new_id, int new_cash_register);

        // void delete_employee(string name, int id);
        void delete_lifeguard(string name, int id, int working_years);
        void delete_instructor(string name, int id, int skill_level);
        void delete_cashier(string name, int id, int cash_register);

        void calculate_each_salary();
        void calculate_each_schedule();
        
        string get_name_at_index(int index);
        string print_employees();
        int get_length_list();
        vector<unique_ptr<Employee>>* get_list();
        vector<unique_ptr<Employee>>* getEmployeesList();

        void remove_all_employees();

};

#endif