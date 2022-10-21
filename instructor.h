#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "employee.h"
#include <iostream>
#include <string>

class Instructor : public Employee
{
    private:
        int skill_level=0;

    public:
        Instructor();
        Instructor(string new_name, int new_id, int new_skill_level);
        string get_class_name() override;
        int get_skill_level();
        void set_skill_level(int new_skill_level);

};



#endif