#include "startpage.h"
#include "ui_startpage.h"
#include <QTimer>
#include "ScorePage.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QGraphicsview>
#include <QDialog>
#include <QGraphicsItem>
#include <stdlib.h>
#include <time.h>
#include <QLabel>
#include <math.h>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QFileDialog>


extern int score;
extern int select;

StartPage::StartPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartPage)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);

    //設定初位置
    srand(time(NULL));
    for(i=0;i<5;i++){
        reddrum[i]=((rand()%8)+8)*250;
        bluedrum[i]=((rand()%8)+8)*225;
    }

    adjustment();

    //放圖

    ui->labelcircle->setPixmap(QPixmap(":/picture/circle.jpeg"));

    ui->reddrum_1->setPixmap(QPixmap(":/picture/red.jpeg"));
    ui->reddrum_2->setPixmap(QPixmap(":/picture/red.jpeg"));
    ui->reddrum_3->setPixmap(QPixmap(":/picture/red.jpeg"));
    ui->reddrum_4->setPixmap(QPixmap(":/picture/red.jpeg"));
    ui->reddrum_5->setPixmap(QPixmap(":/picture/red.jpeg"));

    ui->reddrum_1->setGeometry(reddrum[0],drum_y,400,400);
    ui->reddrum_2->setGeometry(reddrum[1],drum_y,400,400);
    ui->reddrum_3->setGeometry(reddrum[2],drum_y,400,400);
    ui->reddrum_4->setGeometry(reddrum[3],drum_y,400,400);
    ui->reddrum_5->setGeometry(reddrum[4],drum_y,400,400);

    ui->bluedrum_1->setPixmap(QPixmap(":/picture/blue.jpeg"));
    ui->bluedrum_2->setPixmap(QPixmap(":/picture/blue.jpeg"));
    ui->bluedrum_3->setPixmap(QPixmap(":/picture/blue.jpeg"));
    ui->bluedrum_4->setPixmap(QPixmap(":/picture/blue.jpeg"));
    ui->bluedrum_5->setPixmap(QPixmap(":/picture/blue.jpeg"));

    ui->bluedrum_1->setGeometry(bluedrum[0],drum_y,400,400);
    ui->bluedrum_2->setGeometry(bluedrum[1],drum_y,400,400);
    ui->bluedrum_3->setGeometry(bluedrum[2],drum_y,400,400);
    ui->bluedrum_4->setGeometry(bluedrum[3],drum_y,400,400);
    ui->bluedrum_5->setGeometry(bluedrum[4],drum_y,400,400);

    ui->labelperfect->setPixmap(QPixmap(":/picture/perfect.jpg"));
    ui->labelgood->setPixmap(QPixmap(":/picture/good.jpg"));
    ui->labelbad->setPixmap(QPixmap(":/picture/bad.jpg"));
    ui->labelperfect->hide();
    ui->labelgood->hide();
    ui->labelbad->hide();

    ui->labelbackbot->setPixmap(QPixmap(":/picture/back_r.jpg"));
    ui->labelbackbot_2->setPixmap(QPixmap(":/picture/back_b.jpg"));
    ui->labelbackbot->hide();
    ui->labelbackbot_2->hide();


    //倒數計時
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
    timer->start();


    timer_ball();
    adjustment();
    music();


}

void StartPage::adjustment(){
    //調整鼓的位置不要過近
    //紅
    for(i=1;i<5;i++){
        x1=reddrum[0];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            reddrum[0]+=200;
        }
    }
    for(i=2;i<5;i++){
        x1=reddrum[1];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            reddrum[1]+=200;
        }
    }
    for(i=3;i<5;i++){
        x1=reddrum[2];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            reddrum[2]+=200;
        }
    }
    for(i=4;i<5;i++){
        x1=reddrum[3];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            reddrum[3]+=200;
        }
    }

    //藍
    for(i=1;i<5;i++){
        x1=bluedrum[0];
        x2=bluedrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[0]+=200;
        }
    }
    for(i=2;i<5;i++){
        x1=bluedrum[1];
        x2=bluedrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[1]+=200;
        }
    }
    for(i=3;i<5;i++){
        x1=bluedrum[2];
        x2=bluedrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[2]+=200;
        }
    }
    for(i=4;i<5;i++){
        x1=bluedrum[3];
        x2=bluedrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[3]+=200;
        }
    }


    //紅藍
    for(i=0;i<5;i++){
        x1=bluedrum[0];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[0]+=1000;
        }
    }
    for(i=1;i<5;i++){
        x1=bluedrum[1];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[1]+=1000;
        }
    }
    for(i=0;i<5;i++){
        x1=bluedrum[2];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[2]+=1000;
        }
    }
    for(i=0;i<5;i++){
        x1=bluedrum[3];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            bluedrum[3]+=1000;
        }
    }
    for(i=0;i<5;i++){
        x1=bluedrum[4];
        x2=reddrum[i];
        d=sqrt(pow(x1-x2,2));
        if(d<=50){
            reddrum[4]+=1000;
        }
    }

}

void StartPage::timer_timeout()
{
    cnt--;
    ui->labelnum->setText(QString::number(cnt));
    if(cnt==0)
    {
        cnt = 100;
        this->close();
        mMediaPlayer->stop();
        ScorePage scorepage;
        scorepage.exec();

    }

}

void StartPage::timer_ball(){
    time_ball = new QTimer(this);
    time_ball->setInterval(10);
    connect(time_ball,SIGNAL(timeout()),this,SLOT(run()));
    time_ball->start();

}

