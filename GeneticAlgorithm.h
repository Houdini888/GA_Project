//
// Created by Mateusz on 15.01.2023.
//

#ifndef GA_PROJECT_GENETICALGORITHM_H
#define GA_PROJECT_GENETICALGORITHM_H


#include <vector>
#include "Individual.h"
#include "KnapsackProblem.h"

class GeneticAlgorithm {
private:
    int popSize;
    float mutProb;
    float crossProb;

    std::vector<Individual> individuals;

    KnapsackProblem *knapsackProblem;

public:

    GeneticAlgorithm(KnapsackProblem &knapsackProblem,int popSize, float mutProb, float crossProb);

    virtual ~GeneticAlgorithm();

    int getPopSize() const;
    float getMutProb() const;
    float getCrossProb() const;
    const std::vector<Individual > &getIndividuals() const;
    KnapsackProblem *getKnapsackProblem() const;

    std::vector<int> findSolution(int repeats);

    //funkcje pomocniczne
private:
    void evaluateIndividuals();
    void crossIndividuals();
    Individual chooseParent();
    void mutateIndividuals();
};




#endif //GA_PROJECT_GENETICALGORITHM_H
