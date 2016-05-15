#ifndef MUSICMEMO_H
#define MUSICMEMO_H

#include <QDialog>
#include <QObject>
#include "musicmemo.h"

namespace Ui {
class musicmemo;
}

class musicmemo : public QDialog
{
    Q_OBJECT

public:
    explicit musicmemo(QWidget *parent = 0);
    ~musicmemo();




private slots:

    void on_pushButtonmusic_clicked();

    void on_pushButtonmusic_2_clicked();

    void on_pushButtonmusic_3_clicked();

    void on_pushButtonmusic_4_clicked();

private:
    Ui::musicmemo *ui;
};

#endif // MUSICMEMO_H
