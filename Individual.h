//
// Created by Mateusz on 15.01.2023.
//

#ifndef GA_PROJECT_INDIVIDUAL_H
#define GA_PROJECT_INDIVIDUAL_H


#include <vector>
#include "KnapsackProblem.h"

class Individual {

private:
    std::vector<int> genotype;
    double fitness;



public:
    Individual(int genesNr);
    Individual(std::vector<int>& genotype);

    virtual ~Individual();

    const std::vector<int> &getGenotype() const;
    double getFitness() const;

    void mutation(float mutProb);
    double evaluate(const KnapsackProblem &problem);
    std::pair<Individual,Individual> cross(Individual &otherIndividual) const;


    void printGenotype();

};


#endif //GA_PROJECT_INDIVIDUAL_H
