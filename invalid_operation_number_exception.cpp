#include "invalid_operation_number_exception.h"

InvalidOperationNumberException::InvalidOperationNumberException(int invalid_value):
    std::invalid_argument("Number operation out of range: " + std::to_string(invalid_value)){}