#include "cannot_find_employee_exception.h"

CannotFindEmployeeException::CannotFindEmployeeException() :
    std::invalid_argument("Employee to modify have to exist"){}