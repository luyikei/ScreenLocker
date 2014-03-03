#include "screenlocker.h"
#include "ui_screenlocker.h"
#include "timedialog.h"
#include <QVBoxLayout>
#include <QDialog>
#include <QDebug>
#include <QDir>
#include <QDebug>
#include <QFile>

ScreenLocker::ScreenLocker(QWidget *parent) :
    QWidget(parent)
{


    QPalette pal = palette();
    pal.setColor(backgroundRole(), Qt::black);
    setPalette(pal);

    layout = new QVBoxLayout(this);
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
        if(dialog.isToRemoveUSB->isChecked()){
            removeUsbList = scanUsbDevices();
            removeUsb(removeUsbList);
        }
        timeUntilLabel->setText(timeUntil.toString(QString::fromUtf8("yyyy M月 d日 h:mm")));
    }

}

void ScreenLocker::closeEvent(QCloseEvent *e)
{
    recongnizeUsb(removeUsbList);
}

void ScreenLocker::removeUsb(const QStringList &l)
{

    QFile unbind("/sys/bus/usb/drivers/usb/unbind");

    if (!unbind.open(QIODevice::WriteOnly)){
        return;
    }

    foreach (const QString &str, l) {


        QTextStream out(&unbind);

        out<<str;
    }

}

void ScreenLocker::recongnizeUsb(const QStringList &l)
{

    QFile bind("/sys/bus/usb/drivers/usb/bind");

    if (!bind.open(QIODevice::WriteOnly)){
        return;
    }

    foreach (const QString &str, l) {


        QTextStream out(&bind);

        out<<str;
    }

}

QStringList ScreenLocker::scanUsbDevices()
{

    QDir q_dir("/sys/bus/usb/devices/");

    if(q_dir.exists()){

         QStringList filelist = q_dir.entryList();
         QStringList usbList;

         foreach (const QString &str, filelist) {

             QFile currentFile(q_dir.absoluteFilePath(QString("%1%2").arg(str).arg("/product")));

             if (!currentFile.open(QIODevice::ReadOnly)){
                 continue;
             }

             QTextStream in(&currentFile);

             if (in.readAll().contains("USB"))
                 usbList << str;


         }

         qDebug() << usbList;

         return usbList;

     }
    return QStringList();



}
