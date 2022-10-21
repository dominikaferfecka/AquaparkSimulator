#include <iostream>
#include "clientDB.hpp"
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

ClientDB::ClientDB(){};
bool ClientDB::addClient(Client &attr) const
{
    try
    {
        this->getClient(attr.get_name());
        return false;
    }
    catch (bad_exception e)
    {
        try
        {

            this->clients.push_back(make_unique<Client>(attr));
        }
        catch (exception e)
        {
            cout << "Not added !!! " << e.what() << endl;
        }
    }
    return true;
};
bool ClientDB::removeClient(string name)
{
    unique_ptr<Client> &found = this->getClient(name);
    auto pos = find(this->clients.begin(), this->clients.end(), found);
    if (!found)
    {
        return false;
    }
    else
    {
        this->clients.erase(pos);
    }
    return true;
};
unique_ptr<Client> &ClientDB::getClient(string name) const
{
    for (auto &&pointer : this->clients)
    {
        if (pointer->get_name() == name)
            return pointer;
    }
    throw bad_exception();
};
unique_ptr<Client> &ClientDB::getClient(int index)
{
    return this->clients.at(index);
};

void ClientDB::printAllClients()
{
    if (this->clients.size() == 0)
    {
        cout << "Brak klientow" << endl;
        return;
    }
    int counter = 1;
    for (auto &&pointer : this->clients)
    {
        cout << counter << ". " << pointer->get_name() << endl;
        counter++;
    }
}

int ClientDB::getClientsLength()
{
    return this->clients.size();
};

vector<unique_ptr<Client>> *ClientDB::getClientList()
{
    return &clients;
};

void ClientDB::removeAllClients()
{
   clients.clear();
}