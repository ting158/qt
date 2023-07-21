#ifndef WRJ_H
#define WRJ_H

#include "car.h"

class WRJ : public Car
{
public:
    WRJ();


    void Draw(QPainter *p);
    void DrawWuRenJi();
    void DrawLuoXuanJiang(int x0, int y0);

    void Move(int key);
    void LuoXuanJiangXuanZhuan();

    float m_x, m_y;
    float m_r;
    float m_JDlxj;  //螺旋桨角度

    int m_nd;
};

#endif // WRJ_H
