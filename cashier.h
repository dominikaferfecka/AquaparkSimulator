#ifndef CASHIER_H
#define CASHIER_H

#include "employee.h"
#include <iostream>
#include <string>

class Cashier : public Employee
{
    private:
        int cash_register=0; //numer kasy

    public:
        Cashier();
        Cashier(string new_name, int new_id, int cash_register);
        string get_class_name() override;
        int get_cash_register();
        void set_cash_register(int new_cash_register);

};



#endif