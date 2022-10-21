#include "lifeguard.h"
using namespace std;

//CONSTRUCTORS

Lifeguard::Lifeguard() {}

Lifeguard::Lifeguard(string new_name, int new_id, int new_working_years) : Employee(new_name, new_id), working_years(new_working_years) {}


int Lifeguard::get_working_years()
{
    return working_years;
}

void Lifeguard::set_working_years(int new_working_years)
{
    if (new_working_years <= 0)
        throw NegativeArgumentException(to_string(new_working_years));
    working_years = new_working_years;
}

string Lifeguard::get_class_name()
{
    return "Lifeguard";
}