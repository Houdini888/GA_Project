//
// Created by Mateusz on 23.01.2023.
//

#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() : generator(rd()) {}

int RandomGenerator::randomInt(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(generator);

}

double RandomGenerator::randomReal(double min, double max) {
    std::uniform_real_distribution<> dist(min, max);
    return dist(generator);

}


