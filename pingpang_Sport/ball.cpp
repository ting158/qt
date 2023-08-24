#include "ball.h"

Ball::Ball(QObject *parent)
    : QObject{parent}
{
    m_k = 100;   //100像素 = 1米

    m_YD_CST.setX(200);
    m_YD_CST.setY(100);

    m_YD_FST.setX(1100);
    m_YD_FST.setY(100);

    m_L = 2.7;  // m
    m_W = 1.5;  // m
    m_H = 0.15; // m

    m_r = 0.05;  // m

    m_vx0 = 5;      // m/s
    m_vy0 = 1;      // m/s
    m_vz0 = -1.5;   // m/s

    m_x0 = -0.2;
    m_y0 = 0;
    m_z0 = 0.3;

    initState();
}

void Ball::initState()
{
    m_x = m_x0;
    m_y = m_y0;
    m_z = m_z0;

    m_vx = m_vx0;
    m_vy = m_vy0;
    m_vz = m_vz0;

    m_xGJ.append(m_x);
    m_yGJ.append(m_y);
    m_zGJ.append(m_z);
    m_vxGJ.append(m_vx);
    m_vyGJ.append(m_vy);
    m_vzGJ.append(m_vz);
}

void Ball::Move()
{
    if (isOverMove())
        return;

    float t = 0.01;

    if (m_z - m_r <= 0)  //碰到桌面反弹
        m_vz = fabs(m_vz);
    m_vz += -9.8 * t;

    if (m_z - m_r <= m_H && m_z + m_r <= 0 && m_x - m_r <= m_L / 2 && m_x + m_r >= m_L / 2) //碰到球网反弹
        m_vx = -m_vx;

    m_x += m_vx * t;
    m_y += m_vy * t;
    m_z += m_vz * t;


    //保存数据
    m_xGJ.append(m_x);
    m_yGJ.append(m_y);
    m_zGJ.append(m_z);
    m_vxGJ.append(m_vx);
    m_vyGJ.append(m_vy);
    m_vzGJ.append(m_vz);
}

int Ball::isOverMove()
{
    if (m_x > m_L || m_x < -m_L / 4)
        return 1;
    return 0;
}

void Ball::getData(float x, float y, float z, float vx, float vy, float vz)
{
    m_x0 = x;
    m_y0 = y;
    m_z0 = z;
    m_vx0 = vx;
    m_vy0 = vy;
    m_vz0 = vz;

    m_xGJ.clear();
    m_yGJ.clear();
    m_zGJ.clear();
    m_vxGJ.clear();
    m_vyGJ.clear();
    m_vzGJ.clear();

    initState();
}

void Ball::Draw(QPainter *p)
{
    m_painter = p;

    DrawCST();
    DrawFST();
    DrawXCurve();
    DrawVCurve();
}

void Ball::DrawCST()
{
    int x1, y1, x2, y2, r;

    //桌子
    x1 = m_YD_CST.x();
    y1 = m_YD_CST.y();
    x2 = x1 +  m_L * m_k;
    y2 = y1;
    m_painter->drawLine(x1, y1, x2, y2);

    x1 = m_YD_CST.x() + m_L / 2 * m_k;
    y1 = m_YD_CST.y();
    x2 = x1;
    y2 = y1 - m_H * m_k;
    m_painter->drawLine(x1, y1, x2, y2);

    //球
    x1 = m_YD_CST.x() + m_x * m_k;
    y1 = m_YD_CST.y() - m_z * m_k;
    r = m_r * m_k;
    m_painter->drawEllipse(QPoint(x1, y1), r, r);
}

void Ball::DrawFST()
{
    int x1, y1, x2, y2, w, h, r;

    //桌子
    x1 = m_YD_FST.x() - m_W / 2 * m_k;
    y1 = m_YD_FST.y();
    w = m_W * m_k;
    h = m_L * m_k;
    m_painter->drawRect(x1, y1, w, h);
    x1 = m_YD_FST.x() - m_W / 2 * m_k;
    y1 += m_L * m_k / 2;
    x2 = x1 + m_W * m_k;
    y2 = y1;
    m_painter->drawLine(x1, y1, x2, y2);

    //球
    x1 = m_YD_FST.x() - m_y * m_k;
    y1 = m_YD_FST.y() + m_x * m_k;
    r = m_r * m_k;
    m_painter->drawEllipse(QPoint(x1, y1), r, r);
}

