#include "menu.h"
#include "ui_menu.h"
#include "StartPage.h"
#include "musicmemo.h"
#include <QDialog>


menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    ui->label->setPixmap(QPixmap(":/picture/menu.jpg"));
    ui->label_2->setPixmap(QPixmap(":/picture/red.jpeg"));
    ui->label_3->setPixmap(QPixmap(":/picture/blue.jpeg"));

}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_2_clicked()
{
    close();
}

void menu::on_pushButton_clicked()
{
    this->hide();
    musicmemo music;
    music.exec();
}

