#include <iostream>
#include <sstream>
#include "employee.h"
#include "employeeBuilder.hpp"
#include "draw_number.h"

using namespace std;

EmployeeBuilder::EmployeeBuilder(){};

void EmployeeBuilder::build(EmployeesList &list, int count)
{
    for (int a = 0; a < count; a++)
    {
        if (a % 3 == 1)
        {
            stringstream name;
            name << "Cashier " << a;
            list.add_cashier(name.str(), a, a / 3);
        }
        else if (a % 3 == 0)
        {

            stringstream name;
            name << "Instructor " << a;
            list.add_instructor(name.str(), a, draw_number(0, 3));
        }
        else
        {
            stringstream name;
            name << "Lifeguard " << a;
            list.add_lifeguard(name.str(), a, draw_number(0, 20));
        }
    }
};