void StartPage::run(){
    ui->reddrum_1->setGeometry(reddrum[0],drum_y,400,400);
    ui->reddrum_2->setGeometry(reddrum[1],drum_y,400,400);
    ui->reddrum_3->setGeometry(reddrum[2],drum_y,400,400);
    ui->reddrum_4->setGeometry(reddrum[3],drum_y,400,400);
    ui->reddrum_5->setGeometry(reddrum[4],drum_y,400,400);

    ui->bluedrum_1->setGeometry(bluedrum[0],drum_y,400,400);
    ui->bluedrum_2->setGeometry(bluedrum[1],drum_y,400,400);
    ui->bluedrum_3->setGeometry(bluedrum[2],drum_y,400,400);
    ui->bluedrum_4->setGeometry(bluedrum[3],drum_y,400,400);
    ui->bluedrum_5->setGeometry(bluedrum[4],drum_y,400,400);

    for(i=0;i<5;i++){
        reddrum[i]-=4;
        bluedrum[i]-=4;
        if(reddrum[i]<=0){
            reddrum[i]=((rand()%8)+8)*250;
        }
        if(bluedrum[i]<=0){
            bluedrum[i]=((rand()%8)+8)*225;
        }
    }
}

void StartPage::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D){
        ui->labelbackbot->show();
        //mMediaPlayer->setMedia(QUrl("qrc:/music/don.mp3"));
        //mMediaPlayer->play();
    }
    if(event->key()==Qt::Key_J){
       ui->labelbackbot_2->show();
       //mMediaPlayer->setMedia(QUrl("qrc:/music/ka.mp3"));
       //mMediaPlayer->play();
    }
    for(i=0;i<5;i++){
        if(event->key()==Qt::Key_D && reddrum[i]<=325 && reddrum[i]>=235){
            ui->labelperfect->show();
            score+=2;
            ui->labelscorenum->setText(QString::number(score));
            reddrum[i]=((rand()%8)+8)*250;
            adjustment();

        }
        if(event->key()==Qt::Key_D && reddrum[i]<=235 && reddrum[i]>=225){
            ui->labelgood->show();
            score+=1;
            ui->labelscorenum->setText(QString::number(score));
            reddrum[i]=((rand()%8)+8)*250;
            adjustment();
        }
        if(event->key()==Qt::Key_D && reddrum[i]<=225 && reddrum[i]>=205){
            ui->labelbad->show();
            reddrum[i]=((rand()%8)+8)*250;
            adjustment();
        }
        if(event->key()==Qt::Key_D && reddrum[i]<=335 && reddrum[i]>=325){
            ui->labelgood->show();
            score+=1;
            ui->labelscorenum->setText(QString::number(score));
            reddrum[i]=((rand()%8)+8)*250;
            adjustment();
        }
        if(event->key()==Qt::Key_D && reddrum[i]<=355 && reddrum[i]>=335){
            ui->labelbad->show();
            reddrum[i]=((rand()%8)+8)*250;
            adjustment();
        }


        if(event->key()==Qt::Key_J && bluedrum[i]<=325 && bluedrum[i]>=235){
            ui->labelperfect->show();
            score+=2;
            ui->labelscorenum->setText(QString::number(score));
            bluedrum[i]=((rand()%8)+8)*225;
            adjustment();
        }
        if(event->key()==Qt::Key_J && bluedrum[i]<=235 && bluedrum[i]>=225){
            ui->labelgood->show();
            score+=1;
            ui->labelscorenum->setText(QString::number(score));
            bluedrum[i]=((rand()%8)+8)*225;
            adjustment();
        }
        if(event->key()==Qt::Key_J && bluedrum[i]<=225 && bluedrum[i]>=205){
            ui->labelbad->show();
            bluedrum[i]=((rand()%8)+8)*225;
            adjustment();
        }
        if(event->key()==Qt::Key_J && bluedrum[i]<=335 && bluedrum[i]>=325){
            ui->labelgood->show();
            score+=1;
            ui->labelscorenum->setText(QString::number(score));
            bluedrum[i]=((rand()%8)+8)*225;
            adjustment();
        }
        if(event->key()==Qt::Key_J && bluedrum[i]<=355 && bluedrum[i]>=335){
            ui->labelbad->show();
            bluedrum[i]=((rand()%8)+8)*225;
            adjustment();
        }
    }
}

void StartPage::keyReleaseEvent(QKeyEvent *event1)
{

        if(event1->key()==Qt::Key_D){
            ui->labelgood->hide();
            ui->labelperfect->hide();
            ui->labelbad->hide();
            ui->labelbackbot->hide();

        }

        if(event1->key()==Qt::Key_J){
            ui->labelgood->hide();
            ui->labelperfect->hide();
            ui->labelbad->hide();
            ui->labelbackbot_2->hide();
        }

}

void StartPage::music(){

    if(select==1){
        mMediaPlayer->setMedia(QUrl("qrc:/music/TAEYANG.mp3"));
        mMediaPlayer->play();

    }
    if(select==2){
        mMediaPlayer->setMedia(QUrl("qrc:/music/Everytime.mp3"));
        mMediaPlayer->play();

    }
    if(select==3){
        mMediaPlayer->setMedia(QUrl("qrc:/music/THE MAX.mp3"));
        mMediaPlayer->play();

    }
    if(select==4){
        mMediaPlayer->setMedia(QUrl("qrc:/music/Talk Love.mp3"));
        mMediaPlayer->play();

    }

}

StartPage::~StartPage()
{
    delete ui;
}
