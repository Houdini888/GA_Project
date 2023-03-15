//
// Created by Mateusz on 15.01.2023.
//

#include <random>
#include <iostream>
#include <utility>
#include "Individual.h"
#include "RandomGenerator.h"


Individual::Individual(int genesNr) {
    fitness = 0;
    if(genesNr > 0){
        RandomGenerator generator;

        for(int i = 0; i < genesNr; i++){
            genotype.push_back(generator.randomInt(0,1));
        }
    }else{
        throw std::out_of_range("ERROR: WRONG NUMBER OF GENES");
    }
}

Individual::Individual(std::vector<int>& genotype) : genotype(std::move(genotype)) {
}

Individual::~Individual() {

}

const std::vector<int> &Individual::getGenotype() const {
    return genotype;
}

void Individual::mutation(float mutProb) {
    if(mutProb <= 1 && mutProb >= 0){
        RandomGenerator generator;

        for(int i = 0; i < genotype.size(); i++){
            if( generator.randomReal(0,1) < mutProb ){

                if(genotype.at(i) == 1){genotype.at(i) = 0;}
                else{genotype.at(i) = 1;}
            }

        }

    }else{
        throw std::out_of_range("ERROR: WRONG MUTT PROB");
    }
}

double Individual::evaluate(const KnapsackProblem &problem) {
     fitness = problem.evaluate(genotype);
     return fitness;

}

double Individual::getFitness() const {
    return fitness;
}

std::pair<Individual, Individual> Individual::cross(Individual &otherIndividual) const {
    RandomGenerator generator;
    int crossingPoint = generator.randomInt(0,genotype.size()-2);

    std::vector<int> child1Genotype;
    std::vector<int> child2Genotype;

    for(int i = 0; i <= crossingPoint; i++){
        //this_parent part 1 for child 1
        child1Genotype.push_back(genotype.at(i));
        //other_parent part 1 for child 2
        child2Genotype.push_back(otherIndividual.getGenotype().at(i));
    }
    for(int j = crossingPoint+1; j < genotype.size(); j++){
        //other_parent part 2 for child 1
        child1Genotype.push_back(otherIndividual.getGenotype().at(j));
        //this_parent part 2 for child 2
        child2Genotype.push_back(genotype.at(j));
    }

    Individual child1 = Individual(child1Genotype);
    Individual child2 = Individual(child2Genotype);

    std::pair<Individual,Individual> siblings = std::make_pair(child1,child2);
    return siblings;
}




void Individual::printGenotype() {
    for(int gene : genotype){
        std::cout << gene;
    }
    std::cout << '\n';
}