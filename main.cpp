#include "screenlocker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScreenLocker w;
    w.show();

    return a.exec();
}
