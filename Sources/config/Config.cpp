//
// Created by 张自爆 on 2019/5/16.
//
#include "Config.h"

// 地图参数
int Config::gridSize = 20;
int Config::gameMapSize = 38;
int Config::snakeSpeed = 50;
//神经网络参数
int Config::hidden_nodes = 16;
int Config::hidden_layers = 2;
int Config::fps = 100;  //15 is ideal for self play, increasing for AI does not directly increase speed, speed is dependant on processing power
// 当前玩蛇分数
int Config::score = 0;
// 最高分数
int  Config::highScore = 0;

float Config::mutationRate = 0.05;
float  Config::defaultMutation = Config::mutationRate;

bool  Config::humanPlaying = true;  //false for AI, true to play yourself
bool  Config::replayBest = true;  //shows only the best of each generation
bool  Config::seeVision = false;  //see the snakes visione
bool  Config::modelLoaded = false;

int Config::getScore() {
    return score;
}

void Config::setScore(int score) {
    Config::score = score;
}

int Config::GridSize() {
    return gridSize;
}

int Config::GameMapSize() {
    return gameMapSize;
}

int Config::SnakeSpeed() {
    return snakeSpeed;
}


int Config::getHiddenNodes() {
    return hidden_nodes;
}

void Config::setHiddenNodes(int hiddenNodes) {
    hidden_nodes = hiddenNodes;
}

int Config::getHiddenLayers() {
    return hidden_layers;
}

void Config::setHiddenLayers(int hiddenLayers) {
    hidden_layers = hiddenLayers;
}

int Config::getFps() {
    return fps;
}

void Config::setFps(int fps) {
    Config::fps = fps;
}

int Config::getHighScore() {
    return highScore;
}

void Config::setHighScore(int highScore) {
    Config::highScore = highScore;
}

float Config::getMutationRate() {
    return mutationRate;
}

void Config::setMutationRate(float mutationRate) {
    Config::mutationRate = mutationRate;
}


bool Config::isHumanPlaying() {
    return humanPlaying;
}

void Config::setHumanPlaying(bool humanPlaying) {
    Config::humanPlaying = humanPlaying;
}

bool Config::isReplayBest() {
    return replayBest;
}

void Config::setReplayBest(bool replayBest) {
    Config::replayBest = replayBest;
}

bool Config::isSeeVision() {
    return seeVision;
}

void Config::setSeeVision(bool seeVision) {
    Config::seeVision = seeVision;
}

bool Config::isModelLoaded() {
    return modelLoaded;
}

void Config::setModelLoaded(bool modelLoaded) {
    Config::modelLoaded = modelLoaded;
}

float Config::getDefaultMutation() {
    return defaultMutation;
}

void Config::setDefaultMutation(float defaultMutation) {
    Config::defaultMutation = defaultMutation;
}

