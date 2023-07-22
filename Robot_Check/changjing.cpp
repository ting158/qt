#include "ChangJing.h"

#include "math.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

#define TextOut drawText
#define Ellipse drawEllipse
#define Rectangle drawRect
#define LineTo drawLine
#define PI 3.1415926

CChangJing::CChangJing()
{
	m_kx = 1920 / 1000.0;
	m_ky = -1080 / 1000.0;

    m_YD.setX(700);
    m_YD.setY(800);

	m_nd = 0;

    m_nJZ = 0;
    m_nLM = 0;
    m_nLZ = 0;

	srand((int)time(NULL));

	InitChangJing();

	m_flag_drawlz = false;
}

CChangJing::~CChangJing()
{

}

void CChangJing::InitChangJing()
{
    FILE *pf = fopen("E:\\Qt Creator\\train\\Robot_Check\\Buildings.txt", "r");
    while(!feof(pf))
    {
        fscanf(pf, "%s %f %f %f %f %f %f %f %f %f %f",
            m_JZ[m_nJZ].name,
            &(m_JZ[m_nJZ].pos[0][0]), &(m_JZ[m_nJZ].pos[0][1]),
            &(m_JZ[m_nJZ].pos[1][0]), &(m_JZ[m_nJZ].pos[1][1]),
            &(m_JZ[m_nJZ].pos[2][0]), &(m_JZ[m_nJZ].pos[2][1]),
            &(m_JZ[m_nJZ].pos[3][0]), &(m_JZ[m_nJZ].pos[3][1]),
            &(m_JZ[m_nJZ].name_pos[0]), &(m_JZ[m_nJZ].name_pos[1]));
        m_nJZ++;
    }
    fclose(pf);
    pf = NULL;

//    int i;
//    pf = fopen("Roads.txt", "r");
//    while(!feof(pf))
//    {
//        fscanf(pf, "%s %d", m_LM[m_nLM].name, &(m_LM[m_nLM].n));
//        for (i = 0; i < m_LM[m_nLM].n; i++)
//        {
//            fscanf(pf, "%f %f", &(m_LM[m_nLM].pos1[i][0]), &(m_LM[m_nLM].pos1[i][1]));
//        }
//        for (i = 0; i < m_LM[m_nLM].n; i++)
//        {
//            fscanf(pf, "%f %f", &(m_LM[m_nLM].pos2[i][0]), &(m_LM[m_nLM].pos2[i][1]));
//        }
//        fscanf(pf, "%f %f", &(m_LM[m_nLM].name_pos[0]), &(m_LM[m_nLM].name_pos[1]));
//        m_nLM++;
//    }
//    fclose(pf);
//    pf = NULL;
}

void CChangJing::Draw(QPainter *p)
{
	pDC = p;

	//显示浓度
    int x, y;
    QString str = QString("鼠标点击附近浓度：%1").arg(m_nd);
	x = 1600;
	y = 30;
	pDC->TextOut(x, y, str);


	DrawChangJing();

	if (m_flag_drawlz)
		DrawLiZi();
}

void CChangJing::DrawChangJing()
{
	int i, j;
    int x, y, x1, y1, x2, y2;
    QPoint dd[4];

	//建筑
	for (i = 0; i < m_nJZ; i++)
	{
		for (j = 0; j < 4; j++)
		{
            dd[j].setX(m_YD.x() + m_JZ[i].pos[j][0] * m_kx);
            dd[j].setY(m_YD.y() + m_JZ[i].pos[j][1] * m_ky);
		}
        pDC->drawPolygon(dd, 4);
        x = m_YD.x() + m_JZ[i].name_pos[0] * m_kx;
        y = m_YD.y() + m_JZ[i].name_pos[1] * m_ky;
		pDC->TextOut(x, y, m_JZ[i].name);
	}

	//路
	for (i = 0; i < m_nLM; i++)
	{
        x1 = m_YD.x() + m_LM[i].pos1[0][0] * m_kx;
        y1 = m_YD.y() + m_LM[i].pos1[0][1] * m_ky;
		for (j = 1; j < m_LM[i].n; j++)
		{
            x2 = m_YD.x() + m_LM[i].pos1[j][0] * m_kx;
            y2 = m_YD.y() + m_LM[i].pos1[j][1] * m_ky;
            pDC->LineTo(x1, y1, x2, y2);

            x1 = x2;
            y1 = y2;
		}

        x1 = m_YD.x() + m_LM[i].pos2[0][0] * m_kx;
        y1 = m_YD.y() + m_LM[i].pos2[0][1] * m_ky;
		for (j = 1; j < m_LM[i].n; j++)
		{
            x = m_YD.x() + m_LM[i].pos2[j][0] * m_kx;
            y = m_YD.y() + m_LM[i].pos2[j][1] * m_ky;
            pDC->LineTo(x1, y1, x2, y2);

            x1 = x2;
            y1 = y2;
		}
	}
}

void CChangJing::CreateLiZi()
{
	int i;

	for (i = 0; i < 50; i++)
	{
		m_LZ[m_nLZ].x = m_XLDx;
		m_LZ[m_nLZ].y = m_XLDy;
		m_LZ[m_nLZ].vx = rand() % 101 - 50;
		m_LZ[m_nLZ].vy = rand() % 101 - 50;
		m_LZ[m_nLZ].T = rand() % 21 + 80;
		m_LZ[m_nLZ].t = 0;
		m_nLZ++;
	}
}

void CChangJing::DrawLiZi()
{
	int i, x, y, r = 2;

	for (i = 0; i < m_nLZ; i++)
	{
        x = m_YD.x() + m_LZ[i].x * m_kx;
        y = m_YD.y() + m_LZ[i].y * m_ky;
        pDC->Ellipse(QPoint(x, y), r, r);
	}
}

void CChangJing::MoveLiZi()
{
	int i;
	float deltat = 0.1;

	for (i = 0; i < m_nLZ; i++)
	{
		m_LZ[i].x += m_LZ[i].vx * deltat;
		m_LZ[i].y += m_LZ[i].vy * deltat;
		m_LZ[i].t += deltat;

		if (m_LZ[i].t > m_LZ[i].T)
		{
			m_LZ[i] = m_LZ[m_nLZ - 1];
			m_nLZ--;
		}
	}
}

int CChangJing::QiuNongDu(float x, float y)
{
	int i;
	float d;
	int n = 0;

	for (i = 0; i < m_nLZ; i++)
	{
		d = sqrt((m_LZ[i].x - x) * (m_LZ[i].x - x) + (m_LZ[i].y - y) * (m_LZ[i].y - y));

		if (d <= 50)
			n++;
	}

	return n;
}
