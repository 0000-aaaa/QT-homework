#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<qmath.h>
class Enemy : public QGraphicsPixmapItem
{

public:
    explicit Enemy();
    int hp;
    QPoint target;
    double speed;
    int type;
    void EnemyMove();
    bool ifcontain(QPointF _pos);

};

#endif // ENEMY_H

