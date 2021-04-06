#include "mainwindow.h"

#include <QApplication>
#include "main.h"

allInfo myAllInfo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
