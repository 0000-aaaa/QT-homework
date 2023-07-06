#include "enemylist.h"

EnemyList::EnemyList()
{

}

void EnemyList::produceEnemy(){
    Enemy* temp=new Enemy();
    ptr->addItem(temp);
    mlist.push_back(temp);
}
void EnemyList::EnemyListMove(){
    if(mlist.empty())return;
    for(auto i=mlist.begin();i!=mlist.end();i++){
        (*i)->EnemyMove();
    }
}
void EnemyList::SetPtr(QGraphicsScene*_ptr){
    ptr=_ptr;
}
void EnemyList::RemoveDeadEnemy(){
    if(mlist.empty())return ;
    for(auto i=mlist.begin();i!=mlist.end();i++){
        while((*i)->hp<=0){
            ptr->removeItem((*i));
            i=mlist.erase(i);
            if(i==mlist.end())return;
        }
        if(i==mlist.end())return ;
    }
}
