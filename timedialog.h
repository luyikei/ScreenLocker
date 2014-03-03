#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H

#include <QDialog>
#include <QDateTimeEdit>
#include <QHBoxLayout>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QCheckBox>

class TimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeDialog(QDateTime timeUntil,QWidget *parent = 0);
    QDateTimeEdit *edit;
    QHBoxLayout *layout;
    QDialogButtonBox *buttonBox;
    QCheckBox *isToRemoveUSB;
signals:

public slots:

};

#endif // TIMEDIALOG_H
