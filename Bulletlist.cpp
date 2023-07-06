#include "Bulletlist.h"

BulletList::BulletList()
{

}
void BulletList::produceBullet(QPoint pos,QPoint direct){
    Bullet* temp=new Bullet(pos);
    ptr->addItem(temp);
    temp->SetDirect(direct);
    mlist.push_back(temp);
}
void BulletList:: BulletListMove(){
    if(mlist.empty())return;
    for(auto i=mlist.begin();i!=mlist.end();i++){
        (*i)->BulletMove();
    }
};
void BulletList::SetPtr(QGraphicsScene*_ptr){
    ptr=_ptr;
};
void BulletList::RemoveRunBullet(){
    if(mlist.empty())return;
    for(auto i=mlist.begin();i!=mlist.end();i++){
        while((*i)->RunOut())
        {
            ptr->removeItem((*i));
            i=mlist.erase(i);
            if(i==mlist.end())return;
        }
        if(i==mlist.end())return;
    }
};
void BulletList::RemoveHitBullet(EnemyList* mEnemyList){
    if(mlist.empty())return;
    for(auto i=mlist.begin();i!=mlist.end();i++){
        while((*i)->ShootEnemy(mEnemyList))
        {
            ptr->removeItem((*i));
            i=mlist.erase(i);
            if(i==mlist.end())return;
        }
        if(i==mlist.end())return;
    }
};
