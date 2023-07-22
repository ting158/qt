#include "Tank.h"
#include "time.h"
#include "math.h"
#include <QDebug>
#include <QPolygonF>


CTank::CTank()
{
	srand(time(NULL));

    m_BK.setX(200);
    m_BK.setY(0);
	m_wBK = 400;
	m_hBK = 600;

	InitGame();
}

CTank::~CTank()
{

}

//画图
void CTank::Draw(QPainter * painter)
{
    pDC = painter;

	DrawBackground();

	DrawCircle();
	DrawSquare();
	DrawTriangle();

	DrawTank();
	DrawBullet();
}

//画边框和得分
void CTank::DrawBackground()
{
	int x, y, w, h;
    x = m_BK.x();
    y = m_BK.y();
	w = m_wBK;
	h = m_hBK;
    pDC->drawRect(x, y, w, h);

    QString str = QString("得分：%1").arg(m_Score);
    pDC->setFont(QFont("黑体", 20, 2));
    pDC->drawText(m_BK.x() + m_wBK + 50, 50, str);
}

//画圆
void CTank::DrawCircle()
{
	int i, x, y, r;
	for (i = 0; i < m_nCir; i++)
	{
		x = m_Cir[i].x;
		y = m_Cir[i].y;
		r = m_Cir[i].r;
        pDC->drawEllipse(QPoint(x, y), r, r);
	}
}

//画正方形
void CTank::DrawSquare()
{
	int i, x, y, w;
	for (i = 0; i < m_nSqu; i++)
	{
		x = m_Squ[i].x;
		y = m_Squ[i].y;
		w = m_Squ[i].w;
        pDC->drawRect(x, y, w, w);
	}
}

//画三角形
void CTank::DrawTriangle()
{
	int i, x, y, h, w;
	for (i = 0; i < m_nTri; i++)
	{
		x = m_Tri[i].x;
		y = m_Tri[i].y;
		h = m_Tri[i].h;
		w = m_Tri[i].w;
        QPoint a(x, y);
        QPoint b(x - w / 2, y + h);
        QPoint c(x + w / 2, y + h);
        QPolygon tri;
        tri << a << b << c;
        pDC->drawPolygon(tri);
	}
}

//画坦克
void CTank::DrawTank()
{
	int x, y, r, w, h;

    x = m_Center.x() - m_BodyLen / 2;
    y = m_Center.y() - m_BodyLen / 2;
	w = m_BodyLen;
    pDC->drawRect(x, y, w, w);

	r = m_rCenter;
	w = r;
    x = m_Center.x() -  w / 2;
    y = m_Center.y() - m_GunLen;
	h = m_GunLen;
    pDC->drawRect(x, y, w, h);

    x = m_Center.x();
    y = m_Center.y();
    pDC->drawEllipse(QPoint(x, y), r, r);
}

//画子弹
void CTank::DrawBullet()
{
	int i, x, y, r;
	for (i = 0; i < m_nBul; i++)
	{
		x = m_Bul[i].x;
		y = m_Bul[i].y;
		r = m_Bul[i].r;
        pDC->drawEllipse(QPoint(x, y), r, r);
	}
}

//生成图形
void CTank::CreateBlock()
{
	int type = rand() % 3;  //0--圆，1--正方形，2--三角形

	if (0 == type)
	{
		CreateCircle();
	}

	if (1 == type)
	{
		CreateSquare();
	}

	if (2 == type)
	{
		CreateTriangle();
	}
}

//生成圆形
void CTank::CreateCircle()
{
	m_Cir[m_nCir].r = rand() % 11 + 10;
    m_Cir[m_nCir].x = rand() % (int)(m_wBK - 2 * m_Cir[m_nCir].r + 1) + m_BK.x() + m_Cir[m_nCir].r;
    m_Cir[m_nCir].y = m_BK.y() - m_Cir[m_nCir].r;
	m_Cir[m_nCir].v = rand() % 5 + 1;
	m_Cir[m_nCir].score = m_Cir[m_nCir].v;

	m_nCir++;
}

//生成正方形
void CTank::CreateSquare()
{
	m_Squ[m_nSqu].w = rand() % 21 + 20;
    m_Squ[m_nSqu].x = rand() % (int)(m_wBK - m_Squ[m_nSqu].w + 1) + m_BK.x();
    m_Squ[m_nSqu].y = m_BK.y() - m_Squ[m_nSqu].w;
	m_Squ[m_nSqu].v = rand() % 5 + 1;
	m_Squ[m_nSqu].score = m_Squ[m_nSqu].v;

	m_nSqu++;
}

