#include <iostream>
#include "build-attractions.hpp"
#include "attractionsDB.hpp"
#include "clientDB.hpp"
#include "draw_number.h"
#include "employees_list.h"
#include "employeeBuilder.hpp"
#include "attractionsDB.hpp"
#include "client.h"
#include <sstream>
#include "simulation.h"
#include "negative_argument_exception.h"
using namespace std;

//void to_test()
// {
//     cout << "Hello world" << endl;
//     AttractionsDB db = AttractionsDB();
//     BuildAttractions ba = BuildAttractions("attraction-names.txt", 5, db);
//     ba.work();
//     db.printAllAttractions();

//     ClientDB cdb = ClientDB();
//     Client klient1("a");
//     Client klient2("b");
//     Client klient3("c");
//     cdb.addClient(klient1);
//     cdb.addClient(klient2);
//     cdb.addClient(klient3);
//     cdb.printAllClients();

//     EmployeesList employees_database;
//     EmployeeBuilder eb = EmployeeBuilder();
//     eb.build(employees_database, 10);
//     cout << "Pracownikow: " << employees_database.get_length_list() << endl;
//     cout << "p w/ id: 5 -> " << employees_database.get_list()->at(5).get()->get_name() << endl;
//     Client client("Klient nr 1");
//     client.set_age(5);

//     client.add_attraction(db);
//     cout << client.get_time_attraction() << endl;
//     client.get_receipt().print();
// }

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        std::cerr << "Incorrect number of command line arguments - expected 4, got " << argc << std::endl;
        return 1;
    }

    int n, m, time_units;

    std::stringstream stream;
    
    stream << argv[1];
    stream >> n;
    if (n == 0)
    {
        std::cerr << "Incorrect type of argument: " << argv[1] << " excepected type int" << std::endl;
        return 1;
    }
    if (n < 3)
        throw NegativeArgumentException(to_string(n));
    stream.clear();

    stream << argv[2];
    stream >> m;
    if (m == 0)
    {
        std::cerr << "Incorrect type of argument: " << argv[2] << " excepected type int" << std::endl;
        return 1;
    }
    if (m < 3)
        throw NegativeArgumentException(to_string(m));

    stream.clear();

    stream << argv[3];
    stream >> time_units;
    if (time_units == 0)
    {
        std::cerr << "Incorrect type of argument: " << argv[3] << " excepected type int" << std::endl;
        return 1;
    }
    if (time_units < 0)
        throw NegativeArgumentException(to_string(time_units));
    stream.clear();

    cout << n << endl
         << m << endl
         << time_units;


    //int n = 6, m = 10, time_units = 20;

    Simulation simulation(n, m, time_units);
    return 0;
}
