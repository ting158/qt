#ifndef SPRINGMAINWINDOW_H
#define SPRINGMAINWINDOW_H

#include <QMainWindow>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class SpringMainWindow; }
QT_END_NAMESPACE

class SpringMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SpringMainWindow(QWidget *parent = nullptr);
    ~SpringMainWindow();

    void paintEvent(QPaintEvent *event);


    void initSport();
    void Move();
    void DrawQuXian(int initX, int initY, float gj[], int ngj, QString str, float max, float p);
    void DrawSpring();




    //成员变量
    QTimer * m_timer;
    QPainter m_painter;
    float m_k;  //米与像素的转换系数

    //弹簧
    QPoint m_Point;  //弹簧悬挂点
    float m_LUp;       //悬挂弹簧的线长
    float m_LDown;     //悬挂小球线长
    float m_w;  //弹簧宽度
    float m_L;  //弹簧长度
    float m_L0; //弹簧原长
    float m_kSpring;  //弹性系数
    float m_damping;  //阻尼系数

    //小球
    float m_m;  //质量
    float m_r;  //半径
    float m_v;  //速度
    float m_f;  //合外力
    float m_a;  //加速度
    float m_y;  //位移

    float m_vGJ[1000];
    float m_fGJ[1000];
    float m_aGJ[1000];
    float m_yGJ[1000];

    int m_nvGJ;
    int m_nfGJ;
    int m_naGJ;
    int m_nyGJ;

//signals:
//    void timeout();

private slots:
    void OnTimer();
    void on_pushButton_start_clicked();

private:
    Ui::SpringMainWindow *ui;
};
#endif // SPRINGMAINWINDOW_H
