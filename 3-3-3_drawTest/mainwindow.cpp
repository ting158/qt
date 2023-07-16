#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
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
    QPen * pen = new QPen();

    pen->setColor(QColor(255, 0, 0));

    p->setFont(QFont("Times New Roman", 30));

    p->setPen(*pen);

    p->drawText(100, 200, QString("hello world"));

    p->end();
}

