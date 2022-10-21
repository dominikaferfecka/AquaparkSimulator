#include "catch.hpp"
#include "../client.h"
#include "../empty_name_exception.h"
#include "../negative_argument_exception.h"
#include "../cannot_find_employee_exception.h"
#include "../invalid_attractions_list_exception.h"

TEST_CASE("client simple test", "[client]")
{
    Client client("Client nr 1");
    CHECK(client.get_name() == "Client nr 1");

    SECTION("name", "[client]")
    {
        client.set_name("Client nr 2");
        CHECK(client.get_name() == "Client nr 2");
    }

    SECTION("age", "[client]")
    {
        client.set_age(20);
        CHECK(client.get_age() == 20);
    }

    SECTION("swimming_skills", "[client]")
    {
        client.set_swimming_skills(2);
        CHECK(client.get_swimming_skills() == 2);
    }

    SECTION("time_units", "[client]")
    {
        client.set_time_units(10);
        CHECK(client.get_time_units() == 10);
    }

    SECTION("time_attraction", "[client]")
    {
        client.set_time_attraction(10);
        CHECK(client.get_time_attraction() == 10);
    }
}

TEST_CASE("client invalid data test", "[client]")
{
    Client client("Client nr 1");
    CHECK(client.get_name() == "Client nr 1");

    SECTION("name", "[client]")
    {
        REQUIRE_THROWS_AS(client.set_name(""), EmptyNameException);
    }

    SECTION("age", "[client]")
    {
        REQUIRE_THROWS_AS(client.set_age(-20), NegativeArgumentException);
    }

    SECTION("swimming_skills", "[client]")
    {
        REQUIRE_THROWS_AS(client.set_swimming_skills(-2), NegativeArgumentException);
    }

    SECTION("time_units", "[client]")
    {
        REQUIRE_THROWS_AS(client.set_time_units(-2), NegativeArgumentException);
    }

    SECTION("time_attraction", "[client]")
    {
        REQUIRE_THROWS_AS(client.set_time_attraction(-2), NegativeArgumentException);
    }
}