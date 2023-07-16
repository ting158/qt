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

    QTimer *m_timer;
    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));
    m_timer->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnTimer()
{
    ui->lineEdit->setText(QString::number(m_a++));

    qDebug() << m_a;
}


void MainWindow::on_pushButton_clicked()
{
    emit timeout();
}

