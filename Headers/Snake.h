//
// Created by 张自爆 on 2019/5/16.
//
#ifndef HELLO_SNAKE_H
#define HELLO_SNAKE_H

#include <QList>
#include <QObject>
#include <QtCore/QTimer>
#include <NeuralNetwork.h>
#include <Dense>
#include <Food.h>

using Eigen::MatrixXd;

class Snake : public QObject {
Q_OBJECT
private:
    QTimer *timer;
    int speed;
    int move_steps;
private:
    bool alive;
    QList<QList<int>> body;
public:
    int score;
    int lifeLeft = 100;  //amount of moves the snake can make before it dies
    int lifetime = 0;  //amount of time the snake has been alive
    int foodIterate = 0;
    float fitness = 0;
    bool replay = false;  //if this snake is a replay of best snake
    int direction; //    上：0  右：1  下： 2  左：3
    MatrixXd vision;
    MatrixXd decision;
    NeuralNetwork *brain;
    QList<QList<int>> foodList; //list of food positions (used to replay the best snake)
    Food *food;
public:
    Snake();

    Snake(int layers);

    Snake(QList<QList<int>> &foods);

    void SnakeDead();

    virtual ~Snake();

    void calculateFitness();

    // 参数：头下一次出现的位置坐标
    bool isHitSelf(double x, double y);

    bool isHitFood(double x, double y);

    bool isHitWall(double x, double y);

    void eat();

    void look();

    void think();

    QList<double> lookInDirection(QList<double> direction);

    Snake *cloneForReplay();

    Snake *clone();

    Snake *crossover(Snake *parent);

    void mutate();

    void revive();

public slots:

    void crawl();

public:
    int getMoveSteps() const;

    void setMoveSteps(int moveSteps);

    int getSpeed() const;

    void setSpeed(int speed);

    int getDirection() const;

    void setDirection(int direction);

    QList<QList<int>> &getBody();

    void setBody(const QList<QList<int>> &body);

    bool isAlive() const;

    void setAlive(bool alive);
};


#endif //HELLO_SNAKE_H