//生成三角形
void CTank::CreateTriangle()
{
	m_Tri[m_nTri].h = rand() % 21 + 20;
	m_Tri[m_nTri].w = rand() % 21 + 20;
    m_Tri[m_nTri].x = rand() % (int)(m_wBK - m_Tri[m_nTri].w + 1) + m_BK.x() + m_Tri[m_nTri].w / 2;
    m_Tri[m_nTri].y = m_BK.y() - m_Tri[m_nTri].h;
	m_Tri[m_nTri].v = rand() % 5 + 1;
	m_Tri[m_nTri].score = m_Tri[m_nTri].v;

	m_nTri++;
}

//生成子弹
void CTank::CreateBullet()
{
	m_Bul[m_nBul].r = 5;
    m_Bul[m_nBul].x = m_Center.x();
    m_Bul[m_nBul].y = m_Center.y() - m_GunLen - m_Bul[m_nBul].r;
	m_Bul[m_nBul].v = 10;

	m_nBul++;
}

//方块运动
void CTank::MoveBlock()
{
	MoveCircle();
	MoveSquare();
	MoveTriangle();
}

void CTank::MoveCircle()
{
	int i;
	for (i = 0; i < m_nCir; i++)
	{
		m_Cir[i].y += m_Cir[i].v;

        if (m_Cir[i].y + m_Cir[i].r >= m_BK.y() + m_hBK)
		{
			DeleteCircle(i);
		}
	}
}

void CTank::MoveSquare()
{
	int i;
	for (i = 0; i < m_nSqu; i++)
	{
		m_Squ[i].y += m_Squ[i].v;

        if (m_Squ[i].y + m_Squ[i].w >= m_BK.y() + m_hBK)
		{
			DeleteSquare(i);
		}
	}
}

void CTank::MoveTriangle()
{
	int i;
	for (i = 0; i < m_nTri; i++)
	{
		m_Tri[i].y += m_Tri[i].v;

        if (m_Tri[i].y + m_Tri[i].h >= m_BK.y() + m_hBK)
		{
			DeleteTriangle(i);
		}
	}
}

//子弹运动
void CTank::MoveBullet()
{
    int i;

 	for (i = 0; i < m_nBul; i++)
	{
		m_Bul[i].y -= m_Bul[i].v;

		//出界
        if (m_Bul[i].y + m_Bul[i].r < m_BK.y())
		{
			DeleteBullet(i);
		}

		//击中图形
		BulletHitBlock();
	}
}

void CTank::DeleteCircle(int n)
{
	m_Cir[n] = m_Cir[m_nCir - 1];
	m_nCir--;
}

void CTank::DeleteSquare(int n)
{
	m_Squ[n] = m_Squ[m_nSqu - 1];
	m_nSqu--;
}

void CTank::DeleteTriangle(int n)
{
	m_Tri[n] = m_Tri[m_nTri - 1];
	m_nTri--;
}

void CTank::DeleteBullet(int n)
{
	m_Bul[n] = m_Bul[m_nBul - 1];
	m_nBul--;
}

void CTank::MoveTank(int key)
{
    switch(key)
	{
    case Qt::Key_A:  //左
        if (m_Center.x() - m_BodyLen / 2 > m_BK.x())
            m_Center.setX(m_Center.x() - 10);
		break;
    case Qt::Key_W:  //上
        if (m_Center.y() - m_GunLen > m_BK.y())
            m_Center.setY(m_Center.y() - 10);
		break;
    case Qt::Key_D:  //右
        if (m_Center.x() + m_BodyLen / 2 < m_BK.x() + m_wBK)
            m_Center.setX(m_Center.x() + 10);
		break;
    case Qt::Key_S:  //下
        if (m_Center.y() + m_BodyLen / 2 < m_BK.y() + m_hBK)
            m_Center.setY(m_Center.y() + 10);
        break;
    case Qt::Key_H:  //攻击
        this->CreateBullet();
        break;
	}
}