void Ball::DrawXCurve()
{
    int i;
    float x1, y1, x2, y2;
    float initX, initY;
    QString str;

    initX = m_YD_CST.x();
    initY = m_YD_CST.y() + 200;
    x1 = initX;
    y1 = initY;
    x2 = x1 + 500;
    y2 = y1;
    m_painter->drawLine(x1, y1, x2, y2);
    x1 = initX;
    y1 = initY - 130;
    x2 = x1;
    y2 = y1 + 260;
    m_painter->drawLine(x1, y1, x2, y2);
    x1 = initX - 15;
    y1 = initY + 5;
    m_painter->drawText(x1, y1, "0");

    x1 = initX + 150;
    y1 = initY + 130;
    m_painter->drawText(x1, y1, "运动轨迹");

    for (i = 1; i <= 3; i++)
    {
        x1 = initX;
        y1 = initY - i * m_k / 3;
        x2 = x1 + 10;
        y2 = y1;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = initX - 15;
        y1 += 5;
        str = QString::number(i);
        m_painter->drawText(x1, y1, str);
    }
    for (i = 1; i <= 3; i++)
    {
        x1 = initX;
        y1 = initY + i * m_k / 3;
        x2 = x1 + 10;
        y2 = y1;
        m_painter->drawLine(x1, y1, x2, y2);
        x1 = initX - 20;
        y1 += 5;
        str = QString::number(-i);
        m_painter->drawText(x1, y1, str);
    }
    for (i = 1; i <= 8; i++)
    {
        x1 = initX + i *  60;
        y1 = initY;
        x2 = x1;
        y2 = y1 - 10;
        m_painter->drawLine(x1, y1, x2, y2);
        str = QString::number(i);
        x2 -= 3;
        y2 += 25;
        m_painter->drawText(x2, y2, str);
    }

    QPen pen1;
    pen1.setColor(Qt::red);
    m_painter->setPen(pen1);

    x1 = initX;
    y1 = initY;
    int n = m_xGJ.count();
    for (i = 0; i < n; i++)
    {
        x2 = initX + i * 3;
        y2 = initY - m_xGJ[i] * m_k / 3;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = x2;
        y1 = y2;
    }
    x1 = initX - 150;
    y1 = initY - 130;
    x2 = x1 + 20;
    y2 = y1;
    m_painter->drawLine(x1, y1, x2, y2);
    x2 += 15;
    y2 += 5;
    m_painter->drawText(x2, y2, "x方向");

    QPen pen2;
    pen2.setColor(Qt::green);
    m_painter->setPen(pen2);

    x1 = initX;
    y1 = initY;
    n = m_yGJ.count();
    for (i = 0; i < n; i++)
    {
        x2 = initX + i * 3;
        y2 = initY - m_yGJ[i] * m_k / 3;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = x2;
        y1 = y2;
    }
    x1 = initX - 150;
    y1 = initY - 90;
    x2 = x1 + 20;
    y2 = y1;
    m_painter->drawLine(x1, y1, x2, y2);
    x2 += 15;
    y2 += 5;
    m_painter->drawText(x2, y2, "y方向");

    QPen pen3;
    pen3.setColor(Qt::black);
    m_painter->setPen(pen3);
    x1 = initX;
    y1 = initY;
    n = m_zGJ.count();
    for (i = 0; i < n; i++)
    {
        x2 = initX + i * 3;
        y2 = initY - m_zGJ[i] * m_k / 3;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = x2;
        y1 = y2;
    }
    x1 = initX - 150;
    y1 = initY - 50;
    x2 = x1 + 20;
    y2 = y1;
    m_painter->drawLine(x1, y1, x2, y2);
    x2 += 15;
    y2 += 5;
    m_painter->drawText(x2, y2, "z方向");
}

void Ball::DrawVCurve()
{
    int i;
    float x1, y1, x2, y2;
    float initX, initY;
    QString str;

    initX = m_YD_CST.x();
    initY = m_YD_CST.y() + 550;
    x1 = initX;
    y1 = initY;
    x2 = x1 + 500;
    y2 = y1;
    m_painter->drawLine(x1, y1, x2, y2);
    x1 = initX;
    y1 = initY - 130;
    x2 = x1;
    y2 = y1 + 260;
    m_painter->drawLine(x1, y1, x2, y2);
    x1 = initX - 15;
    y1 = initY + 5;
    m_painter->drawText(x1, y1, "0");

    x1 = initX + 150;
    y1 = initY + 130;
    m_painter->drawText(x1, y1, "速度轨迹");

    for (i = 1; i <= 2; i++)
    {
        x1 = initX;
        y1 = initY - i * 5 * m_k / 8;
        x2 = x1 + 10;
        y2 = y1;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = initX - 25;
        y1 += 5;
        str = QString::number(i * 5);
        m_painter->drawText(x1, y1, str);
    }
    for (i = 1; i <= 2; i++)
    {
        x1 = initX;
        y1 = initY + i * 5 * m_k / 8;
        x2 = x1 + 10;
        y2 = y1;
        m_painter->drawLine(x1, y1, x2, y2);
        x1 = initX - 30;
        y1 += 5;
        str = QString::number(-i * 5);
        m_painter->drawText(x1, y1, str);
    }
    for (i = 1; i <= 8; i++)
    {
        x1 = initX + i *  60;
        y1 = initY;
        x2 = x1;
        y2 = y1 - 10;
        m_painter->drawLine(x1, y1, x2, y2);
        str = QString::number(i);
        x2 -= 3;
        y2 += 25;
        m_painter->drawText(x2, y2, str);
    }

    QPen pen1;
    pen1.setColor(Qt::red);
    m_painter->setPen(pen1);

    x1 = initX;
    y1 = initY;
    int n = m_vxGJ.count();
    for (i = 0; i < n; i++)
    {
        x2 = initX + i * 3;
        y2 = initY - m_vxGJ[i] * m_k / 8;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = x2;
        y1 = y2;
    }

    QPen pen2;
    pen2.setColor(Qt::green);
    m_painter->setPen(pen2);

    x1 = initX;
    y1 = initY;
    n = m_vyGJ.count();
    for (i = 0; i < n; i++)
    {
        x2 = initX + i * 3;
        y2 = initY - m_vyGJ[i] * m_k / 8;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = x2;
        y1 = y2;
    }

    QPen pen3;
    pen3.setColor(Qt::black);
    m_painter->setPen(pen3);
    x1 = initX;
    y1 = initY;
    n = m_vzGJ.count();
    for (i = 0; i < n; i++)
    {
        x2 = initX + i * 3;
        y2 = initY - m_vzGJ[i] * m_k / 8;
        m_painter->drawLine(x1, y1, x2, y2);

        x1 = x2;
        y1 = y2;
    }
}
