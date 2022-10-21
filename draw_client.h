#ifndef DRAW_CLIENT_H
#define DRAW_CLIENT_H

#include <iostream>
#include <string>
#include "client.h"
#include "draw_number.h"
using namespace std;

Client draw_new_client(int id)
{
    string name = "Client nr " + to_string(id);
    int age = draw_number(5, 100);
    int swimming_skills = draw_number(1, 3);
    int time_units = draw_number(5, 50);
    Client client(name, age, swimming_skills, time_units);
    return client;
}
#endif