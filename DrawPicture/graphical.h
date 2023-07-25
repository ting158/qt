#ifndef GRAPHICAL_H
#define GRAPHICAL_H

#include <QPainter>

enum GraphicalType
{
    CIRCLE, RECTANGLE
};

enum ModeType
{
    DRAW, MOVE
};

typedef struct
{
    float x, y;
    float r;
    QString name;
}SCircle;

typedef struct
{
    float x, y;
    float w, h;
    QString name;
}SRectangle;

class Graphical
{
public:
    Graphical();

    void Draw(QPainter * p);
    void DrawCircle();
    void DrawRectangle();
    void DrawTemp();
    void DrawCurrentOperation();

    void SaveGraphical(QPoint press, QPoint release);
    void SaveTempGraphical(QPoint press, QPoint move);
    void DeleteTempGraphical();

    void MoveGraphical(QPoint press, QPoint move);
    void OverMove();

    int GetIndexChoosingGraphical(QPoint press);   //返回元素索引值

    void SetOpt(QString str);

    QPainter * m_painter;

    int m_graphicalType;
    int m_modeType;
    QVector<SCircle> m_cir;
    QVector<SRectangle> m_rec;
    SCircle m_tempCir;
    SRectangle m_tempRec;
    SCircle m_moveCir;
    SRectangle m_moveRec;
    QString m_optDraw;
    QString m_optCurrent;
    int m_indexChoose;  //被选中图形的索引
    int m_moveGraType;  //移动的图形种类

};

#endif // GRAPHICAL_H
