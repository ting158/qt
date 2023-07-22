#include "gamewidget.h"
#include "ui_gamewidget.h"

#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    m_painter = new QPainter;

    m_timer1Id = startTimer(1000);
    m_timer2Id = startTimer(50);
    m_timer1Satrt = false;
    m_timer2Satrt = false;
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);

    m_painter->setRenderHint(QPainter::Antialiasing);  //抗锯齿

    m_tank.Draw(m_painter);

    m_painter->end();

    update();
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    m_tank.MoveTank(event->key());
}

void GameWidget::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timer1Id && m_timer1Satrt)
    {
        m_tank.CreateBlock();
    }
    if (event->timerId() == m_timer2Id && m_timer2Satrt)
    {
        m_tank.MoveBlock();
        m_tank.MoveBullet();

        if (m_tank.BlockHitTank() == true)
        {
            QMessageBox::information(this, "Game Over", "游戏结束");
            m_timer1Satrt = false;
            m_timer2Satrt = false;
        }
    }
}

void GameWidget::on_pushButton_Start_clicked()
{
    m_timer1Satrt = true;
    m_timer2Satrt = true;
}


void GameWidget::on_pushButton_Stop_clicked()
{
    m_timer1Satrt = false;
    m_timer2Satrt = false;
}


void GameWidget::on_pushButton_Restart_clicked()
{
    m_tank.InitGame();
    m_timer1Satrt = false;
    m_timer2Satrt = false;
}

