//
// Created by 张自爆 on 2019/5/16.
//

#include <c++/iostream>
#include <QtWidgets/QMessageBox>
#include <math.h>
#include "Snake.h"
#include "Config.h"

Snake::Snake() {
    speed = Config::SnakeSpeed();
    // 回收食物
    food = new Food(body);
    if (!Config::isHumanPlaying()) {
        vision = MatrixXd(24, 1);
        decision = MatrixXd(4, 1);
//        qDeleteAll(foodList);
        foodList.clear();
        foodList.append(food->getPosition());
        // 回收脑子
        brain = new NeuralNetwork(24, Config::getHiddenNodes(), 4, Config::getHiddenLayers());
    } else if (Config::isModelLoaded()) {
        brain = GameWorld::getInstance()->getModel()->brain->clone();
    }
    move_steps = 0;
    body.clear();
    for (int i = 2; i >= 0; --i) {
        QList<int> temp_body;
        temp_body << i << 2;
        body.append(temp_body);
    }
    direction = 1;
    alive = true;
    score = body.size();
    //    move timer
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(crawl()));
    timer->start(speed);
}
//Snake::Snake(int layers) {
//    revive();
//}

Snake::Snake(QList<QList<int>> &foods) {
    speed = Config::SnakeSpeed();
    // 回收食物
    food = new Food(body);
    if (!Config::isHumanPlaying()) {
        vision = MatrixXd(24, 1);
        decision = MatrixXd(4, 1);
//        qDeleteAll(foodList);
        foodList.clear();
        foodList.append(food->getPosition());
        // 回收脑子
        brain = new NeuralNetwork(24, Config::getHiddenNodes(), 4, Config::getHiddenLayers());
    } else if (Config::isModelLoaded()) {
        brain = GameWorld::getInstance()->getModel()->brain->clone();
    }
    move_steps = 0;
    body.clear();
    for (int i = 2; i >= 0; --i) {
        QList<int> temp_body;
        temp_body << i << 2;
        body.append(temp_body);
    }
    direction = 1;
    alive = true;
    score = body.size();
    replay = true;
    foodList.clear();
    for (int i = 0; i < foods.size(); ++i) {  //clone all the food positions in the foodlist
        foodList.append(foods[i]);
    }
    food->setPosition(foodList[foodIterate]);
    foodIterate++;
    //    move timer
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(crawl()));
    timer->start(speed);
}

void Snake::SnakeDead() {
    alive = false;
}

void Snake::crawl() {
    if (alive) {
        if (!Config::isHumanPlaying()) {
            look();
            think();
        }
        if (!Config::isHumanPlaying() and !Config::isModelLoaded()) {
            lifetime++;
            lifeLeft--;
        }
        int prev_x = body[0][0];
        int prev_y = body[0][1];
        int next_x = prev_x, next_y = prev_y;
        switch (direction) {
            case 0:
                //  up
                next_y -= 1;
                break;
            case 1:
                // right
                next_x += 1;
                break;
            case 2:
                // down
                next_y += 1;
                break;
            case 3:
                // left
                next_x -= 1;
                break;
        }
        if (isHitWall(next_x, next_y) or
            isHitSelf(next_x, next_y) or
            (lifeLeft <= 0 and !Config::isHumanPlaying())) {
            SnakeDead();
        } else {
            if (isHitFood(next_x, next_y)) {
                eat();
            }
//  移动蛇的身体
            body[0][0] = next_x;
            body[0][1] = next_y;
            for (int i = 1; i < body.size(); i++) {
                int temp_x = prev_x;
                int temp_y = prev_y;
                prev_x = body[i][0];
                prev_y = body[i][1];
                body[i][0] = temp_x;
                body[i][1] = temp_y;
            }
            ++move_steps;
        }
    }
}

bool Snake::isHitWall(double x, double y) {
    if ((x >= Config::GameMapSize()) or x <= -1 or (y >= Config::GameMapSize()) or y <= -1) {
        return true;
    }
    return false;
}

bool Snake::isHitFood(double x, double y) {
    if (!food->isAte() and x == food->getPosition()[0] and
        y == food->getPosition()[1]) {
        return true;
    } else {
        return false;
    }
}

void Snake::look() {
    vision = MatrixXd(24, 1);
    // -1,0
    int candidate[16] = {-1, 0, -1, -1, 0, -1, 1, -1, 1, 0, 1, 1, 0, 1, -1, 1};
    QList<double> data;
    for (int i = 0; i < 8; ++i) {
        QList<double> temp;
        temp << candidate[2 * i] << candidate[2 * i + 1];
        data.append(lookInDirection(temp));
    }
    for (int i = 0; i < data.size(); ++i) {
        vision(i, 0) = data[i];
    }
}

