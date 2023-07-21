#include "car.h"

#define TextOut drawText
#define Ellipse drawEllipse
#define Rectangle drawRect
#define LineTo drawLine
#define PI 3.1415926

Car::Car()
{
    m_kx = 1920 / 1000.0;
    m_ky = -1080 / 1000.0;
    m_YD.x = 700;
    m_YD.y = 850;

    m_nd = 0;

    m_x = 0;
    m_y = 0;


    m_MBx = 0;
    m_MBy = 0;
    m_v = 80;
    m_w = 10;
    m_mode = -1;
    m_sn = -1;
    m_dir = 0;
    m_r = 50;
    m_vJD = 50;

    m_nGJ = 0;
    m_bjCreate = 0;

    m_nd_max = 0;


    m_ndCir.jd = 0;
    m_ndCir.r = 50;
    m_ndCir.omg = 100;
}

void Car::Draw(QPainter *p)
{
    pDC = p;

    //显示浓度
    int x, y;
    QString str = QString("小车附近浓度：%1").arg(m_nd);
    x = 1750;
    y = 150;
    pDC->TextOut(x, y, str);

    //DrawNDMaxMin();
    DrawCar();
    DrawLuJing();
}

void Car::DrawCar()
{
    int x, y, r, w, h;
    QBrush * Brush = new QBrush(QColor(64, 224, 208));
    //Brush->setColor(QColor(64, 224, 208));
    pDC->setBrush(*Brush);

    x = m_YD.x + m_x * m_kx;
    y = m_YD.y + m_y * m_ky;
    r = m_w / 3 * m_kx;
    pDC->Ellipse(QPoint(x, y), r, r);

    x = x - r - m_w * m_kx + 2;
    y = y - r;
    w = m_w * m_kx;
    h = r * 2;
    pDC->Rectangle(x, y, w, h);
}

void Car::DrawLuJing()
{
    int i, x1, y1, x2, y2;

    x1 = m_YD.x + m_GJ[0][0] * m_kx;
    y1 = m_YD.y + m_GJ[0][1] * m_ky;
    for (i = 1; i < m_nGJ; i++)
    {
        x2 = m_YD.x + m_GJ[i][0] * m_kx;
        y2 = m_YD.y + m_GJ[i][1] * m_ky;
        pDC->LineTo(x1, y1, x2, y2);

        x1 = x2;
        y1 = y2;
    }
}

void Car::DrawNDMaxMin()
{
    int x, y, r = 10;

    QBrush * Brush1 = new QBrush(QColor(255,0,0));
    //Brush1.setColor(QColor(255,0,0));
    pDC->setBrush(*Brush1);
    x = m_YD.x + m_ndCir.Max_x * m_kx;
    y = m_YD.y + m_ndCir.Max_y * m_ky;
    pDC->Ellipse(QPoint(x, y), r, r);

    QBrush * Brush2 = new QBrush(QColor(0,255,0));
    //Brush2.setColor(QColor(0,255,0));
    pDC->setBrush(*Brush2);
    x = m_YD.x + m_ndCir.Min_x * m_kx;
    y = m_YD.y + m_ndCir.Min_y * m_ky;
    pDC->Ellipse(QPoint(x, y), r, r);
}

void Car::Move()
{
    if (m_mode == YunSu)
        MoveYunSuDaoMuBiaoDian();
    if (m_mode == ZhuanQuan)
        MoveZhuanQuan();
    if (m_mode == LuJing)
        MoveGuiJi();
    if (m_mode == FindXieLou)
        //MoveFindXieLouDian();
        MoveZhuanQuanChaZhaoXieLouDian();
}

void Car::MoveDianNaDaoNa()
{
    m_x = m_MBx;
    m_y = m_MBy;
}

void Car::MoveYunSuDaoMuBiaoDian()
{
    float deltat = 0.1;

    m_d = sqrt((m_MBx - m_x) * (m_MBx - m_x) + (m_MBy - m_y) * (m_MBy - m_y));
    m_vx = m_v * (m_MBx - m_x) / m_d;
    m_vy = m_v * (m_MBy - m_y) / m_d;

    if (m_d > 5)
    {
        m_x += m_vx * deltat;
        m_y += m_vy * deltat;
    }
}

