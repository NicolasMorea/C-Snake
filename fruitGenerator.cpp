#include <random>
#include <iostream>
#include "snakeGenerator.h"

int generate_Fruit(Snake &snake){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,columns * rows -1);

    return dist6(rng);
}
