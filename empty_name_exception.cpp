#include "empty_name_exception.h"

EmptyNameException::EmptyNameException() :
    std::invalid_argument("Name cannot be empty"){}