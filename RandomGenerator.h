//
// Created by Mateusz on 23.01.2023.
//

#ifndef GA_PROJECT_RANDOMGENERATOR_H
#define GA_PROJECT_RANDOMGENERATOR_H


#include <random>

class RandomGenerator {
private:
    std::random_device rd;
    std::mt19937 generator;

public:
    RandomGenerator();

    int randomInt(int min, int max);

    double randomReal(double min, double max);
};


#endif //GA_PROJECT_RANDOMGENERATOR_H
