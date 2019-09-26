//
// Created by 张自爆 on 2019/5/22.
//
#ifndef HELLO_POPULATION_H
#define HELLO_POPULATION_H

#include "Snake.h"

class Population {
public:
    QList<Snake *> snakes;
    Snake *bestSnake;

    int bestSnakeScore = 0;
    int gen = 0;
    int samebest = 0;

    float bestFitness = 0;
    float fitnessSum = 0;
public:
    Population(int size);

    bool done();

    void setBestSnake();

    int selectParent();

    void naturalSelection();

    void mutate();

    void calculateFitness();

    void calculateFitnessSum();
};
#endif //HELLO_POPULATION_H
