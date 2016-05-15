#include "menu.h"
#include <QApplication>
#include "startpage.h"
#include "ui_startpage.h"
#include <QTimer>
#include "ScorePage.h"
#include "musicmemo.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QGraphicsview>

int score=0;
int select=0;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    menu w;
    w.show();

    return a.exec();
}
