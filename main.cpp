#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <foundfilesmodel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile styleFile(":/res/Genetive.qss");
    styleFile.open(QIODevice::ReadOnly);
    QString style( styleFile.readAll() );
    a.setStyleSheet( style );
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
