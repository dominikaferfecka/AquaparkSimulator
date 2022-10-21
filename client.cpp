#include "client.h"
#include "instructor.h"
#include "empty_name_exception.h"
#include "negative_argument_exception.h"
#include "invalid_attractions_list_exception.h"
#include <string>

// getters
string Client::get_name()
{
    return name;
}

int Client::get_age()
{
    return age;
}

int Client::get_swimming_skills()
{
    return swimming_skills;
}

int Client::get_time_units()
{
    return time_units;
}

int Client::get_time_attraction()
{
    return time_attraction;
}

bool Client::get_instructor_taken()
{
    return instructor_taken;
}

Receipt Client::get_receipt()
{
    return receipt;
}

// setters
void Client::set_name(string new_name)
{
    if (new_name == "")
        throw EmptyNameException();
    name = new_name;
}

void Client::set_age(int new_age)
{
    if (new_age <= 0)
        throw NegativeArgumentException(to_string(new_age));
    age = new_age;
}

void Client::set_swimming_skills(int new_swimming_skills)
{
    if (new_swimming_skills <= 0)
        throw NegativeArgumentException(to_string(new_swimming_skills));
    swimming_skills = new_swimming_skills;
}

void Client::set_time_units(int new_time_units)
{
    if (new_time_units <= 0)
        throw NegativeArgumentException(to_string(new_time_units));
    time_units = new_time_units;
}

void Client::set_time_attraction(int new_time_attraction)
{
    if (new_time_attraction <= 0)
        throw NegativeArgumentException(to_string(new_time_attraction));
    time_attraction = new_time_attraction;
}

// constructors

Client::Client() {}

Client::Client(string new_name) : name(new_name) {}

Client::Client(string new_name, int new_age, int new_swimming_skills, int new_time_units) : name(new_name), age(new_age), swimming_skills(new_swimming_skills), time_units(new_time_units) {}

string Client::add_attraction(AttractionsDB &attractions_database)
{
    to_validate = 0;
    if (time_attraction == 0) // wykona tylko jesli nie jest na zadnej atrakcji
    {
        bool for_kids = age < 18;
        string chosen_attraction_name = choose_attraction(attractions_database, for_kids);
        time_attraction = attractions_database.getAttraction(chosen_attraction_name)->getTimeUnits(); // ustaw nowy czas na atrakcji
        receipt.add_attraction(attractions_database, chosen_attraction_name);
        return chosen_attraction_name;
    }
    else
    {
        time_attraction--;
        return "";
    }

    return "";
}

string Client::choose_attraction(AttractionsDB &attractions_database, bool for_kids)
{
    int size = attractions_database.getAttractionsLength();
    if (to_validate == size+2)
        throw InvalidAttractionsListException(name);
    int indeks = draw_number(0, size - 1);

    auto pointer = attractions_database.getAttractionsList();
    string chosen_attraction = (*pointer)[indeks]->getName();

    size_t found = chosen_attraction.find("tor plywacki");
    if (found!=string::npos) // sprawdzenie poprawnosci jesli tor plywacki - sprawdzamy glebokosc do umiejetnosci
    {
        found = chosen_attraction.find("Poczatkujacy tor plywacki");
        if (found!=string::npos && swimming_skills != 1)
        {
            to_validate++;
            return chosen_attraction = choose_attraction(attractions_database, for_kids);
        }
            
        
        found = chosen_attraction.find("Standardowy tor plywacki");
        if (found!=string::npos && swimming_skills != 2)
        {
            to_validate++;
            return chosen_attraction = choose_attraction(attractions_database, for_kids);
        }


        found = chosen_attraction.find("Ekspercki tor plywacki");
        if (found!=string::npos && swimming_skills != 3)
        {
            to_validate++;
            return chosen_attraction = choose_attraction(attractions_database, for_kids);
        }
    }
    else    // jesli nie jest to tor plywacki sprawdzamy wiek
    {
        if (((*pointer)[indeks]->ifForKids()) != for_kids) // jesli nie jest dla tego wieku wylosuj jeszcze raz
        {
           to_validate++; 
           return chosen_attraction = choose_attraction(attractions_database, for_kids); 
        }
        else
            return chosen_attraction;
    }
    return chosen_attraction;
}

string Client::add_instructor(EmployeesList &employees_database)
{
    if (instructor_taken == false)
    {

        int number = draw_number(0, 15);
        if (number == 3) // wybranie czy chce nowego instruktora
        {
            string chosen_instructor_name = choose_instructor(employees_database);
            instructor_taken = true;
            receipt.add_instructor(employees_database, chosen_instructor_name);
            return chosen_instructor_name;
        }
    }
    return "";
}

string Client::choose_instructor(EmployeesList &employees_database)
{
    int size = employees_database.get_length_list();

    int index = draw_number(0, int((size - 1) / 3));

    string searched_name = "Instructor " + to_string(3 * index);
    string found_name = employees_database.get_name_at_index(3 * index);
    if (found_name == searched_name)
        return found_name;
    else
        return choose_instructor(employees_database);

}
