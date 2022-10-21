#ifndef EMPTY_NAME_EXCEPTION_H
#define EMPTY_NAME_EXCEPTION_H

#include <stdexcept>

class EmptyNameException : public std::invalid_argument
{
    public:
        EmptyNameException();
};

#endif