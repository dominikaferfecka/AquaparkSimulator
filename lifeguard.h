#ifndef LIFEGUARD_H
#define LIFEGUARD_H

#include "employee.h"
#include <iostream>
#include <string>

class Lifeguard : public Employee
{
    private:
        int working_years=0; //ilość lat przepracowanych

    public:
        Lifeguard();
        Lifeguard(string new_name, int new_id, int new_working_years);
        string get_class_name() override;
        int get_working_years();
        void set_working_years(int new_working_years);


};



#endif