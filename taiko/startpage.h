#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QDialog>
#include <QGraphicsRectItem>
#include <QObject>
#include "startpage.h"

namespace Ui {
class StartPage;
}
class QMediaPlayer;

class StartPage : public QDialog, public QGraphicsRectItem
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = 0);

    QTimer *timer;
    QTimer *time_ball;
    int cnt = 100; //計時器秒數
    int reddrum[5]={0};
    int bluedrum[5]={0};
    int drum_y=200;
    int i,x1,x2;
    float d;


    ~StartPage();

private slots:
    void timer_timeout();
    void adjustment();
    void timer_ball();
    void run();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event1);
    void music();


private:
    Ui::StartPage *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // STARTPAGE_H
