#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include"enemy.h"
#include"enemylist.h"
#include<QTimer>
#include"Bulletlist.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::Widget *ui;
    QGraphicsView mGameView;
    QGraphicsScene mScene;
    QGraphicsPixmapItem mbackground;
    //Enemy menemy;
    EnemyList* mEnemyList;//敌人队列
    BulletList* mBulletList;//子弹队列

    QTimer* mEnemyProduceTimer;//敌人产生计时器
    QTimer* mEnemyMoveTimer;//敌人移动计时器
    QTimer* mBulletMoveTimer;//子弹移动计时器
    QTimer* mEnemyRemoveTimer;//去除死亡敌人计时器
    QTimer* mRemoveRunBulletTimer;//去除飞出边界子弹计时器
    QTimer* mRemoveHitBulletTimer;//去除击中敌人子弹计时器
};
#endif // WIDGET_H
