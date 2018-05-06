#include "mainwindow.h"
#include <QApplication>

#include "fdengine.h"
#include "frengine.h"
#include "ftengine.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
