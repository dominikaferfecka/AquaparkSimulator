#ifndef NEGATIVE_ARGUMENT_EXCEPTION_H
#define NEGATIVE_ARGUMENT_EXCEPTION_H

#include <stdexcept>
#include <iostream>


class NegativeArgumentException : public std::invalid_argument
{
    public:
        NegativeArgumentException(std::string invalid_value);
};

#endif