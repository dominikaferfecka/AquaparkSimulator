#ifndef CANNOT_OPEN_FILE_EXCEPTION_H
#define CANNOT_OPEN_FILE_EXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <string>


class CannotOpenFileException : public std::invalid_argument
{
    public:
        CannotOpenFileException();
};

#endif