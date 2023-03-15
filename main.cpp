#include <iostream>
#include <random>
#include "Individual.h"
#include "GeneticAlgorithm.h"

int main() {

    KnapsackProblem *knapsackProblem = new KnapsackProblem(5,"kp.txt");
    GeneticAlgorithm geneticAlgorithm = GeneticAlgorithm(*knapsackProblem,100,0.1,0.5);

    std::vector<int> solution = geneticAlgorithm.findSolution(1000);


    for(int gene: solution){
        std::cout << gene;
    }





/////////////////////////////////////////////////////////////////////////

//    std::vector<int> solution = ga.findSolution(100);
//
//    for(int gene : solution){
//        std::cout << gene;
//    }






//
//    for(Individual *individual : ga->getIndividuals()){
//        for(int gene : individual->getGenotype()){
//            std::cout << gene;
//        }
//        std::cout << '\n';
//    }

//    Individual *individual = new Individual(vector.size());
//
//    for(int gene : individual->getGenotype()){
//        std::cout << gene;
//    }
//    std::cout << "\n" << individual->evaluate(*problem) << " " << individual->getFitness();


//    Individual *p1 = new Individual(5);
//    Individual *p2 = new Individual(5);
//
//    p1->printGenotype();
//    p2->printGenotype();
//
//    std::pair<Individual*,Individual*> children = p1->cross(*p2);
//    Individual *c1 = children.first;
//    Individual *c2 = children.second;
//
//    c1->printGenotype();
//    c2->printGenotype();





    return 0;
}
