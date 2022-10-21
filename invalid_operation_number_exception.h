#ifndef INVALID_OPERATION_NUMBER_EXCEPTION_H
#define INVALID_OPERATION_NUMBER_EXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <string>


class InvalidOperationNumberException : public std::invalid_argument
{
    public:
        InvalidOperationNumberException(int invalid_value);
};

#endif