void Car::MoveZhuanQuan()
{
    float deltat = 0.1;

    m_x = m_YXx + m_r * cos(m_JD / 180 * PI);
    m_y = m_YXy + m_r * sin(m_JD / 180 * PI);
    m_JD += m_vJD * m_sn * deltat;
}

void Car::MoveGuiJi()
{
    m_MBx = m_GJ[m_nowMB][0];
    m_MBy = m_GJ[m_nowMB][1];

    MoveYunSuDaoMuBiaoDian();

    if (m_d <= 5 && m_nowMB < m_nGJ)
        m_nowMB++;
}

void Car::MoveZhuanQuanChaZhaoXieLouDian()
{
    float deltat = 0.1;

    if (m_ndCir.jd < 360)
    {
        //转圈
        m_x = m_ndCir.x + m_ndCir.r * cos(m_ndCir.jd / 180 * PI);
        m_y = m_ndCir.y + m_ndCir.r * sin(m_ndCir.jd / 180 * PI);
        m_ndCir.jd += m_ndCir.omg * deltat;

        //保存最大浓度点和最小浓度点
        if (m_ndCir.Max < m_nd)
        {
            m_ndCir.Max = m_nd;
            m_ndCir.Max_x = m_x;
            m_ndCir.Max_y = m_y;
        }
        if (m_ndCir.Min > m_nd)
        {
            m_ndCir.Min = m_nd;
            m_ndCir.Min_x = m_x;
            m_ndCir.Min_y = m_y;
        }
    }
    else
    {
        //计算目标点坐标
        m_MBx = m_ndCir.x - 2 * (m_ndCir.x - m_ndCir.Max_x);
        m_MBy = m_ndCir.y - 2 * (m_ndCir.y - m_ndCir.Max_y);

        //匀速运动到目标点
        MoveYunSuDaoMuBiaoDian();

        //到达目标点
        if (m_d < 5)
        {
            m_ndCir.jd = 0;  //初始化角度
            m_ndCir.r *= 0.9;    //半径减小

            //初始化圆
            initCircleNDTest();
        }
    }
}

int Car::isOverLuJing()
{
    if (m_nowMB > m_nGJ - 1)
    {
        m_nowMB = 1;
        m_nGJ = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

void Car::initCircleNDTest()
{
    m_ndCir.x = m_x - m_ndCir.r * cos(m_ndCir.jd / 180 * PI);
    m_ndCir.y = m_y - m_ndCir.r * sin(m_ndCir.jd / 180 * PI);
    m_ndCir.Max = 0;
    m_ndCir.Min = 10000000;
    m_ndCir.Max_x = m_x;
    m_ndCir.Max_y = m_y;
    m_ndCir.Min_x = m_x;
    m_ndCir.Min_y = m_y;
}

void Car::ZhuanHuaMuBiaoDian(QPoint p)
{
    m_MBx = (p.x() - m_YD.x) / m_kx;
    m_MBy = (p.y() - m_YD.y) / m_ky;

    if (m_mode == ShunYi)
        MoveDianNaDaoNa();
}

void Car::ChuLiYuanXinCanShu()
{
    m_JD = (12 + 3 - m_dir) * 30;
    m_YXx = m_x - m_r * cos((180 - m_JD) / 180 * PI);
    m_YXy = m_y - m_r * sin((180 - m_JD) / 180 * PI);

    m_initJD = m_JD;
}

void Car::ChuLiGuiJiZuoBiao(QPoint p)
{
    ZhuanHuaMuBiaoDian(p);

    m_GJ[m_nGJ][0] = m_MBx;
    m_GJ[m_nGJ][1] = m_MBy;
    m_nGJ++;

    if (m_mode == LuJing && m_nGJ == 1)
    {
        m_x = m_GJ[0][0];
        m_y = m_GJ[0][1];
    }
}
