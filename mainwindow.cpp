#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
//    ui(new Ui::MainWindow)
{
    swatchMaker = new SwatchMaker;
    swatchMaker->resize(500, 500);
    swatchMaker->setMouseTracking(true);
    setCentralWidget(swatchMaker);
//    MainWindow(this).resize(swatchMaker->size());

//    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
//    delete ui;
    delete swatchMaker;
}


