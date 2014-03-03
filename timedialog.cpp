#include "timedialog.h"

TimeDialog::TimeDialog(QDateTime timeUntil ,QWidget *parent) :
    QDialog(parent)
{
    layout = new QHBoxLayout(this);
    edit = new QDateTimeEdit(this);
    buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(QDialogButtonBox::Ok);
    buttonBox->addButton(QDialogButtonBox::Cancel);
    isToRemoveUSB = new QCheckBox("Remove USB (WARNING : Experimental! Only Linux)");
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));

    edit->setDateTime(timeUntil);

    layout->addWidget(edit);
    layout->addWidget(buttonBox);
    layout->addWidget(isToRemoveUSB);

}
