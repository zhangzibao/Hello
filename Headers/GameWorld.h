//
// Created by 张自爆 on 2019/5/16.
//

#ifndef HELLO_GAMEWORLD_H
#define HELLO_GAMEWORLD_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets/QApplication>
#include <QKeyEvent>
#include <QPaintEvent>
#include "Snake.h"
#include "Food.h"
#include "Population.h"

class GameWorld : public QGraphicsView {
Q_OBJECT
private:
    static GameWorld *instance;
    QGraphicsScene *foundation;
    QApplication *app;
    Snake *snake;
    Snake *model;
    Population *pop;
    QTimer *timer;

private:
    GameWorld();

public:

    void draw_snake_and_food(Snake *obj);

    void Creation();


protected:
    void keyPressEvent(QKeyEvent *event);

public:
    static GameWorld *getInstance();

    static pthread_mutex_t mutex;
public slots:

    void Redraw();

public:
    Snake *getModel() const;

    void setModel(Snake *model);

    Snake *getSnake();

    void setSnake(Snake *snake);

    QApplication *getApp() const;

    void setApp(QApplication *app);

    QGraphicsScene *getFoundation() const;

    void setFoundation(QGraphicsScene *foundation);
};

#endif //HELLO_GAMEWORLD_H
