#include "snake.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QThread>


Snake::Snake(QObject *parent)
    : QObject{parent}
{
    m_map = QRect(30, 60, 800, 500);

    m_wBody = 25;  //图片尺寸

    m_wNum = m_map.width() / m_wBody;
    m_hNum = m_map.height() / m_wBody;

    initSnake();

}

void Snake::initSnake()
{
    m_dir = RIGHT;  //方向
    m_score = 0;
    m_len = 3;  //长度

    int i = 0;
    for (i = 0; i < m_len; i ++)
    {
        m_body[i].setX(m_wBody / 2 - i);
        m_body[i].setY(m_hNum / 2);
    }

    //    QRandomGenerator::global()->bounded(10);		//生成一个0和10之间的整数
    //    QRandomGenerator::global()->bounded(10.123);	//生成一个0和10.123之间的浮点数
    //    QRandomGenerator::global()->bounded(10, 15);	//生成一个10和15之间的整数

    //随机生成目标
    m_food.setX(QRandomGenerator::global()->bounded(0, m_wNum));
    m_food.setY(QRandomGenerator::global()->bounded(0, m_hNum));

    qDebug() << m_food;
}

void Snake::setDirection(int key)
{
    switch (key) {
    case Qt::Key_W:
        if (m_dir != DOWN)
            m_dir = UP;
        qDebug() << "按下w";
        break;
    case Qt::Key_S:
        if (m_dir != UP)
            m_dir = DOWN;
        qDebug() << "按下s";
        break;
    case Qt::Key_A:
        if (m_dir != RIGHT)
            m_dir = LEFT;
        qDebug() << "按下a";
        break;
    case Qt::Key_D:
        if (m_dir != LEFT)
            m_dir = RIGHT;
        qDebug() << "按下d";
        break;
    default:
        break;
    }
}

void Snake::Move()
{   
    //蛇的头部碰到食物
    if (m_body[0].x() == m_food.x() && m_body[0].y() == m_food.y())
    {
        m_len++;
        m_score += 10;
        //更新食物坐标
        m_food.setX(QRandomGenerator::global()->bounded(0, m_wNum));
        m_food.setY(QRandomGenerator::global()->bounded(0, m_hNum));

        qDebug() << m_food;
    }

    int i;
    for (i = m_len - 1; i > 0; i--)
    {
        m_body[i] = m_body[i - 1];
    }

    if (m_dir == LEFT) //左
    {
        m_body[0].setX(m_body[0].x() - 1);
    }
    else if (m_dir == UP) //上
    {
        m_body[0].setY(m_body[0].y() - 1);
    }
    else if (m_dir == RIGHT) //右
    {
        m_body[0].setX(m_body[0].x() + 1);
    }
    else if (m_dir == DOWN) //下
    {
        m_body[0].setY(m_body[0].y() + 1);
    }


}

bool Snake::isGameOver()
{
    //判断是否撞墙
    int x = m_map.x() + m_body[0].x() * m_wBody;
    int y = m_map.y() + m_body[0].y() * m_wBody;
    if (x < m_map.x() || x > m_map.x() + (m_wNum - 1) * m_wBody ||
        y < m_map.y() || y > m_map.y() + (m_hNum - 1) * m_wBody)
    {
        return true;
    }

    //判断是否咬到自己
    //遍历蛇身坐标，与蛇头坐标相同即咬到
    for (int i = 1; i < m_len; i++)
    {
        if (m_body[0].x() == m_body[i].x() && m_body[0].y() == m_body[i].y())
        {
            return true;
        }
    }
    return false;
}
