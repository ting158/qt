#ifndef CHANGJING_H
#define CHANGJING_H

#include <QPainter>

//typedef struct
//{
//    int x, y;
//}CPoint;

typedef struct
{
	char name[50];
	float pos[4][2];
	float name_pos[2];
}SBuilding;

typedef struct
{
	char name[50];
	float pos1[20][2];
	float pos2[20][2];
	int n;
	float name_pos[2];
}SRoad;

typedef struct
{
	float x, y;
	float vx, vy;
	float T;
	float t;
}SLiZi;

class CChangJing  
{
public:
	int QiuNongDu(float x, float y);
	void MoveLiZi();
	void DrawChangJing();
	void DrawLiZi();
	void CreateLiZi();
    void Draw(QPainter *pDC);
	void InitChangJing();
	CChangJing();
	virtual ~CChangJing();

    QPainter *pDC;
	float m_kx;
	float m_ky;
    QPoint m_YD;

	float m_XLDx, m_XLDy;
	int m_nd;  //浓度

    SBuilding m_JZ[100];
    int m_nJZ;

    SRoad m_LM[100];
    int m_nLM;

    SLiZi m_LZ[100000];
    int m_nLZ;


	bool m_flag_drawlz;

};

#endif // CHANGJING_H
