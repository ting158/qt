#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>

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
    QPainter * p = new QPainter(this);
    QPen pen;

    //实线
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    p->setPen(pen);
    p->drawLine(0, 50, 200, 50);

    //虚线
    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::red);
    p->setPen(pen);
    p->drawLine(0, 100, 200, 100);

    //点线
    pen.setStyle(Qt::DotLine);
    pen.setColor(Qt::blue);
    p->setPen(pen);
    p->drawLine(0, 150, 200, 150);

    p->end();

}
