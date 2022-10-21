#include "receipt.h"
#include <sstream>
Receipt::Receipt() {}
Receipt::Receipt(double new_total_price) : total_price(new_total_price) {}

double Receipt::get_total_price()
{
    return total_price;
}

void Receipt::add_attraction(AttractionsDB &attractions_database, string attraction_name)
{
    string result = attraction_name;
    result += " --- cena: ";

    int price = attractions_database.getAttraction(attraction_name)->getTicketPrice();
    result += to_string(price);

    client_attractions.push_back(result);

    total_price += price;
}

void Receipt::add_instructor(EmployeesList &employees_database, string instructor_name)
{
    string result = instructor_name;
    result += " --- cena: ";

    int price = 30;
    result += to_string(price);

    client_attractions.push_back(result);
    total_price += price;
}

string Receipt::print()
{
    stringstream ss;
    ss << "---------------- Paragon ----------------" << endl;
    for (int i = 0; i < client_attractions.size(); i++)
    {
        ss << client_attractions[i] << endl;
    }
    ss << "                          Cena laczna: " << total_price << endl;
    ss << "-----------------------------------------" << endl;
    return ss.str();
}