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
    void EnemyListMove();
    void SetPtr(QGraphicsScene*_ptr);
    void RemoveDeadEnemy();
};

#endif // ENEMYLIST_H

