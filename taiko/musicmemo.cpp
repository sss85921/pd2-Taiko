#include "musicmemo.h"
#include "ui_musicmemo.h"
#include <QDialog>
#include "menu.h"
#include "startpage.h"


extern int select;

musicmemo::musicmemo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::musicmemo)
{
    ui->setupUi(this);

    ui->label->setPixmap(QPixmap(":/picture/songselectbg.jpg"));
}

musicmemo::~musicmemo()
{
    delete ui;
}

void musicmemo::on_pushButtonmusic_clicked()
{
    select=1;
    this->hide();
    StartPage startpage;
    startpage.exec();

}
void musicmemo::on_pushButtonmusic_2_clicked()
{
    select=2;
    this->hide();
    StartPage startpage;
    startpage.exec();

}
void musicmemo::on_pushButtonmusic_3_clicked()
{
    select=3;
    this->hide();
    StartPage startpage;
    startpage.exec();

}
void musicmemo::on_pushButtonmusic_4_clicked()
{
    select=4;
    this->hide();
    StartPage startpage;
    startpage.exec();

}

