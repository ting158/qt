#include "graphical.h"
#include <math.h>
#include <QDebug>

Graphical::Graphical()
{
    m_graphicalType = CIRCLE;
    m_modeType = DRAW;
    m_optCurrent = "无操作";
}

void Graphical::Draw(QPainter *p)
{
    m_painter = p;

    DrawCircle();
    DrawRectangle();
    if (m_modeType != MOVE)
        DrawTemp();
    DrawCurrentOperation();
}

void Graphical::DrawCircle()
{
    int x, y, r;
    QVector<SCircle>::iterator iter;

    for (iter = m_cir.begin(); iter != m_cir.end(); iter++)
    {
        x = iter->x;
        y = iter->y;
        r = iter->r;
        m_painter->drawEllipse(QPoint(x, y), r, r);
    }
}

void Graphical::DrawRectangle()
{
    int x, y, w, h;
    QVector<SRectangle>::iterator iter;

    for (iter = m_rec.begin(); iter != m_rec.end(); iter++)
    {
        x = iter->x;
        y = iter->y;
        w = iter->w;
        h = iter->h;
        m_painter->drawRect(x, y, w, h);
    }
}

void Graphical::DrawTemp()
{
    int x, y, r, w, h;

    x = m_tempCir.x;
    y = m_tempCir.y;
    r = m_tempCir.r;
    m_painter->drawEllipse(QPoint(x, y), r, r);

    x = m_tempRec.x;
    y = m_tempRec.y;
    w = m_tempRec.w;
    h = m_tempRec.h;
    m_painter->drawRect(x, y, w, h);
}

void Graphical::DrawCurrentOperation()
{
    if (m_graphicalType == CIRCLE && m_modeType == DRAW)
        m_optDraw = "当前为画圆";
    if (m_graphicalType == RECTANGLE && m_modeType == DRAW)
        m_optDraw = "当前为画矩形";
    m_painter->drawText(20, 50, m_optDraw);

    QString str = "当前操作：";
    str += m_optCurrent;
    m_painter->drawText(20, 70, str);
}

void Graphical::SetOpt(QString str)
{
    m_optCurrent = str;
}

void Graphical::SaveGraphical(QPoint press, QPoint release)
{
    if (m_graphicalType == CIRCLE)
    {
        SCircle cir;
        cir.x = press.x();
        cir.y = press.y();
        cir.r = sqrt((release.x() - press.x()) * (release.x() - press.x()) + (release.y() - press.y()) * (release.y() - press.y()));
        cir.name = QString::number(m_cir.count() + 1);
        cir.name += "号圆";
        m_cir.push_back(cir);
    }
    if (m_graphicalType == RECTANGLE)
    {
        SRectangle rec;
        rec.x = press.x();
        rec.y = press.y();
        rec.w = release.x() - press.x();
        rec.h = release.y() - press.y();
        rec.name = QString::number(m_rec.count() + 1);
        rec.name += "号矩形";
        m_rec.push_back(rec);
    }
}

void Graphical::SaveTempGraphical(QPoint press, QPoint move)
{
    if (m_graphicalType == CIRCLE)
    {
        m_tempCir.x = press.x();
        m_tempCir.y = press.y();
        m_tempCir.r = sqrt((move.x() - press.x()) * (move.x() - press.x()) + (move.y() - press.y()) * (move.y() - press.y()));
        m_tempCir.name = "临时圆";
    }
    if (m_graphicalType == RECTANGLE)
    {
        m_tempRec.x = press.x();
        m_tempRec.y = press.y();
        m_tempRec.w = move.x() - press.x();
        m_tempRec.h = move.y() - press.y();
        m_tempRec.name = "临时矩形";
    }
}

void Graphical::DeleteTempGraphical()
{
    m_tempCir.r = 0;
    m_tempRec.w = 0;
    m_tempRec.h = 0;
}

void Graphical::MoveGraphical(QPoint press, QPoint move)
{
    if (m_indexChoose == -1)
        return;

    if (m_moveGraType == CIRCLE)
    {
        m_optCurrent = "移动圆";

        m_cir[m_indexChoose].x = m_tempCir.x + (move.x() - press.x());
        m_cir[m_indexChoose].y = m_tempCir.y + (move.y() - press.y());

    }
    if (m_moveGraType == RECTANGLE)
    {
        m_optCurrent = "移动矩形";

        m_rec[m_indexChoose].x = m_tempRec.x + (move.x() - press.x());
        m_rec[m_indexChoose].y = m_tempRec.y + (move.y() - press.y());
    }
}

void Graphical::OverMove()
{
    m_optCurrent = "无操作";
}

int Graphical::GetIndexChoosingGraphical(QPoint press)
{
    int x, y, r, w, h, d;
    QVector<SCircle>::iterator iterCir;
    QVector<SRectangle>::iterator iterRec;

    for (iterCir = m_cir.begin(); iterCir != m_cir.end(); iterCir++)
    {
        x = iterCir->x;
        y = iterCir->y;
        r = iterCir->r;

        d = sqrt((press.x() - x) * (press.x() - x) + (press.y() - y) * (press.y() - y));

        //选中圆
        if (d > r - 5 && d < r + 5)
        {
            int index = std::distance(m_cir.begin(), iterCir);
            m_moveGraType = CIRCLE;
            m_optDraw = "选择的图形：" + m_cir[index].name;
            m_tempCir = m_cir[index];
            return index;   //返回元素的索引（从0开始）
        }
    }

    for (iterRec = m_rec.begin(); iterRec != m_rec.end(); iterRec++)
    {
        x = iterRec->x;
        y = iterRec->y;
        w = iterRec->w;
        h = iterRec->h;

        if ((press.x() > x - 5 && press.x() < x + 5 && press.y() > y && press.y() < y + h) ||  //左高
            (press.x() > x + w - 5 && press.x() < x + w + 5 && press.y() > y && press.y() < y + h) ||  //右高
            (press.x() > x && press.x() < x + w && press.y() > y - 5 && press.y() < y + 5) ||  //上宽
            (press.x() > x && press.x() < x + w && press.y() > y - h - 5 && press.y() < y + h + 5))    //下宽
        {
            int index = std::distance(m_rec.begin(), iterRec);
            m_moveGraType = RECTANGLE;
            m_optDraw = "选择的图形：" + m_rec[index].name;

            m_tempRec = m_rec[index];
            return index;   //返回元素的索引（从0开始）
        }
    }

    m_optDraw = "选择的图形：未选择";
    return -1;   //未选择返回-1
}
