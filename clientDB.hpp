#ifndef CLIENT_DB_H
#define CLIENT_DB_H
#include <iostream>
#include "client.h"
#include <vector>
#include <memory>
using namespace std;

class ClientDB
{
    mutable vector<unique_ptr<Client>> clients;

public:
    ClientDB();
    bool addClient(Client &attr) const;
    bool removeClient(string name);
    unique_ptr<Client> &getClient(string name) const;
    unique_ptr<Client> &getClient(int index);
    void printAllClients();
    int getClientsLength();
    vector<unique_ptr<Client>> *getClientList();
    void removeAllClients();
};

#endif