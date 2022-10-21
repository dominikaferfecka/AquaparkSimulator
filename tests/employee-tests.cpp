#include "catch.hpp"
#include "../employee.h"
#include "../cashier.h"
#include "../instructor.h"
#include "../lifeguard.h"
#include "../employees_list.h"
#include "../empty_name_exception.h"
#include "../negative_argument_exception.h"
#include "../cannot_find_employee_exception.h"
#include "../invalid_attractions_list_exception.h"

// EMPLOYEE TESTS

TEST_CASE("lifeguard simple test", "[lifeguard]")
{
    SECTION("create", "[lifeguard]")
    {
        Lifeguard lifeguard("Lifeguard nr 1", 1, 10);
        CHECK(lifeguard.get_name() == "Lifeguard nr 1");
        CHECK(lifeguard.get_id() == 1);
        CHECK(lifeguard.get_working_years() == 10);

        SECTION("modification", "[lifeguard]")
        {
            lifeguard.set_name("Lifeguard nr 2");
            lifeguard.set_working_years(20);
            CHECK(lifeguard.get_name() == "Lifeguard nr 2");
            CHECK(lifeguard.get_working_years() == 20);
        }
    }
}

TEST_CASE("lifeguard invalid test", "[lifeguard]")
{
    SECTION("create", "[lifeguard]")
    {
        Lifeguard lifeguard("Lifeguard nr 1", 1, 10);
        CHECK(lifeguard.get_name() == "Lifeguard nr 1");
        CHECK(lifeguard.get_id() == 1);
        CHECK(lifeguard.get_working_years() == 10);

        SECTION("invalid name", "[lifeguard]")
        {
            REQUIRE_THROWS_AS(lifeguard.set_name(""), EmptyNameException);
        }

        SECTION("invalid working years", "[lifeguard]")
        {
            REQUIRE_THROWS_AS(lifeguard.set_working_years(-1), NegativeArgumentException);
        }
    }
}

TEST_CASE("cashier simple test", "[cashier]")
{
    SECTION("create", "[cashier]")
    {
        Cashier cashier("Cashier nr 1", 1, 2);
        CHECK(cashier.get_name() == "Cashier nr 1");
        CHECK(cashier.get_id() == 1);

        SECTION("modification", "[cashier]")
        {
            cashier.set_name("Cashier nr 2");
            cashier.set_id(20);
            CHECK(cashier.get_name() == "Cashier nr 2");
            CHECK(cashier.get_id() == 20);
        }

        SECTION("cash_register", "[cashier]")
        {
            cashier.set_cash_register(1);
            CHECK(cashier.get_cash_register() == 1);
        }
    }
}

TEST_CASE("cashier invalid test", "[cashier]")
{
    SECTION("create", "[cashier]")
    {
        Cashier cashier("Cashier nr 1", 1, 10);
        CHECK(cashier.get_name() == "Cashier nr 1");
        CHECK(cashier.get_id() == 1);

        SECTION("invalid name", "[cashier]")
        {
            REQUIRE_THROWS_AS(cashier.set_name(""), EmptyNameException);
        }

        SECTION("invalid id", "[cashier]")
        {
            REQUIRE_THROWS_AS(cashier.set_id(-1), NegativeArgumentException);
        }

        SECTION("invalid cash register", "[cashier]")
        {
            REQUIRE_THROWS_AS(cashier.set_cash_register(-1), NegativeArgumentException);
        }
    }
}

TEST_CASE("instructor simple test", "[instructor]")
{
    SECTION("create", "[instructor]")
    {
        Instructor instructor("Instructor nr 1", 1, 10);
        CHECK(instructor.get_name() == "Instructor nr 1");
        CHECK(instructor.get_id() == 1);

        SECTION("modification", "[instructor]")
        {
            instructor.set_name("Instructor nr 2");
            instructor.set_id(20);
            CHECK(instructor.get_name() == "Instructor nr 2");
            CHECK(instructor.get_id() == 20);
        }
        
        SECTION("skill_level", "[instructor]")
        {
            instructor.set_skill_level(1);
            CHECK(instructor.get_skill_level() == 1);
        }

    }
}

TEST_CASE("instructor invalid test", "[instructor]")
{
    SECTION("create", "[instructor]")
    {
        Instructor instructor("Instructor nr 1", 1, 10);
        CHECK(instructor.get_name() == "Instructor nr 1");
        CHECK(instructor.get_id() == 1);

        SECTION("invalid name", "[instructor]")
        {
            REQUIRE_THROWS_AS(instructor.set_name(""), EmptyNameException);
        }

        SECTION("invalid id", "[instructor]")
        {
            REQUIRE_THROWS_AS(instructor.set_id(-1), NegativeArgumentException);
        }

        SECTION("skill_level", "[instructor]")
        {
            REQUIRE_THROWS_AS(instructor.set_skill_level(-1), NegativeArgumentException);
        }
    }
}

TEST_CASE("employees list test", "[employees_list]")
{
    EmployeesList employees;
    CHECK(employees.get_length_list() == 0);

    SECTION("add cashier", "[employees_list]")
    {
        employees.add_cashier("Cashier nr 1", 1, 20);
        CHECK(employees.get_length_list() == 1);

        SECTION("delete cashier", "[employees_list]")
        {
            employees.delete_cashier("Cashier nr 1", 1, 20);
            CHECK(employees.get_length_list() == 0);
        }
    }

    SECTION("add instructor", "[employees_list]")
    {
        employees.add_instructor("Instructor nr 1", 1, 20);
        CHECK(employees.get_length_list() == 1);

        SECTION("delete instructor", "[employees_list]")
        {
            employees.delete_instructor("Instructor nr 1", 1, 20);
            CHECK(employees.get_length_list() == 0);
        }
    }

    SECTION("add lifeguard", "[employees_list]")
    {
        employees.add_lifeguard("Lifeguard nr 1", 1, 20);
        CHECK(employees.get_length_list() == 1);

        SECTION("delete lifeguard", "[employees_list]")
        {
            employees.delete_lifeguard("Lifeguard nr 1", 1, 20);
            CHECK(employees.get_length_list() == 0);
        }
    }
}


