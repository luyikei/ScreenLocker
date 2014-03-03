#ifndef SCREENLOCKER_H
#define SCREENLOCKER_H

#include <QWidget>

#include <QDateTime>
#include <QLabel>
#include <QVBoxLayout>
#include <QStringList>
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
    void closeEvent(QCloseEvent *e);

    void removeUsb(const QStringList& l);
    void recongnizeUsb(const QStringList& l);

    QStringList scanUsbDevices();


    QDateTime timeUntil;
private:
    QLabel *timeNowLabel;
    QLabel *timeUntilLabel;

    QVBoxLayout *layout;

    QStringList removeUsbList;
};

#endif // SCREENLOCKER_H
