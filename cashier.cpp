#include "cashier.h"
using namespace std;

//CONSTRUCTORS

Cashier::Cashier() {}

Cashier::Cashier(string new_name, int new_id, int new_cash_register) : Employee(new_name, new_id), cash_register(new_cash_register) {}

int Cashier::get_cash_register()
{
    return cash_register;
}

void Cashier::set_cash_register(int new_cash_register)
{
    if (new_cash_register <= 0)
        throw NegativeArgumentException(to_string(new_cash_register));
    cash_register = new_cash_register;
}

string Cashier::get_class_name()
{
    return "Cashier";
}