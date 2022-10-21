#include "instructor.h"
using namespace std;

//CONSTRUCTORS

Instructor::Instructor() {}

Instructor::Instructor(string new_name, int new_id, int new_skill_level) : 
Employee(new_name, new_id), skill_level(new_skill_level)  {}


string Instructor::get_class_name()
{
    return "Instructor";
}

int Instructor::get_skill_level()
{
    return skill_level;
}

void Instructor::set_skill_level(int new_skill_level)
{
    if (new_skill_level <= 0)
        throw NegativeArgumentException(to_string(new_skill_level));
    skill_level = new_skill_level;
}