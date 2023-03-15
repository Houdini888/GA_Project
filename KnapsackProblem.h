//
// Created by Mateusz on 15.01.2023.
//

#ifndef GA_PROJECT_KNAPSACKPROBLEM_H
#define GA_PROJECT_KNAPSACKPROBLEM_H


#include <vector>
#include <string>

class KnapsackProblem {

private:
    // first = value , second = weight
    std::vector<std::pair<double,double>> itemList;
    double backpackSize;

public:
    //KnapsackProblem(std::vector<std::pair<double, double>> itemList, double backpackSize);
    KnapsackProblem(double backpackSize, std::string filename);

    const std::vector<std::pair<double, double>> &getItemList() const;
    double getBackpackSize() const;

   double evaluate(const std::vector<int> &genotype) const;
   void loadFromFile(const std::string& filename);

   void printItems();



};


#endif //GA_PROJECT_KNAPSACKPROBLEM_H
