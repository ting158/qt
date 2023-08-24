#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QPainter>

class Ball : public QObject
{
    Q_OBJECT
public:
    explicit Ball(QObject *parent = nullptr);

    void initState();

    void Move();
    int isOverMove();

    void getData(float x, float y, float z, float vx, float vy, float vz);

    void Draw(QPainter * p);
    void DrawCST();   //侧视图
    void DrawFST();   //俯视图
    void DrawXCurve();//位移曲线
    void DrawVCurve();//速度曲线


    QPainter * m_painter;

    float m_k;  //  像素/米

    QPoint m_YD_CST;   //侧视图原点
    QPoint m_YD_FST;   //俯视图原点

    float m_L;  //桌子长度
    float m_W;  //桌子宽度
    float m_H;  //球网高度

    float m_r;  //半径

    //位置
    float m_x0, m_x;   //初始，实时
    float m_y0, m_y;
    float m_z0, m_z;

    //速度
    float m_vx0, m_vx;  //初始，实时
    float m_vy0, m_vy;
    float m_vz0, m_vz;

    //运动轨迹
    QVector<float> m_xGJ;
    QVector<float> m_yGJ;
    QVector<float> m_zGJ;
    QVector<float> m_vxGJ;
    QVector<float> m_vyGJ;
    QVector<float> m_vzGJ;


signals:

};

#endif // BALL_H
