#include "scorepage.h"
#include "ui_scorepage.h"
#include "startpage.h"
#include <QDialog>
#include <QFont>
#include <QGraphicsTextItem>
#include "musicmemo.h"
#include <QMediaPlayer>


extern int score;
extern int select;

ScorePage::ScorePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScorePage)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);

    ui->scorenum->setText(QString::number(score));

    ui->label_4->setPixmap(QPixmap(":/picture/scorepagebg.jpg"));
    ui->superdrum->setPixmap(QPixmap(":/picture/reddrum12.jpg"));
    ui->superdrum_2->setPixmap(QPixmap(":/picture/reddrum12.jpg"));
    ui->superdrum_3->setPixmap(QPixmap(":/picture/reddrum12.jpg"));
    ui->superdrum_4->setPixmap(QPixmap(":/picture/reddrum12.jpg"));
    ui->superdrum_5->setPixmap(QPixmap(":/picture/reddrum12.jpg"));
    ui->superdrum_6->setPixmap(QPixmap(":/picture/reddrum12.jpg"));
    ui->gooddrum_7->setPixmap(QPixmap(":/picture/reddrum2.jpg"));
    ui->gooddrum_8->setPixmap(QPixmap(":/picture/reddrum2.jpg"));
    ui->gooddrum_9->setPixmap(QPixmap(":/picture/reddrum2.jpg"));
    ui->gooddrum_10->setPixmap(QPixmap(":/picture/reddrum2.jpg"));
    ui->gooddrum_11->setPixmap(QPixmap(":/picture/reddrum2.jpg"));
    ui->gooddrum_12->setPixmap(QPixmap(":/picture/reddrum2.jpg"));
    ui->baddrum_13->setPixmap(QPixmap(":/picture/reddrum8.jpg"));
    ui->baddrum_14->setPixmap(QPixmap(":/picture/reddrum8.jpg"));
    ui->baddrum_15->setPixmap(QPixmap(":/picture/reddrum8.jpg"));
    ui->baddrum_16->setPixmap(QPixmap(":/picture/reddrum8.jpg"));
    ui->baddrum_17->setPixmap(QPixmap(":/picture/reddrum8.jpg"));
    ui->baddrum_18->setPixmap(QPixmap(":/picture/reddrum8.jpg"));

    if(score>200){
        ui->superdrum->show();
        ui->superdrum_2->show();
        ui->superdrum_3->show();
        ui->superdrum_4->show();
        ui->superdrum_5->show();
        ui->superdrum_6->show();
        ui->gooddrum_7->hide();
        ui->gooddrum_8->hide();
        ui->gooddrum_9->hide();
        ui->gooddrum_10->hide();
        ui->gooddrum_11->hide();
        ui->gooddrum_12->hide();
        ui->baddrum_13->hide();
        ui->baddrum_14->hide();
        ui->baddrum_15->hide();
        ui->baddrum_16->hide();
        ui->baddrum_17->hide();
        ui->baddrum_18->hide();


        mMediaPlayer->setMedia(QUrl("qrc:/music/supersound.mp3"));
        mMediaPlayer->play();
    }
    if(score>=100 && score<200){
        ui->superdrum->hide();
        ui->superdrum_2->hide();
        ui->superdrum_3->hide();
        ui->superdrum_4->hide();
        ui->superdrum_5->hide();
        ui->superdrum_6->hide();
        ui->gooddrum_7->show();
        ui->gooddrum_8->show();
        ui->gooddrum_9->show();
        ui->gooddrum_10->show();
        ui->gooddrum_11->show();
        ui->gooddrum_12->show();
        ui->baddrum_13->hide();
        ui->baddrum_14->hide();
        ui->baddrum_15->hide();
        ui->baddrum_16->hide();
        ui->baddrum_17->hide();
        ui->baddrum_18->hide();

        mMediaPlayer->setMedia(QUrl("qrc:/music/goodsound.mp3"));
        mMediaPlayer->play();
    }
    if(score<100){
        ui->superdrum->hide();
        ui->superdrum_2->hide();
        ui->superdrum_3->hide();
        ui->superdrum_4->hide();
        ui->superdrum_5->hide();
        ui->superdrum_6->hide();
        ui->gooddrum_7->hide();
        ui->gooddrum_8->hide();
        ui->gooddrum_9->hide();
        ui->gooddrum_10->hide();
        ui->gooddrum_11->hide();
        ui->gooddrum_12->hide();
        ui->baddrum_13->show();
        ui->baddrum_14->show();
        ui->baddrum_15->show();
        ui->baddrum_16->show();
        ui->baddrum_17->show();
        ui->baddrum_18->show();

        mMediaPlayer->setMedia(QUrl("qrc:/music/badsoud.mp3"));
        mMediaPlayer->play();
    }
}

ScorePage::~ScorePage()
{
    delete ui;
}

void ScorePage::on_pushButton_2_clicked()
{
    close();
}

void ScorePage::on_pushButton_clicked()
{
    score=0;
    select=0;
    this->close();
    musicmemo Music;
    Music.exec();

}
