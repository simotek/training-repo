#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    int oneHundred = 100;

    QString *myVersion = w.getVersion();
    qDebug("My Version1: 0x%X %s %d", myVersion, myVersion->toUtf8().data(), oneHundred);

    myVersion->append(QString::number(oneHundred));
    qDebug("My Version2: 0x%X %s",myVersion, myVersion->toUtf8().data());

    qDebug("Version: 0x%X %s",w.getVersion(), w.getVersion()->toUtf8().data());
    w.show();
    return a.exec();
}
