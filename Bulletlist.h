#ifndef BULLETLIST_H
#define BULLETLIST_H

#include"enemylist.h"
#include<QVector>
#include<QGraphicsScene>
#include"Bullet.h"
class BulletList
{
public:
    BulletList();
    QVector<Bullet*> mlist;
    QGraphicsScene*ptr;
    void produceBullet(QPoint pos,QPoint direct);
    void BulletListMove();
    void SetPtr(QGraphicsScene*_ptr);
    void RemoveRunBullet();
    void RemoveHitBullet(EnemyList* mEnemyList);
};

#endif // BULLETLIST_H
