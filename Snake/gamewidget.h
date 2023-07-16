#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <snake.h>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>
#include "formgameover.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWidget; }
QT_END_NAMESPACE

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = nullptr);
    ~GameWidget();

    void paintEvent(QPaintEvent *event);  //绘图事件
    void keyPressEvent(QKeyEvent *event);  //按键事件

    void DrawBackground(); //画背景
    void DrawSnake();      //画蛇
    void DrawFood();       //画目标

    QPainter m_painter;
    Snake m_snake;
    QPixmap m_pix;
    QTimer * m_timer;
    FormGameOver * m_over;

signals:
    void SandGameOverMessage();

public slots:
    void OnTimer();
    void on_pushButton_start_clicked();

private slots:
    void on_pushButton_stop_clicked();

    void on_pushButton_restart_clicked();

private:
    Ui::GameWidget *ui;
};
#endif // GAMEWIDGET_H
