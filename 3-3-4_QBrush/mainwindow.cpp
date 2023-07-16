#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QBrush>

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
    QPainter * painter = new QPainter(this);
    QBrush brush;

    brush.setColor(QColor(0, 0, 255));
    brush.setStyle(Qt::Dense6Pattern);
    painter->setBrush(brush);

    QPoint reck[2];
    reck[0].setX(100);
    reck[0].setY(100);
    reck[1].setX(300);
    reck[1].setY(200);
    painter->drawRect(QRect(reck[0], reck[1]));

    painter->end();

}

