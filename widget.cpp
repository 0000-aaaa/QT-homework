#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setFixedSize(512,768);
    //敌人队列初始化
    mEnemyList=new EnemyList();
    mEnemyList->SetPtr(&mScene);
    //子弹队列初始化
    mBulletList=new BulletList();
    mBulletList->SetPtr(&mScene);
    //游戏界面产生
    mGameView.setSceneRect(QRect(0,0,512,768));
    mScene.setSceneRect(QRect(0,0,512,768));
    mbackground.setPixmap(QPixmap(":/new/prefix1/imag/1.jpg"));
    mScene.addItem(&mbackground);
    //mScene.addItem(&menemy);
    mGameView.setScene(&mScene);
    mGameView.setParent(this);
    //计时器
    //敌人产生
    mEnemyProduceTimer=new QTimer(this);
    mEnemyProduceTimer->start(3000);
    connect(mEnemyProduceTimer,&QTimer::timeout,[&](){
        mEnemyList->produceEnemy();
    });
    //敌人移动
    mEnemyMoveTimer=new QTimer(this);
    mEnemyMoveTimer->start(500);
    connect(mEnemyMoveTimer,&QTimer::timeout,[&](){
        mEnemyList->EnemyListMove(QPointF(200,200));
    });
    //子弹移动
    mBulletMoveTimer=new QTimer(this);
    mBulletMoveTimer->start(10);
    connect(mBulletMoveTimer,&QTimer::timeout,[&](){
        mBulletList->BulletListMove();
    });
    //去除死亡敌人
    mEnemyRemoveTimer=new QTimer(this);
    mEnemyRemoveTimer->start(100);
    connect(mEnemyRemoveTimer,&QTimer::timeout,[&](){
        mEnemyList->RemoveDeadEnemy();
    });
    //去除飞出边界的子弹
    mRemoveRunBulletTimer=new QTimer(this);
    mRemoveRunBulletTimer->start(100);
    connect(mRemoveRunBulletTimer,&QTimer::timeout,[&](){
        mBulletList->RemoveRunBullet();
    });
    //去除击中敌人子弹
    mRemoveHitBulletTimer=new QTimer(this);
    mRemoveHitBulletTimer->start(100);
    connect(mRemoveHitBulletTimer,&QTimer::timeout,[&](){
        mBulletList->RemoveHitBullet(mEnemyList);
    });
//敌人生成敌人
    mEnemyProduceEnemyTimer=new QTimer(this);
    mEnemyProduceEnemyTimer->start(5000);
    connect(mEnemyProduceEnemyTimer,&QTimer::timeout,[&](){
        mEnemyList->EnemyProduceEnemy();
    });

    mGameView.show();


}

Widget::~Widget()
{
    delete ui;
}
void Widget::mousePressEvent(QMouseEvent *event){
    mBulletList->produceBullet(QPoint(50,50),event->pos());
}
