//
// Created by Mateusz on 15.01.2023.
//

#include <fstream>
#include <utility>
#include <iostream>
#include "KnapsackProblem.h"

//KnapsackProblem::KnapsackProblem(std::vector<std::pair<double, double>> itemList, double backpackSize)
//        : itemList(std::move(itemList)), backpackSize(backpackSize) {
//    if(backpackSize <= 0){
//        throw std::out_of_range("WRONG BACKPACK SIZE");
//    }
//}

KnapsackProblem::KnapsackProblem(double backpackSize, std::string filename) : backpackSize(backpackSize) {
    if(backpackSize <= 0){
        throw std::out_of_range("WRONG BACKPACK SIZE");
    }
    loadFromFile(filename);
}

const std::vector<std::pair<double, double>> &KnapsackProblem::getItemList() const {
    return itemList;
}

double KnapsackProblem::getBackpackSize() const {
    return backpackSize;
}

double KnapsackProblem::evaluate(const std::vector<int> &genotype) const {
    double totalValue = 0;
    double totalSize = 0;
    for(int i = 0; i < genotype.size(); i++){
        if(genotype.at(i) == 1){
            totalValue += itemList.at(i).first;
            totalSize += itemList.at(i).second;
        }
    }

    double tempFitness;
    if(totalSize <= backpackSize){
        tempFitness = totalValue;
    }else{
        tempFitness = 0;
    }
    return tempFitness;
}

void KnapsackProblem::loadFromFile(const std::string& filename) {

        try{
            std::ifstream stream(filename);
            double val = 0;
            double wg = 0;

            while(stream >> val >> wg){

                if(val >= 0 && wg >= 0){
                    itemList.push_back(std::make_pair(val,wg));
                }else{
                    throw std::out_of_range("WRONG ITEM VALUES IN FILE");
                }
            }

        }catch(std::exception& exception){
            exception.what();
        }

}

void KnapsackProblem::printItems() {
    for(std::pair<double,double> item : itemList){
        std::cout << "(" << item.first << "," << item.second << ")" << " ";
    }
    std::cout << "\n";
}