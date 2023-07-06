#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include <QObject>
#include<QGraphicsPixmapItem>
#include<qmath.h>
#include"enemylist.h"
class Bullet : public QGraphicsPixmapItem
{

public:
    explicit Bullet(QPoint _pos);
    int ATK;
    QPoint direct;
    int speed;
    void SetDirect(QPoint _direct);
    void BulletMove();
    bool ShootEnemy(EnemyList* mEnemylist);
    bool RunOut();
};

#endif // BULLET_H