void Snake::think() {
    decision = brain->output(vision);
    MatrixXd::Index maxRow, maxCol;
    int maxIndex = 0;
    decision.maxCoeff(&maxRow, &maxCol);
    maxIndex = maxRow;
    switch (maxIndex) {
        case 0:
//            up
            direction = 0;
            break;
        case 1:
//            down
            direction = 2;
            break;
        case 2:
//            left
            direction = 3;
            break;
        case 3:
//            right
            direction = 1;
            break;
        default:
            break;
    }
}

QList<double> Snake::lookInDirection(QList<double> the_direction) {
    QList<double> look;
    QList<double> pos;
    look << 0 << 0 << 0;
    pos << body.constFirst()[0] << body.constFirst()[1];
    double distance = 0;
    bool foodFound = false;
    bool bodyFound = false;
    pos[0] += the_direction[0];
    pos[1] += the_direction[1];
    distance += 1;
    while (!isHitWall(pos[0], pos[1])) {
        if (!foodFound && isHitFood(pos[0], pos[1])) {
            foodFound = true;
            look[0] = 1;
        }
        if (!bodyFound && isHitSelf(pos[0], pos[1])) {
            bodyFound = true;
            look[1] = 1;
        }
        pos[0] += the_direction[0];
        pos[1] += the_direction[1];
        distance += 1;
    }
    look[2] = 1 / distance;
    return look;
}

void Snake::calculateFitness() {
    if (score < 10) {
        fitness = floor(lifetime * lifetime) * pow(2, score);
    } else {
        fitness = floor(lifetime * lifetime);
        fitness *= pow(2, 10);
        fitness *= (score - 9);
    }
}

Snake *Snake::cloneForReplay() {
    Snake *clone = new Snake(foodList);
    clone->brain = brain->clone();
    return clone;
}

Snake *Snake::clone() {
    Snake *clone = new Snake();
    clone->brain = brain->clone();
//    std::cout<<clone->food->getPosition()[0]<<std::endl;
    return clone;
}

Snake *Snake::crossover(Snake *parent) {
    Snake *child = new Snake();
    delete child->brain;
    child->brain = NULL;
    child->brain = brain->crossover(parent->brain);
    return child;
}

void Snake::mutate() {
    brain->mutate(Config::getMutationRate());
}

void Snake::eat() {
    score++;
    QList<int> tail = body.constLast();
    QList<int> insert_node;
    insert_node << tail[0] << tail[1];
    body.append(insert_node);
    if (!Config::isHumanPlaying() && !Config::isModelLoaded()) {
        if (lifeLeft < 500) {
            if (lifeLeft > 400) {
                lifeLeft = 500;
            } else {
                lifeLeft += 100;
            }
        }
    }
    if (!replay) {
        if (!Config::isHumanPlaying()) {
            foodList.append(food->getPosition());
        }
    } else {  //if the snake is a replay, then we dont want to create new random foods, we want to see the positions the best snake had to collect
        food->setPosition(foodList[foodIterate]);
        foodIterate++;
    }
    // 更新食物位置和lifetime
    food->resurgence(body);
}

void Snake::revive() {
    // 更新食物
    food->resurgence(body);
    move_steps = 0;
    direction = 1;
    alive = true;
    // 更新身体
    score = body.size();
    body.clear();
    for (int i = 2; i >= 0; --i) {
        QList<int> temp_body;
        temp_body << i << 2;
        body.append(temp_body);
    }
}

bool Snake::isHitSelf(double x, double y) {
    for (int i = 1; i < body.size(); i++) {
        if (x == body[i][0] and y == body[i][1]) {
            return true;
        }
    }
    return false;
}

bool Snake::isAlive() const {
    return alive;
}

void Snake::setAlive(bool alive) {
    Snake::alive = alive;
}

int Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(int direction) {
    Snake::direction = direction;
}

QList<QList<int>> &Snake::getBody() {
    return body;
}

void Snake::setBody(const QList<QList<int>> &body) {
    Snake::body = body;
}

int Snake::getSpeed() const {
    return speed;
}

void Snake::setSpeed(int speed) {
    Snake::speed = speed;
}

int Snake::getMoveSteps() const {
    return move_steps;
}

void Snake::setMoveSteps(int moveSteps) {
    move_steps = moveSteps;
}

Snake::~Snake() {
    delete brain;
    delete food;
    delete timer;

}

