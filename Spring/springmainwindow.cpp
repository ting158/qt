#include "springmainwindow.h"
#include "ui_springmainwindow.h"
#include <QPoint>
#include <QTimer>
#include <QDebug>


SpringMainWindow::SpringMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpringMainWindow)
{
    ui->setupUi(this);

    m_k = 200;

    m_Point.setX(200);
    m_Point.setY(100);
    m_LUp = 0.25;
    m_LDown = 0.14;
    m_L0 = 0.1;
    m_kSpring = 10;
    m_damping = 0.9;
    m_w = 0.25;
    m_m = 0.8;
    m_r = 0.05;
    m_v = 1;
    m_y = 0;
    m_L = 0.5;
    m_nvGJ = 0;
    m_naGJ = 0;
    m_nfGJ = 0;
    m_nyGJ = 0;

    m_timer = new QTimer(this);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));

}

SpringMainWindow::~SpringMainWindow()
{
    delete ui;
}

void SpringMainWindow::paintEvent(QPaintEvent *event)
{
    m_painter.begin(this);

    DrawSpring();
    DrawQuXian(500, 125, m_yGJ, m_nyGJ, "位移变化曲线", 0.15, 500);
    DrawQuXian(900, 125, m_vGJ, m_nvGJ, "速度变化曲线", 1.5, 50);
    DrawQuXian(500, 425, m_aGJ, m_naGJ, "加速度变化曲线", 5, 15);
    DrawQuXian(900, 425, m_fGJ, m_nfGJ, "受力变化曲线", 4, 18.75);

    m_painter.end();

    update();
}

void SpringMainWindow::OnTimer()
{
    Move();
}

void SpringMainWindow::initSport()
{
    m_y = 0;

    m_L = 0.5;
    m_nvGJ = 0;
    m_naGJ = 0;
    m_nfGJ = 0;
    m_nyGJ = 0;
}

void SpringMainWindow::Move()
{
    m_f = m_m * 9.8 - m_kSpring * (m_L - m_L0);
    m_a = m_f / m_m;
    m_y = m_v * 0.1 + 0.5 * m_a * 0.1 * 0.1;
    m_L += m_y;
    m_v += m_a * 0.1;
    m_v *= m_damping;

    //保存数据
    m_vGJ[m_nvGJ] = m_v;
    m_nvGJ++;
    m_aGJ[m_naGJ] = m_a;
    m_naGJ++;
    m_fGJ[m_nfGJ] = m_f;
    m_nfGJ++;
    m_yGJ[m_nyGJ] = m_y;
    m_nyGJ++;
}

void SpringMainWindow::DrawQuXian(int initX, int initY, float gj[], int ngj, QString str, float max, float p)
{
    int i, k = 0;

    m_painter.drawLine(QPoint(initX, initY), QPoint(initX + 300, initY));
    m_painter.drawLine(QPoint(initX, initY - 75), QPoint(initX, initY + 75));
    m_painter.drawText(initX + 100, initY + 75 + 10, str);
    m_painter.drawText(initX - 15, initY + 8, "0");

    for (i = 0; i < 3; i++)
    {
        k += 20;
        m_painter.drawLine(QPoint(initX, initY + k), QPoint(initX + 5, initY + k));
    }
    k = 0;
    for (i = 0; i < 3; i++)
    {
        k += 20;
        m_painter.drawLine(QPoint(initX, initY - k), QPoint(initX + 5, initY - k));
    }
    k = 0;
    for (i = 0; i < 10; i++)
    {
        k += 20;
        m_painter.drawLine(QPoint(initX + k, initY), QPoint(initX + k, initY - 5));
    }
    k = 0;
    for (i = 1; i < 4; i++)
    {
        k += 20;
        QString str = QString::number(-max / 3 * i, 'f', 3);
        m_painter.drawText(initX - 50, initY  + k + 10, str);
    }
    k = 0;
    for (i = 1; i < 4; i++)
    {
        k += 20;
        QString str = QString::number(max / 3 * i, 'f', 3);
        m_painter.drawText(initX - 45, initY - k + 10, str);
    }
    k = 0;
    for (i = 1; i < 4; i++)
    {
        k += 50;
        QString str = QString::number(i * 10);
        m_painter.drawText(initX + k, initY + 15, str);
    }

    //曲线
    int x = initX;
    int y = initY + gj[0];
    int x0 = x;
    int y0 = y;

    for (i = 1; i < ngj; i++)
    {
        x += 2;
        y = initY - gj[i] * p;
        m_painter.drawLine(x0, y0, x, y);
        x0 = x;
        y0 = y;
    }
}

void SpringMainWindow::DrawSpring()
{
    float x1, y1, x2, y2, w, h, r;

    x1 = m_Point.x() - 50;
    y1 = m_Point.y();
    x2 = m_Point.x() + 50;
    y2 = m_Point.y();
    m_painter.drawLine(x1, y1, x2, y2);
    x1 = m_Point.x();
    y1 += m_LUp * m_k;
    m_painter.drawLine(QPoint(m_Point), QPoint(x1, y1));

    w = m_w * m_k;
    h = m_L * m_k;
    x1 -= w / 2;
    m_painter.drawRect(x1, y1, w, h);

    x1 = m_Point.x();
    y1 += m_L * m_k;
    x2 = x1;
    y2 = y1 + m_LDown * m_k;
    m_painter.drawLine(x1, y1, x2, y2);
    y1 = y2 + m_r * m_k;
    r = m_r * m_k;
    m_painter.drawEllipse(QPoint(x1, y1), r, r);
}


void SpringMainWindow::on_pushButton_start_clicked()
{
    m_timer->start(100);
}

