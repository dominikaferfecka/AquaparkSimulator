#ifndef INVALID_ATTRACTIONS_LIST_EXCEPTION_H
#define INVALID_ATTRACTIONS_LIST_EXCEPTION_H

#include <stdexcept>
#include <iostream>


class InvalidAttractionsListException : public std::invalid_argument
{
    public:
        InvalidAttractionsListException(std::string client_name);
};

#endif