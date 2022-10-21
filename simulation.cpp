#include "simulation.h"
#include "build-attractions.hpp"
#include "employeeBuilder.hpp"
#include "draw_client.h"
#include <vector>

#include <chrono>
#include <thread>

using namespace std;

Simulation::Simulation(int new_n, int new_m, int new_units_time)
    : n(new_n), m(new_m), units_time(new_units_time)
{
    logger.logStartSimulation();
    create_attractions_database();
    create_employees_database();
    simulate();
}

void Simulation::create_attractions_database()
{
    BuildAttractions ba = BuildAttractions("attraction-names.txt", m, attractions_database);
    ba.work();
    logger.logLoadingAttractions(attractions_database.printAllAttractions());
}

void Simulation::create_employees_database()
{
    EmployeeBuilder eb = EmployeeBuilder();
    eb.build(employees_database, n);
    logger.logLoadingEmployees(employees_database.print_employees());
}

void Simulation::simulate()
{
    vector<string> names_to_delete;
    for (int current_time_units = 1; current_time_units <= units_time; current_time_units++)
    {
        // cout.flush();
        //this_thread::sleep_for(chrono::milliseconds(3000));

        logger.logUnitTime(current_time_units);

        Client new_client = draw_new_client(current_time_units);
        clients_database.addClient(new_client);
        logger.logVisitStart(new_client);

        // przejście po wszystkich klientach:
        if (clients_database.getClientsLength() > 0)
        {
            for (auto &&pointer : *clients_database.getClientList())
            {
                // //wybrać atrakcje lub zmniejszyc jednostki czasu atrakcji
                string choosen_attraction_name = pointer->add_attraction(attractions_database);
                if (choosen_attraction_name.length() > 0)
                {
                    logger.logAttractionVisit(pointer->get_name(), choosen_attraction_name);
                }

                // //wybrać instruktora
                string choosen_instructor_name = pointer->add_instructor(employees_database);
                if (choosen_instructor_name.length() > 0)
                {
                    logger.logInstructor(pointer->get_name(), choosen_instructor_name);
                }

                // zmniejszyć jednostki czasu klienta
                pointer->set_time_units((pointer->get_time_units()) - 1);

                // zostac/wyjsc z parku wodnego
                if (pointer->get_time_units() == 1)
                {
                    logger.logVisitEnd(pointer->get_name(), pointer->get_receipt());
                    names_to_delete.push_back(pointer->get_name());
                }
            }
            for (int i = 0; i < names_to_delete.size(); i++)
            {
                clients_database.removeClient(names_to_delete[i]);
            }
            names_to_delete.clear();
        }
    }
}

Simulation::~Simulation()
{
    logger.logEndSimulation();
    attractions_database.removeAllAttractions();
    employees_database.remove_all_employees();
    clients_database.removeAllClients();
}