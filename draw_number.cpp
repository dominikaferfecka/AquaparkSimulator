#include "draw_number.h"

int draw_number(int i, int j)
{
    unsigned seed = static_cast<unsigned> (std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(i, j);
    int random_number = distribution(generator);
    return random_number;
}