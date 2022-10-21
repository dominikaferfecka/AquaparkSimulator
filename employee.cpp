#include "employee.h"
#include <string>

//CONSTRUCTORS

Employee::Employee() {}

Employee::Employee(string new_name, int new_id) : name(new_name), id(new_id) {}


//GETTERS

string Employee::get_name()
{
    return name;
}


int Employee::get_id()
{
    return id;
}

//SETTERS
void Employee::set_name(string new_name)
{
    if(new_name == "")
        throw EmptyNameException(); 
    name = new_name;
}


void Employee::set_id(int new_id)
{
    if (new_id <= 0)
        throw NegativeArgumentException(to_string(new_id));
    id = new_id;
}

//operator wypisywania

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << "Employee: Name: " << employee.name << " id: " << to_string(employee.id);
    return os;
}

