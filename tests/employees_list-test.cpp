#include "catch.hpp"
#include <iostream>
#include "../employees_list.h"
#include "../employee.h"
#include "../cashier.h"
#include "../lifeguard.h"
#include "../instructor.h"
#include "../cannot_find_employee_exception.h"
using namespace std;

TEST_CASE("Employees Data Base")
{
    EmployeesList db;
    REQUIRE(db.get_length_list() == 0);

    SECTION("adding employees")
    {
        db.add_lifeguard("l", 1, 10);
        db.add_instructor("i", 2, 20);
        db.add_cashier("c", 3, 30);
        REQUIRE(db.get_length_list() == 3);
        REQUIRE(db.get_name_at_index(0) == "l");

        // SECTION("removing an employee")
        // {
        //     db.delete_lifeguard("l", 1, 10);
        //     REQUIRE(db.get_length_list() == 2);
        //     REQUIRE(db.get_name_at_index(0) == "i");
        // }

        // SECTION("removing all employees")
        // {
        //     db.remove_all_employees();
        //     REQUIRE(db.get_length_list() == 0);
        // }
        
        // SECTION("invalid data")
        // {
        //     REQUIRE_THROWS_AS(db.delete_lifeguard("L", 3, 5), CannotFindEmployeeException);
        // }
    }
}