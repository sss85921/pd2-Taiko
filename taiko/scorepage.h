#ifndef SCOREPAGE_H
#define SCOREPAGE_H

#include <QDialog>

namespace Ui {
class ScorePage;
}
class QMediaPlayer;

class ScorePage : public QDialog
{
    Q_OBJECT

public:
    explicit ScorePage(QWidget *parent = 0);
    ~ScorePage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ScorePage *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // SCOREPAGE_H
