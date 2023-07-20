#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include "gameoverwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWidget; }
QT_END_NAMESPACE

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = nullptr);
    ~GameWidget();

    void paintEvent(QPaintEvent *event);        //画图事件
    void mousePressEvent(QMouseEvent *event);   //鼠标按下事件

    //初始化棋盘
    void initChess();

    //将鼠标点击的坐标转换为棋盘坐标（棋盘二维数组下标）
    QPoint ConvertMousePressToIndex(QPoint p);

    //画背景
    void DrawBackground();

    //画棋子
    void DrawChess();

    //下棋
    void play();

    //获胜判断
    int isWin();

    //胜利后的处理
    void GameOver();


    //成员变量
    QPainter m_painter;
    int m_x, m_y;   //棋盘左上角坐标
    int m_w;   //棋盘格子的宽度
    int m_num;
    int m_chess[15][15];  //记录棋子，0-->无，-1-->黑，1-->白
    bool m_playFlag;   //黑白棋标志，true为白棋，false为黑棋
    QPoint m_index;   //鼠标点击的棋盘坐标
    int m_winner;

    GameOverWidget * m_gameover;

signals:
    void SandWinnerInfo(int winnner);

private:
    Ui::GameWidget *ui;
};
#endif // GAMEWIDGET_H
