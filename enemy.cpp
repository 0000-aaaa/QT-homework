#include "enemy.h"

Enemy::Enemy()

{
    hp=100;
    speed=2;
    target=QPoint(500,500);
    this->setPixmap(QPixmap(":/new/prefix1/imag/OIP.png"));
    this->setPos(200,200);
   // this->moveBy(100,100);
}
void Enemy::EnemyMove(){
    double dx=target.x()-this->x();
    double dy=target.y()-this->y();
    this->moveBy(speed*dx/sqrt(dx*dx+dy*dy),speed*dy/sqrt(dx*dx+dy*dy));
}
bool  Enemy::ifcontain(QPointF _pos){
    if(abs(this->x()-_pos.x())<=this->pixmap().width()&&abs(this->y()-_pos.y())<=this->pixmap().height())
        return true;
    else return false;
}
