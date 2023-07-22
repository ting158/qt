#include <QPainter>

#include "Car.h"

class CWRJ : public CCar  
{
public:
	void LuoXuanJiangXuanZhuan();
	void DrawLuoXuanJiang(int x, int y);
    void Move(int key);
	void DrawWuRenJi();
    void Draw(QPainter *p);
	CWRJ();
	virtual ~CWRJ();

	float m_x, m_y;
	float m_r;
	float m_JDlxj;  //螺旋桨角度

	int m_nd;
};

