//
// Created by 张自爆 on 2019/5/16.
//

#ifndef HELLO_FOOD_H
#define HELLO_FOOD_H


#include <QtCore/QList>
#include <QGraphicsRectItem>
#include <QtCore/QTimer>

class Food : public QObject {
Q_OBJECT
private:
    QList<int> position;
    int life_time;
    bool ate;
    QTimer *timer;
public:
    bool isAte() const;

    void setAte(bool ate);

public:
    const QList<int> &getPosition() const;

    void setPosition(const QList<int> &position);

    int getLifeTime() const;

    virtual ~Food();

    void setLifeTime(int lifeTime);

public:
    Food();
    Food(QList<QList<int>> body);

    void resurgence(QList<QList<int>> body);

public slots:

//    void deathWard();

};


#endif //HELLO_FOOD_H
