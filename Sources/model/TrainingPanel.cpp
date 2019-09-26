//
// Created by 张自爆 on 2019/5/21.
//

#include "TrainingPanel.h"
#include <GameWorld.h>
#include "Config.h"

TrainingPanel *TrainingPanel::instance = NULL;
QGraphicsTextItem *score_item = NULL;
QGraphicsTextItem *HighScore_item = NULL;

void TrainingPanel::initialize() {
    MainPanel = new QGraphicsScene(this);
    setScene(MainPanel);
    // 重绘线程
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Redraw()));
    timer->start(10);
}

// 单例模式
pthread_mutex_t TrainingPanel::mutex;

TrainingPanel *TrainingPanel::getInstance() {
    if (instance == NULL) {
        pthread_mutex_lock(&mutex);
        if (instance == NULL) {
            instance = new TrainingPanel();
        }
        pthread_mutex_unlock(&mutex);
    }
    return instance;
}

void TrainingPanel::Redraw() {
    //最高分的重绘
    if (HighScore_item != NULL) {
        MainPanel->removeItem(HighScore_item);
        delete HighScore_item;
        HighScore_item = NULL;
    }
    HighScore_item = new QGraphicsTextItem();
    HighScore_item->setPlainText(QString("The Highest Score : ") + QString::number(Config::getHighScore()));
    HighScore_item->setFont(QFont("华文琥珀", 12));
    HighScore_item->setDefaultTextColor(QColor(0, 0, 0));
    HighScore_item->setPos(0, 0);
    MainPanel->addItem(HighScore_item);

    //当前在跑蛇分数的重绘
    if (score_item != NULL) {
        MainPanel->removeItem(score_item);
        delete score_item;
        score_item = NULL;
    }
    score_item = new QGraphicsTextItem();
    score_item->setPlainText(QString("The current snake's Score : ") + QString::number(Config::getScore()));
    score_item->setFont(QFont("华文琥珀", 12));
    score_item->setDefaultTextColor(QColor(0, 0, 0));
    score_item->setPos(20, 20);
    MainPanel->addItem(score_item);
}

TrainingPanel::TrainingPanel() {
//    initialize();
}