#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include "Tank.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWidget; }
QT_END_NAMESPACE

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = nullptr);
    ~GameWidget();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);

    QPainter * m_painter;
    CTank m_tank;
    int m_timer1Id;   //产生方块
    int m_timer2Id;   //方块和子弹的运动
    bool m_timer1Satrt;
    bool m_timer2Satrt;

private slots:
    void on_pushButton_Start_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_Restart_clicked();

private:
    Ui::GameWidget *ui;
};
#endif // GAMEWIDGET_H
