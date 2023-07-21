#include "wrj.h"

#define TextOut drawText
#define Ellipse drawEllipse
#define Rectangle drawRect
#define LineTo drawLine
#define PI 3.1415926

WRJ::WRJ()
{
    m_x = 0;
    m_y = 0;
    m_r = m_w / 2;
    m_JDlxj = m_w;
    m_nd = 0;
}

void WRJ::Draw(QPainter *p)
{
    int x, y;
    QString str;

    pDC = p;

    DrawWuRenJi();

    //无人机浓度
    x = 1750;
    y = 200;
    str = QString("无人机附近浓度：%1").arg(m_nd);
    pDC->TextOut(x, y, str);
}

void WRJ::DrawWuRenJi()
{
    int x, y, r, w, x1, y1, x2, y2;

    x = m_YD.x + m_x * m_kx;
    y = m_YD.y + m_y * m_ky;
    r = m_r * m_kx;
    pDC->Ellipse(QPoint(x, y), r, r);

    w = m_w * m_kx;
    x -= w;
    x1 = x + 2 * w;
    pDC->LineTo(x, y, x1, y);

    x1 = m_YD.x + m_x * m_kx;
    y1 = y - w;
    x2 = x1;
    y2 = y1 + 2 * w;
    pDC->LineTo(x1, y1, x2, y2);

    //螺旋桨
    x = m_YD.x + m_x * m_kx;
    y = m_YD.y + m_y * m_ky;
    x -= w;
    DrawLuoXuanJiang(x, y);
    x += 2 * w;
    DrawLuoXuanJiang(x, y);
    x = m_YD.x + m_x * m_kx;
    y = m_YD.y + m_y * m_ky;
    y -= w;
    DrawLuoXuanJiang(x, y);
    y += 2 * w;
    DrawLuoXuanJiang(x, y);
}

void WRJ::DrawLuoXuanJiang(int x0, int y0)
{
    int x, y, w = m_w * m_kx;

    int i;
    for (i = 0; i < 4; i++)
    {
        x = x0 + w / 2 * cos(m_JDlxj + 90 * i / 180.0 * PI);
        y = y0 + w / 2 * sin(m_JDlxj + 90 * i / 180.0 * PI);
        pDC->LineTo(x0, y0, x, y);
    }
}

void WRJ::Move(int key)
{
    float deltat = 0.1;

    switch (key)
    {
    case Qt::Key_A:  //左
        m_x -= m_v * deltat;
        break;
    case Qt::Key_W:  //上
        m_y += m_v * deltat;
        break;
    case Qt::Key_D:  //右
        m_x += m_v * deltat;
        break;
    case Qt::Key_S:  //下
        m_y -= m_v * deltat;
        break;
    }
}

void WRJ::LuoXuanJiangXuanZhuan()
{
    m_JDlxj += m_vJD * 0.1;
}
