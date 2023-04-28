#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(w.centralWidget()->size());    //working on the widget
    w.show();

    return a.exec();
}
