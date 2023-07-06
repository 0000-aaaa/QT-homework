#include "Bullet.h"

Bullet::Bullet(QPoint _pos)
{
    ATK=10;
    speed=1;
    this->setPos(_pos);
    this->setPixmap(QPixmap(":/new/prefix1/imag/bullet.jpg"));
}
void Bullet::SetDirect(QPoint _direct){
    this->direct=_direct;
}
void Bullet::BulletMove(){
    double dx=direct.x();
    double dy=direct.y();
    this->moveBy(speed*dx/sqrt(dx*dx+dy*dy),speed*dy/sqrt(dx*dx+dy*dy));
}
bool Bullet::ShootEnemy(EnemyList *mEnemylist){
    if(mEnemylist->mlist.empty())return false;
    for(auto i=mEnemylist->mlist.begin();i!=mEnemylist->mlist.end();i++){
        if((*i)->ifcontain(this->pos())){
            (*i)->hp-=this->ATK;
            return true;
        }
    }
    return false;
}
bool Bullet::RunOut(){
    if(this->x()<0||this->x()>512||this->y()<0||this->y()>768)
        return true;
    else return false;
}
