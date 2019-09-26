//
// Created by 张自爆 on 2019/5/16.
//

#include <QtWidgets/QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <c++/iostream>
#include "GameWorld.h"
#include "Config.h"

GameWorld *GameWorld::instance = NULL;
QGraphicsItemGroup *Snake_body_items = NULL;
QGraphicsRectItem *food_item = NULL;
int pre_moveSteps = 0;

// 创世
void GameWorld::Creation() {
    setFoundation(new QGraphicsScene(this));
    //绘制地图
    QGraphicsRectItem *background = new QGraphicsRectItem(0, 0,
                                                          Config::GameMapSize() * Config::GridSize(),
                                                          Config::GameMapSize() * Config::GridSize());
    background->setBrush(QBrush(QColor(0, 0, 0)));
    foundation->addItem(background);

    setScene(foundation);
    //初始化蛇
    if (Config::isHumanPlaying()) {
        snake = new Snake();
    } else {
        pop = new Population(200); //adjust size of population
//        std::cout<<pop->bestSnake->food->getPosition()[0]<<","<<pop->bestSnake->food->getPosition()[0]<<std::endl;
    }
    // 重绘线程
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Redraw()));
    timer->start(10);

}

void GameWorld::Redraw() {
//   蛇的重绘
    if (Config::isHumanPlaying()) {
        Config::setScore(snake->score);
        draw_snake_and_food(snake);
    } else {
        Config::setScore(pop->bestSnake->score);
//        if (!Config::isModelLoaded()) {
            // 开始蛇的神经网络训练
            if (pop->done()) {
                Config::setHighScore(pop->bestSnake->score);
                pop->calculateFitness();
                pop->naturalSelection();
            } else {
                if (Config::isReplayBest()) {
                    draw_snake_and_food(pop->bestSnake);
                }
            }
//        }
    }
}

void GameWorld::draw_snake_and_food(Snake *obj) {
    // 画蛇
    if (Snake_body_items != NULL) {
        foundation->removeItem(Snake_body_items);
        delete Snake_body_items;
        Snake_body_items = NULL;
    }
    Snake_body_items = new QGraphicsItemGroup();
    for (int i = 0; i < obj->getBody().size(); i++) {
        int x = obj->getBody()[i][0];
        int y = obj->getBody()[i][1];
        QGraphicsRectItem *graphic_node = new QGraphicsRectItem(x * Config::GridSize(), y * Config::GridSize(),
                                                                Config::GridSize(), Config::GridSize());
        graphic_node->setBrush(QBrush(QColor(255, 255, 255)));
        Snake_body_items->addToGroup(graphic_node);
    }
    foundation->addItem(Snake_body_items);

    // 画食物
    if (food_item != NULL) {
        foundation->removeItem(food_item);
        delete food_item;
        food_item = NULL;
    }
    food_item = new QGraphicsRectItem(obj->food->getPosition()[0] * Config::GridSize(),
                                      obj->food->getPosition()[1] * Config::GridSize(),
                                      Config::GridSize(), Config::GridSize());
    food_item->setBrush(QBrush(QColor(124, 252, 0)));
    foundation->addItem(food_item);
}

void GameWorld::keyPressEvent(QKeyEvent *event) {
    if (Config::isHumanPlaying()) {
        if (!snake->isAlive()) {
            if (event->isAutoRepeat()) return;
            //            复活
            if (event->key() == Qt::Key_Space) {
                getSnake()->revive();
            }
        }
        if (pre_moveSteps != snake->getMoveSteps()) {
            switch (event->key()) {
                case Qt::Key_Up:
                    if (event->isAutoRepeat()) return;
                    if (getSnake()->getDirection() != 2) {
                        getSnake()->setDirection(0);
                    }
                    break;
                case Qt::Key_Right:
                    if (event->isAutoRepeat()) return;
                    if (getSnake()->getDirection() != 3) {
                        getSnake()->setDirection(1);
                    }
                    break;
                case Qt::Key_Down:
                    if (event->isAutoRepeat()) return;
                    if (getSnake()->getDirection() != 0) {
                        getSnake()->setDirection(2);
                    }
                    break;
                case Qt::Key_Left:
                    if (event->isAutoRepeat()) return;
                    if (getSnake()->getDirection() != 1) {
                        getSnake()->setDirection(3);
                    }
                    break;
                case Qt::Key_Control:
//            加速
                    if (event->isAutoRepeat()) return;
                    break;
                case Qt::Key_Alt:
//            减速
                    if (event->isAutoRepeat()) return;
                    break;
            }
            pre_moveSteps = snake->getMoveSteps();
        }
    }
}

// 单例模式
pthread_mutex_t GameWorld::mutex;

GameWorld *GameWorld::getInstance() {
    if (instance == NULL) {
        pthread_mutex_lock(&mutex);
        if (instance == NULL) {
            instance = new GameWorld();
        }
        pthread_mutex_unlock(&mutex);
    }
    return instance;
}

QApplication *GameWorld::getApp() const {
    return app;
}

void GameWorld::setApp(QApplication *app) {
    GameWorld::app = app;
}

QGraphicsScene *GameWorld::getFoundation() const {
    return foundation;
}

void GameWorld::setFoundation(QGraphicsScene *scene) {
    GameWorld::foundation = scene;
}

Snake *GameWorld::getSnake() {
    return snake;
}

void GameWorld::setSnake(Snake *snake) {
    GameWorld::snake = snake;
}

GameWorld::GameWorld() {
}

Snake *GameWorld::getModel() const {
    return model;
}

void GameWorld::setModel(Snake *model) {
    GameWorld::model = model;
}
