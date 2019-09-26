//
// Created by 张自爆 on 2019/5/16.
//

#ifndef HELLO_CONFIG_H
#define HELLO_CONFIG_H

#include <QList>
#include "GameWorld.h"

class Config {

private:
    static int hidden_nodes;
    static int hidden_layers;
    static int fps;  //15 is ideal for self play, increasing for AI does not directly increase speed, speed is dependant on processing power
    static int highScore;
    static int score;
    static float mutationRate;
    static float defaultMutation;
    static int gridSize;
    static int gameMapSize;
    static int snakeSpeed;
public:
    static float getDefaultMutation();

    static void setDefaultMutation(float defaultMutation);

private:
    static bool humanPlaying;  //false for AI, true to play yourself
    static bool replayBest;  //shows only the best of each generation
    static bool seeVision;  //see the snakes vision
public:
    static int getHiddenNodes();

    static void setHiddenNodes(int hiddenNodes);

    static int getHiddenLayers();

    static void setHiddenLayers(int hiddenLayers);

    static int getFps();

    static void setFps(int fps);

    static int getHighScore();

    static void setHighScore(int highScore);

    static float getMutationRate();

    static void setMutationRate(float mutationRate);

    static float getDefaultmutation();

    static void setDefaultmutation(float defaultmutation);

    static bool isHumanPlaying();

    static void setHumanPlaying(bool humanPlaying);

    static bool isReplayBest();

    static void setReplayBest(bool replayBest);

    static bool isSeeVision();

    static void setSeeVision(bool seeVision);

    static bool isModelLoaded();

    static void setModelLoaded(bool modelLoaded);

private:
    static bool modelLoaded;
public:

public:
    Config();

    static int SnakeSpeed();

    static int GridSize();

    static int GameMapSize();

    static int getScore();

    static void setScore(int score);

};

#endif //HELLO_CONFIG_H
