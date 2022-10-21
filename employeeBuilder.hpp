#include <iostream>
#include "employee.h"
#include "employees_list.h"

using namespace std;

class EmployeeBuilder
{
public:
    EmployeeBuilder();
    void build(EmployeesList &list, int count);
};