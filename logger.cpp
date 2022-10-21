#include "logger.hpp"
#include "cannot_open_file_exception.h"
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std;

Logger::Logger(string fileName)
{
    f.open(fileName);
    if (f.fail())
    {
        throw CannotOpenFileException();
    }
};

void Logger::logStartSimulation()
{
    string msg = "################ SYMULACJA PARK WODNY ################";
    log(msg);
}

void Logger::logLoadingAttractions(string attractions_list)
{
    string msg;
    msg = "\n---------------- TWORZENIE ATRAKCJI ----------------";
    log(msg);
    cout << attractions_list;
    f << attractions_list;
    msg = "-----------------------------------------------------\n";
    log(msg);
}

void Logger::logLoadingEmployees(string employees_list)
{
    string msg;
    msg = "\n--------------- TWORZENIE PRACOWNIKOW ---------------";
    log(msg);
    cout << employees_list;
    f << employees_list;
    msg = "-----------------------------------------------------\n";
    log(msg);
}

void Logger::logUnitTime(int current_time_units)
{
    stringstream msg;
    msg << endl << "______________ " << "Symulacja " << current_time_units << " jednostka czasu" << " ______________"<< endl;
    log(msg.str());
}

void Logger::logVisitStart(Client client)
{
    stringstream msg;
    msg << endl << "Przychodzi klient (" << client.get_name() << ")" << endl
        << "Na " << client.get_time_units() << " jednostki czasu" << endl
        << "Jego poziom umiejetnosci plywackich: " << client.get_swimming_skills() << endl
        << "Wiek: " << client.get_age();
    log(msg.str());
};

void Logger::logAttractionVisit(Client client, string attractionName)
{
    stringstream msg;
    msg << endl << "Klient (" << client.get_name() << ")" << endl
        << "Wybral atrakcje: " << attractionName;
    log(msg.str());
};

void Logger::logInstructor(Client client, string instructorName)
{
    stringstream msg;
    msg << endl << "Klient (" << client.get_name() << ")" << endl
        << "Wybral instruktora: " << instructorName;
    log(msg.str());
};


void Logger::logVisitEnd(string clientName, Receipt receipt)
{
    stringstream msg;
    msg << endl << "Wychodzi klient (" << clientName << ")" << endl
        << receipt.print();
    log(msg.str());
};

void Logger::logEndSimulation()
{
    string msg = "################ KONIEC SYMULACJI ################";
    log(msg);
}

void Logger::log(string msg)
{
    cout << msg << endl;
    f << msg << endl;
}

Logger::~Logger()
{
    f.close();
}