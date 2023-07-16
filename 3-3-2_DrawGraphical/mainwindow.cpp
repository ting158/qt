#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //画圆
    painter.drawEllipse(QPoint(100, 100), 50, 50);

    //画椭圆
    painter.drawEllipse(QPoint(300, 100), 50, 25);

    //画矩形
    painter.drawRect(150, 200, 100, 300);

    painter.end();
}

