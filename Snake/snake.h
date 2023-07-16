#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QRect>
#include <QPoint>

enum Direction
{
    LEFT, UP, RIGHT, DOWN
};

class Snake : public QObject
{
    Q_OBJECT
public:
    explicit Snake(QObject *parent = nullptr);

    void initSnake();             //初始化
    void setDirection(int key);   //根据按键改变方向
    void Move();                  //运动
    bool isGameOver();            //结束判断

    //地图参数
    QRect m_map;
    int m_wNum, m_hNum;  //地图格子个数

    //蛇参数
    QPoint m_body[500];   //蛇的每一节坐标
    int m_len;  //长度
    int m_dir;  //方向
    int m_wBody;  //每一节的宽度


    QPoint m_food; //目标
    int m_score;  //得分

signals:

};

#endif // SNAKE_H
