#include "cannot_open_file_exception.h"

CannotOpenFileException::CannotOpenFileException() :
    std::invalid_argument("Cannot open the file"){}