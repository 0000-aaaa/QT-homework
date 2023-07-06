#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<qmath.h>
#include<QtGlobal>
#include<QString>
class Enemy : public QGraphicsPixmapItem
{

public:
    explicit Enemy(int _type);
    int hp;
    //QPoint target;
    double speed;
    int type;
    void EnemyMove(QPointF target);
    bool ifcontain(QPointF _pos);

};
//QString Img111[5]={":/new/prefix1/imag/nor.png",":/new/prefix1/imag/Bomb.jpg.jpg",":/new/prefix1/imag/no1.jpg",":/new/prefix1/imag/6193.png_860.png",":/new/prefix1/imag/arm.jpg"};//用来表示士兵种类
#endif // ENEMY_H

