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

using namespace std;

// getters and setters

TEST_CASE("Sauna")
{
    Sauna s;
    REQUIRE(s.getTicketPrice() == 10);
    REQUIRE(s.getTimeUnits() == 10);
    REQUIRE(s.ifForKids() == false);
}

TEST_CASE("Slide")
{
    Slide sl;
    REQUIRE(sl.getTicketPrice() == 5);
    REQUIRE(sl.getTimeUnits() == 5);
    REQUIRE(sl.ifForKids() == true);
}

TEST_CASE("Pontoon ride")
{
    PontoonRide pr;
    REQUIRE(pr.getTicketPrice() == 7);
    REQUIRE(pr.getTimeUnits() == 7);
    REQUIRE(pr.ifForKids() == true);
}

TEST_CASE("Bouncy Castle")
{
    BouncyCastle b;
    REQUIRE(b.getTicketPrice() == 15);
    REQUIRE(b.getTimeUnits() == 15);
    REQUIRE(b.ifForKids() == true);
}

TEST_CASE("Aqua Bar")
{
    AquaBar a;
    REQUIRE(a.getTicketPrice() == 20);
    REQUIRE(a.getTimeUnits() == 10);
    REQUIRE(a.ifForKids() == false);
}

// pools
TEST_CASE("Jacuzzi")
{
    Jacuzzi j;
    REQUIRE(j.getTicketPrice() == 8);
    REQUIRE(j.getTimeUnits() == 8);
    REQUIRE(j.ifForKids() == false);
}

TEST_CASE("Paddling pool")
{
    PaddlingPool p;
    REQUIRE(p.getTicketPrice() == 12);
    REQUIRE(p.getTimeUnits() == 12);
    REQUIRE(p.ifForKids() == true);
}

// swimlanes
TEST_CASE("Beginner Swimlane")
{
    BeginnerSwimlane bs;
    REQUIRE(bs.getTicketPrice() == 9.99);
    REQUIRE(bs.getTimeUnits() == 10);
    REQUIRE(bs.ifForKids() == true);
    REQUIRE(bs.getDepth() == 1);
}

TEST_CASE("Standard Swimlane")
{
    StandardSwimlane ss;
    REQUIRE(ss.getTicketPrice() == 14.99);
    REQUIRE(ss.getTimeUnits() == 15);
    REQUIRE(ss.ifForKids() == true);
    REQUIRE(ss.getDepth() == 1.5);
}

TEST_CASE("Pro Swimlane")
{
    ProSwimlane ps;
    REQUIRE(ps.getTicketPrice() == 19.99);
    REQUIRE(ps.getTimeUnits() == 20);
    REQUIRE(ps.ifForKids() == true);
    REQUIRE(ps.getDepth() == 1.8);
}