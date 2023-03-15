cmake_minimum_required(VERSION 3.23)
project(GA_Project)

set(CMAKE_CXX_STANDARD 11)

add_executable(GA_Project main.cpp Individual.cpp Individual.h KnapsackProblem.cpp KnapsackProblem.h GeneticAlgorithm.cpp GeneticAlgorithm.h RandomGenerator.cpp RandomGenerator.h)
