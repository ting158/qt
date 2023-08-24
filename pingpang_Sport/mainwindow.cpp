#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTimerEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_p = new QPainter;
    m_timer = new QTimer;

    this->resize(1500, 1000);

    //定时器
    connect(m_timer, &QTimer::timeout, this, [=](){
        m_ball.Move();
    });

    //设置对话框与球的数据
    connect(&m_set, &Set::sandDate, &m_ball, &Ball::getData);

    //设置参数后暂停运动
    connect(&m_set, &Set::stop, this, [=](){
        m_timer->stop();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    m_p->begin(this);

    m_ball.Draw(m_p);


    m_p->end();

    update();
}

void MainWindow::on_pushButton_start_clicked()
{
    m_timer->start(10);
}


void MainWindow::on_pushButton_stop_clicked()
{
    m_timer->stop();
}


void MainWindow::on_pushButton_set_clicked()
{
    m_set.showDateToLineEdit(m_ball.m_x0, m_ball.m_y0, m_ball.m_z0, m_ball.m_vx0, m_ball.m_vy0, m_ball.m_vz0);
    m_set.show();
}

