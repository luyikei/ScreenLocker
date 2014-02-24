#include "timedialog.h"
#include <QHBoxLayout>
#include <QDateTime>
#include <QDialogButtonBox>

TimeDialog::TimeDialog(QDateTime timeUntil ,QWidget *parent) :
    QDialog(parent)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    edit = new QDateTimeEdit(this);
    QDialogButtonBox *buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(QDialogButtonBox::Ok);
    buttonBox->addButton(QDialogButtonBox::Cancel);

    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));

    edit->setDateTime(timeUntil);

    layout->addWidget(edit);
    layout->addWidget(buttonBox);
}
