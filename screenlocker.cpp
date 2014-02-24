#include "screenlocker.h"
#include "ui_screenlocker.h"
#include "timedialog.h"
#include <QVBoxLayout>
#include <QDialog>
#include <QDebug>
ScreenLocker::ScreenLocker(QWidget *parent) :
    QWidget(parent)
{


    QPalette pal = palette();
    pal.setColor(backgroundRole(), Qt::black);
    setPalette(pal);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);


    timeNowLabel = new QLabel(this);
    timeNowLabel->setStyleSheet("font-size: 70px;"
                             "color:#FFFFFF;");

    timeUntilLabel = new QLabel(this);
    timeUntilLabel->setStyleSheet("font-size: 50px;"
                             "color:#AAAAAA;");

    timeUntil=QDateTime::currentDateTime();
    updateTimeUntil();
    startTimer(1000);

    layout->addWidget(timeNowLabel);
    layout->addWidget(timeUntilLabel);

    showFullScreen();
}

ScreenLocker::~ScreenLocker()
{
}

void ScreenLocker::mousePressEvent(QMouseEvent *e)
{
    updateTimeUntil();
}

void ScreenLocker::timerEvent(QTimerEvent *e)
{
    timeNowLabel->setText(QDateTime::currentDateTime().toString(QString::fromUtf8("yyyy M月 d日 h:mm ss")));
    if(QDateTime::currentDateTime().secsTo(timeUntil) <= 1){

        close();

    }
}

void ScreenLocker::updateTimeUntil()
{
    TimeDialog dialog(timeUntil,this);

    if(dialog.exec() == QDialog::Accepted){
        timeUntil = dialog.edit->dateTime();

        timeUntilLabel->setText(timeUntil.toString(QString::fromUtf8("yyyy M月 d日 h:mm")));
    }

}
