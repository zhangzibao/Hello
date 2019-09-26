//
// Created by 张自爆 on 2019/5/21.
//

#ifndef HELLO_TRAININGPANEL_H
#define HELLO_TRAININGPANEL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets/QApplication>
#include <QKeyEvent>
#include <QPaintEvent>
#include "Snake.h"
#include "Food.h"

class TrainingPanel: public QGraphicsView  {
Q_OBJECT
private:
    TrainingPanel();
    QGraphicsScene *MainPanel;
    static TrainingPanel *instance;
    QTimer *timer;
public:
    static TrainingPanel *getInstance();
    static pthread_mutex_t mutex;
public:
    void initialize();
public slots:

    void Redraw();
};


#endif //HELLO_TRAININGPANEL_H
