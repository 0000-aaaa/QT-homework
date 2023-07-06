#include "enemy.h"

Enemy::Enemy (int _type)

{
    type=_type;
    switch(_type){
    case 0:
        hp=100;
        speed=5;
    //target=QPoint(500,500);
        this->setPixmap(QPixmap(":/new/prefix1/imag/nor.png"));
        break;
    case 1:
        hp=150;
        speed=2;
        this->setPixmap(QPixmap(":/new/prefix1/imag/Bomb.jpg.jpg"));
        break;
    case 2:
        hp=50;
        speed=10;
        this->setPixmap(QPixmap(":/new/prefix1/imag/no1.jpg"));
        break;
    case 3:
        hp=200;
        speed=1;
        this->setPixmap(QPixmap(":/new/prefix1/imag/6193.png_860.png"));
        break;
    case 4:
        hp=150;
        speed=0;
        this->setPixmap(QPixmap(":/new/prefix1/imag/arm.jpg"));
        break;
    default:break;
    }



    int PosX=rand()%500;
    int PosY=rand()%500;
    this->setPos(PosX,PosY);
   // this->moveBy(100,100);
}
void Enemy::EnemyMove(QPointF target){
    double dx=target.x()-this->x();
    double dy=target.y()-this->y();
    this->moveBy(speed*dx/sqrt(dx*dx+dy*dy),speed*dy/sqrt(dx*dx+dy*dy));
}
bool  Enemy::ifcontain(QPointF _pos){
    if(abs(this->x()-_pos.x())<=this->pixmap().width()&&abs(this->y()-_pos.y())<=this->pixmap().height())
        return true;
    else return false;
}
