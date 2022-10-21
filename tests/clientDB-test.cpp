#include "catch.hpp"
#include <iostream>
#include "../clientDB.hpp"
#include "../attraction.hpp"
#include "../attractionsDB.hpp"
#include "../employees_list.h"
#include "../receipt.h"
#include "../draw_number.h"

using namespace std;

TEST_CASE("Clients Data Base")
{
    ClientDB db;
    REQUIRE(db.getClientsLength() == 0);

    SECTION("adding clients")
    {
        Client client1("Client nr 1");
        Client client2("Client nr 2");
        Client client3("Client nr 3");

        db.addClient(client1);
        db.addClient(client2);
        db.addClient(client3);

        REQUIRE(db.getClientsLength() == 3);
        
        SECTION("removing a client")
        {
            db.removeClient("Client nr 1");
            REQUIRE(db.getClientsLength() == 2);
        }

        SECTION("removing all clients")
        {
            db.removeAllClients();
            REQUIRE(db.getClientsLength() == 0);
        }
    }
    
}
