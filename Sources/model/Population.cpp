//
// Created by 张自爆 on 2019/5/22.
//

#include <c++/iostream>
#include "Population.h"
#include "Util.h"
#include "Config.h"

Population::Population(int size) {
    for (int i = 0; i < size; i++) {
        snakes.append(new Snake());
    }
    bestSnake = snakes[0]->clone();
    bestSnake->replay = true;
}

bool Population::done() {  //check if all the snakes in the population are dead
    for (int i = 0; i < snakes.size(); i++) {
        if (snakes[i]->isAlive()) {
            return false;
        }
    }
    if (bestSnake->isAlive()) {
        return false;
    }
    return true;
}

void Population::setBestSnake() {  //set the best snake of the generation
    float max = 0;
    int maxIndex = 0;
    for (int i = 0; i < snakes.size(); i++) {
        if (snakes[i]->fitness > max) {
            max = snakes[i]->fitness;
            maxIndex = i;
        }
    }
    if (max > bestFitness) {
        bestFitness = max;
        delete bestSnake;
//        bestSnake
        bestSnake = snakes[maxIndex]->cloneForReplay();
        bestSnakeScore = snakes[maxIndex]->score;
        //samebest = 0;
        //mutationRate = defaultMutation;
    } else {
        Snake *temp_snake = bestSnake->cloneForReplay();
        delete bestSnake;
        bestSnake = temp_snake;
        /*
        samebest++;
        if(samebest > 2) {  //if the best snake has remained the same for more than 3 generations, raise the mutation rate
           mutationRate *= 2;
           samebest = 0;
        }*/
    }
}

int Population::selectParent() {
    //selects a random number in range of the fitnesssum and if a snake falls in that range then select it
    float rand = Util::random_double(0, fitnessSum);
    float summation = 0;
    for (int i = 0; i < snakes.size(); i++) {
        summation += snakes[i]->fitness;
        if (summation > rand) {
            return i;
        }
    }
    return 0;
}

void Population::naturalSelection() {
    QList<Snake *> newSnakes;
    setBestSnake();
    calculateFitnessSum();
    newSnakes.append(bestSnake->clone());  //add the best snake of the prior generation into the new generation
    for (int i = 1; i < snakes.size(); i++) {
        int index_parent = selectParent();
        Snake *child = snakes[index_parent]->crossover(snakes[index_parent]);
        child->mutate();
        newSnakes.append(child);
    }
    qDeleteAll(snakes);
    snakes.clear();
    snakes.append(newSnakes);
    gen += 1;
    // 额外的代码
    // c++ 析构函数
}

// this function is never used
void Population::mutate() {
    for (int i = 1; i < snakes.size(); i++) {  //start from 1 as to not override the best snake placed in index 0
        snakes[i]->mutate();
    }
}

void Population::calculateFitness() {  //calculate the fitnesses for each snake
    for (int i = 0; i < snakes.size(); i++) {
        snakes[i]->calculateFitness();
    }
}

void Population::calculateFitnessSum() {  //calculate the sum of all the snakes fitnesses
    fitnessSum = 0;
    for (int i = 0; i < snakes.size(); i++) {
        fitnessSum += snakes[i]->fitness;
    }
}