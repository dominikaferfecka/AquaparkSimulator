#include "catch.hpp"
#include <iostream>
#include "../attraction.hpp"
#include "../attractionsDB.hpp"
#include "../pool.hpp"
#include "../jacuzzi.hpp"
#include "../paddlingPool.hpp"
#include "../swimlane.hpp"
#include "../sauna.hpp"
#include "../slide.hpp"
#include "../beginnerSwimlane.hpp"
#include "../standardSwimlane.hpp"
#include "../proSwimlane.hpp"
#include "../bouncyCastle.hpp"
#include "../pontoonRide.hpp"
#include "../aquaBar.hpp"
#include "../invalid_attractions_list_exception.h"
#include "../attractionsDB.hpp"

using namespace std;

TEST_CASE("Attractions Data Base")
{
    AttractionsDB db;
    REQUIRE(db.getAttractionsLength() == 0);

    SECTION("adding attractions")
    {
        Slide s;
        Jacuzzi j;
        BouncyCastle b;
        db.addAttraction(s);
        db.addAttraction(j);
        db.addAttraction(b);
        REQUIRE(db.getAttractionsLength() == 3);
    
        SECTION("removing an attraction")
        {
            db.removeAttraction("jacuzzi");
            REQUIRE(db.getAttractionsLength() == 2);
        }
        SECTION("removing all attractions")
        {
            db.removeAllAttractions();
            REQUIRE(db.getAttractionsLength() == 0);
        }
    }
}
