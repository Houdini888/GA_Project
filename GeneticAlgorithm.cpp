//
// Created by Mateusz on 15.01.2023.
//

#include <random>
#include <stdexcept>
#include "GeneticAlgorithm.h"
#include "RandomGenerator.h"

GeneticAlgorithm::GeneticAlgorithm(KnapsackProblem &knapsackProblem, int popSize, float mutProb, float crossProb):
        knapsackProblem(&knapsackProblem), popSize(popSize), mutProb(mutProb),crossProb(crossProb){

    if(popSize <= 0 || mutProb <= 0 || crossProb <= 0){
        throw std::out_of_range("WRONG ALGORITHM ARGUMENTS");
    }

    int genesNr = knapsackProblem.getItemList().size();
    for(int i = 0; i <popSize; i++){
        individuals.push_back(Individual(genesNr));
    }

}

GeneticAlgorithm::~GeneticAlgorithm() {
    delete knapsackProblem;
}

int GeneticAlgorithm::getPopSize() const {
    return popSize;
}

float GeneticAlgorithm::getMutProb() const {
    return mutProb;
}

float GeneticAlgorithm::getCrossProb() const {
    return crossProb;
}

const std::vector<Individual > &GeneticAlgorithm::getIndividuals() const {
    return individuals;
}

KnapsackProblem *GeneticAlgorithm::getKnapsackProblem() const {
    return knapsackProblem;
}



std::vector<int> GeneticAlgorithm::findSolution(int repeats) {
    for(int i = 0; i < repeats; i++){
        evaluateIndividuals();
        crossIndividuals();
        mutateIndividuals();
    }
    evaluateIndividuals();

    Individual *bestSolution;
    double bestFitness = 0;
    for(Individual individual : individuals){
        if(individual.getFitness() > bestFitness){
            bestSolution = &individual;
            bestFitness = individual.getFitness();
        }
    }
    std::vector<int> solution = bestSolution->getGenotype();
    bestSolution = nullptr;
    return solution;

}

//void GeneticAlgorithm::evaluateIndividuals() {
//    for(Individual individual : individuals){
//        individual.evaluate(*knapsackProblem);
//    }
//}

void GeneticAlgorithm::evaluateIndividuals() {
    for(int i = 0; i < individuals.size(); i++){
        individuals.at(i).evaluate(*knapsackProblem);
    }
}

void GeneticAlgorithm::crossIndividuals() {
    RandomGenerator generator;

    std::vector<Individual> newGeneration;
    newGeneration.reserve(individuals.size());

    while(newGeneration.size() < popSize){

        Individual parent1 = chooseParent();
        Individual parent2 = chooseParent();

        if(generator.randomReal(0,1) <= crossProb){
            std::pair<Individual, Individual> children = parent1.cross(parent2);

            newGeneration.push_back(children.first);
            newGeneration.push_back(children.second);
        }else{
            newGeneration.push_back(parent1);
            newGeneration.push_back(parent2);
        }
    }
    individuals = std::move(newGeneration);
    //return newGeneration;


}

Individual GeneticAlgorithm::chooseParent() {
    RandomGenerator generator;

    Individual candidate1 = individuals.at(generator.randomInt(0,individuals.size()-1));
    Individual candidate2 = individuals.at(generator.randomInt(0,individuals.size()-1));

    if(candidate1.getFitness() > candidate2.getFitness()){
        return candidate1;
    }else{
        return candidate2;
    }
}

void GeneticAlgorithm::mutateIndividuals() {
    for(Individual individual : individuals){
        individual.mutation(mutProb);
    }
}