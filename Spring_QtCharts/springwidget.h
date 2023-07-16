#ifndef SPRINGWIDGET_H
#define SPRINGWIDGET_H

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class SpringWidget; }
QT_END_NAMESPACE

class SpringWidget : public QWidget
{
    Q_OBJECT

public:
    SpringWidget(QWidget *parent = nullptr);
    ~SpringWidget();

    void paintEvent(QPaintEvent *event);

    void initSport();
    void Move();
    void DrawSpring();
    void initCharts();


    //成员变量

    QTimer * m_timer;
    QPainter * m_painter;
    qreal m_k;  //米与像素的转换系数

    //弹簧
    QPoint m_Point;  //弹簧悬挂点
    qreal m_LUp;       //悬挂弹簧的线长
    qreal m_LDown;     //悬挂小球线长
    qreal m_w;  //弹簧宽度
    qreal m_L;  //弹簧长度
    qreal m_L0; //弹簧原长
    qreal m_kSpring;  //弹性系数
    qreal m_damping;  //阻尼系数

    //小球
    qreal m_m;  //质量
    qreal m_r;  //半径
    qreal m_v;  //速度
    qreal m_f;  //合外力
    qreal m_a;  //加速度
    qreal m_y;  //位移

    //曲线
    qreal m_x;
    QSplineSeries * m_series_y;
    QSplineSeries * m_series_v;
    QSplineSeries * m_series_a;
    QSplineSeries * m_series_f;

    //表
    QChart * m_chart_y;
    QChart * m_chart_v;
    QChart * m_chart_a;
    QChart * m_chart_f;


private:
    Ui::SpringWidget *ui;
};
#endif // SPRINGWIDGET_H
