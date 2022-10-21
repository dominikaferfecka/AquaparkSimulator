#ifndef CANNOT_FIND_EMPLOYEE_EXCEPTION_H
#define CANNOT_FIND_EMPLOYEE_EXCEPTION_H

#include <stdexcept>

class CannotFindEmployeeException : public std::invalid_argument
{
    public:
        CannotFindEmployeeException();
};

#endif