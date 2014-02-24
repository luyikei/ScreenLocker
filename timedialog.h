#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H

#include <QDialog>
#include <QDateTimeEdit>
class TimeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeDialog(QWidget *parent = 0);
    QDateTimeEdit *edit;
signals:

public slots:

};

#endif // TIMEDIALOG_H