//子弹击中方块
void CTank::BulletHitBlock()
{
	int i, j;
	float d;

	for (i = 0; i < m_nCir; i++)
	{
		for (j = 0; j < m_nBul; j++)
		{
			d = sqrt((m_Cir[i].x - m_Bul[j].x) * (m_Cir[i].x - m_Bul[j].x) + (m_Cir[i].y - m_Bul[j].y) * (m_Cir[i].y - m_Bul[j].y));
			if (d <= m_Cir[i].r + m_Bul[j].r)
			{
				m_Score += m_Cir[i].score;
				DeleteCircle(i);
				DeleteBullet(j);
			}
		}
	}

	for (i = 0; i < m_nSqu; i++)
	{
		for (j = 0; j < m_nBul; j++)
		{
			if ((m_Bul[j].y - m_Bul[j].r <= m_Squ[i].y + m_Squ[i].w) && 
				(m_Bul[j].x + m_Bul[j].r >= m_Squ[i].x) &&
				(m_Bul[j].x - m_Bul[j].r <= m_Squ[i].x + m_Squ[i].w))
			{
				m_Score += m_Squ[i].score;
				DeleteSquare(i);
				DeleteBullet(j);
			}
		}
	}

	for (i = 0; i < m_nTri; i++)
	{
		for (j = 0; j < m_nBul; j++)
		{
			if ((m_Bul[j].y - m_Bul[j].r <= m_Tri[i].y + m_Tri[i].h) && 
				(m_Bul[j].x + m_Bul[j].r >= m_Tri[i].x - m_Tri[i].w / 2) &&
				(m_Bul[j].x - m_Bul[j].r <= m_Tri[i].x + m_Tri[i].w / 2))
			{
				m_Score += m_Tri[i].score;
				DeleteTriangle(i);
				DeleteBullet(j);
			}
		}
	}
}

//方块击中坦克
bool CTank::BlockHitTank()
{
	int i;
	float d;

	for (i = 0; i < m_nCir; i++)
    {
        d = sqrt((m_Cir[i].x - m_Center.x()) * (m_Cir[i].x - m_Center.x()) + (m_Cir[i].y - m_Center.y()) * (m_Cir[i].y - m_Center.y()));
		if (d < m_Cir[i].r + m_BodyLen / 2)
		{
            return true;
		}
	}

	for (i = 0; i < m_nSqu; i++)
	{
		float xn = m_Squ[i].x + m_Squ[i].w / 2;
        float yn = m_Squ[i].y + m_Squ[i].w / 2;
        d = sqrt((xn - m_Center.x()) * (xn - m_Center.x()) + (yn - m_Center.y()) * (yn - m_Center.y()));
		if (d < m_Squ[i].w / 2 + m_BodyLen / 2)
		{
            return true;
		}
	}

	for (i = 0; i < m_nTri; i++)
	{
        //三角形
        QPointF p1(m_Tri[i].x, m_Tri[i].y);
        QPointF p2(m_Tri[i].x - m_Tri[i].w / 2, m_Tri[i].y + m_Tri[i].h);
        QPointF p3(m_Tri[i].x + m_Tri[i].w / 2, m_Tri[i].y + m_Tri[i].h);
        QPolygonF tri;
        tri << p1 << p2 << p3;

        //矩形的顶点
        QPointF topLeft(m_Center.x() - m_BodyLen / 2, m_Center.y() - m_BodyLen / 2);
        QPointF topRight(m_Center.x() + m_BodyLen / 2, m_Center.y() - m_BodyLen / 2);
        QPointF bottomLeft(m_Center.x() - m_BodyLen / 2, m_Center.y() + m_BodyLen / 2);
        QPointF bottomRight(m_Center.x() + m_BodyLen / 2, m_Center.y() + m_BodyLen / 2);

        //检查三角形是否包含矩形的顶点
        if (tri.containsPoint(topLeft, Qt::OddEvenFill) ||
            tri.containsPoint(topRight, Qt::OddEvenFill) ||
            tri.containsPoint(bottomLeft, Qt::OddEvenFill) ||
            tri.containsPoint(bottomRight, Qt::OddEvenFill))
        {
            //如果三角形包含矩形的任意一个顶点，则认为三角形和矩形相交
            return true;
        }
	}

    return false;
}

//初始化坦克、方块、得分
void CTank::InitGame()
{
	m_Score = 0;

	m_rCenter = 10;
	m_BodyLen = 4 * m_rCenter;
	m_GunLen = 4 * m_rCenter;
    m_Center.setX((m_BK.x() + m_BK.x() + m_wBK) / 2);
    m_Center.setY(m_BK.y() + m_hBK - 3 * m_rCenter);

	m_nBul = 0;
	m_nCir = 0;
	m_nSqu = 0;
	m_nTri = 0;
}
