#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_a = 0;

    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnTimer()
{
    ui->lineEdit->setText(QString::number(m_a++));
}


void MainWindow::on_pushButton_clicked()
{
    m_timer->start(500);
}

