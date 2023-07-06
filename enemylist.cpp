#include "enemylist.h"

EnemyList::EnemyList()
{

}

void EnemyList::produceEnemy(){
    int num=rand()%5;
    Enemy* temp=new Enemy(num);
    ptr->addItem(temp);
    mlist.push_back(temp);
}
void EnemyList::EnemyListMove(QPointF target){
    if(mlist.empty())return;
    for(auto i=mlist.begin();i!=mlist.end();i++){
        (*i)->EnemyMove(target);
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
            Enemy* temp=*i;
            i=mlist.erase(i);
            delete temp;
            if(i==mlist.end())return;
        }
        if(i==mlist.end())return ;
    }
}
void EnemyList::EnemyProduceEnemy(){
    if(mlist.empty())return;
    for(auto i=mlist.begin();i!=mlist.end();i++){
        if((*i)->type==4){
            Enemy* temp=new Enemy(2);
            temp->setPos((*i)->pos());
            ptr->addItem(temp);
            mlist.push_back(temp);
        }
    }
}
