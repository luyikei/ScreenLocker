#ifndef SCREENLOCKER_H
#define SCREENLOCKER_H

#include <QWidget>

#include <QDateTime>
#include <QLabel>
namespace Ui {
class ScreenLocker;
}

class ScreenLocker : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenLocker(QWidget *parent = 0);
    ~ScreenLocker();

    void mousePressEvent(QMouseEvent *e);
    void timerEvent(QTimerEvent *e);
    void updateTimeUntil();


    QDateTime timeUntil;
private:
    QLabel *timeNowLabel;
    QLabel *timeUntilLabel;
};

#endif // SCREENLOCKER_H
