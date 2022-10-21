#include "invalid_attractions_list_exception.h"

InvalidAttractionsListException::InvalidAttractionsListException(std::string client_name):
    std::invalid_argument("Client: " + client_name + " could not join the attraction"){}