#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "changjing.h"
#include "car.h"
#include "wrj.h"
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "setzhuanquanform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void ChuLiLBD();

    ChangJing m_scene;
    Car m_car;
    WRJ m_wrj;
    SetZhuanQuanForm m_set;
    QPainter * m_painter;
    int m_timer_CreateLiZi;
    int m_timer_Move;
    bool m_timer_CreateLiZi_Start;
    bool m_timer_Move_Start;

    CPoint m_tempYD;
    CPoint m_LBD;
    CPoint m_MBD;
    bool m_bjLBD;

private slots:
    void on_actionShow_LiZi_triggered();

    void on_actionhideLiZi_triggered();

    void on_actionleakgge_Start_triggered();

    void on_actionleakage_Stop_triggered();

    void on_actionShunYi_triggered();

    void on_actionYunSu_triggered();

    void on_actionZhuanQuan_triggered();

    void on_actionLuJing_triggered();

    void on_actionFindXieLou_triggered();

    void on_actionStop_triggered();

    void on_actionmoveStart_triggered();

    void on_actionmoveStop_triggered();

    void setFromDlg(float r, float vJD, float dir, int sn);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
