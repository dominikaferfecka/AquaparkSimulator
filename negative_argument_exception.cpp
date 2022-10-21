#include "negative_argument_exception.h"

NegativeArgumentException::NegativeArgumentException(std::string invalid_value):
    std::invalid_argument("Argument have to be bigger" + invalid_value){}