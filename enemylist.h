#ifndef ENEMYLIST_H
#define ENEMYLIST_H

#include"enemy.h"
#include<QVector>
#include<QGraphicsScene>
class EnemyList
{
public:
    EnemyList();
    QVector<Enemy*> mlist;
    QGraphicsScene*ptr;
    void produceEnemy();
    void EnemyListMove(QPointF target);
    void SetPtr(QGraphicsScene*_ptr);
    void RemoveDeadEnemy();
    void EnemyProduceEnemy();
};

#endif // ENEMYLIST_H

