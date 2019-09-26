//
// Created by 张自爆 on 2019/5/16.
//

#include "Food.h"
#include <cstdlib>
#include <Config.h>
#include <QBrush>
#include <c++/iostream>
#include <math.h>
#include <processthreadsapi.h>
#include <Headers/Util.h>

Food::Food() {

}
Food::Food(QList<QList<int>> body) {
    //初始化食物可出现位置
    while (true) {
        int x = Util::random_unint(0, Config::GameMapSize() - 1);
        int y = Util::random_unint(0, Config::GameMapSize() - 1);
        bool position_useful = true;
        for (int k = 0; k < body.size(); k++) {
            if (x == body[k][0] and y == body[k][1]) {
                position_useful = false;
            }
        }
        if (position_useful) {
            QList<int> per_spot;
            per_spot << x << y;
            setPosition(per_spot);
            break;
        }
    }
//    life_time = 5;
    ate = false;
};

void Food::resurgence(QList<QList<int>> body) {
    //初始化食物可出现位置
    while (true) {
        int x = Util::random_unint(0, Config::GameMapSize() - 1);
        int y = Util::random_unint(0, Config::GameMapSize() - 1);
        bool position_useful = true;
        for (int k = 0; k < body.size(); k++) {
            if (x == body[k][0] and y == body[k][1]) {
                position_useful = false;
            }
        }
        if (position_useful) {
            QList<int> per_spot;
            per_spot << x << y;
            setPosition(per_spot);
            break;
        }
    }
//    life_time = 5;
    ate = false;
//    timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), this, SLOT(deathWard()));
//    timer->start(1000);
}



//void Food::deathWard() {
//    --life_time;
//}

const QList<int> &Food::getPosition() const {
    return position;
}

void Food::setPosition(const QList<int> &position) {
    Food::position = position;
}

int Food::getLifeTime() const {
    return life_time;
}

void Food::setLifeTime(int lifeTime) {
    life_time = lifeTime;
}

bool Food::isAte() const {
    return ate;
}

void Food::setAte(bool ate) {
    Food::ate = ate;
}

Food::~Food() {

}
