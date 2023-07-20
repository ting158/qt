#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QWidget>
#include <QPen>
#include <QTimer>
#include <QString>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    m_x = 22;
    m_y = 22;
    m_w = 40;
    m_num = 15;

    initChess();

    m_playFlag = true;
    m_winner = 0;

    m_gameover = new GameOverWidget;


    //gameover窗口监听结束信号
    connect(m_gameover, &GameOverWidget::SandGameOver, this, [=](){
        m_gameover->setWindowTitle(QString("游戏结束"));
        m_gameover->setWindowIcon(QIcon(QPixmap(":/res/icon.png")));
        m_gameover->resize(535, 100);
        m_gameover->show();
    });

    //重新开始按钮
    connect(ui->pushButton_restart, &QPushButton::clicked, this, [=](){
        initChess();
    });
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    m_painter.begin(this);

    //棋盘
    DrawBackground();

    //棋子
    DrawChess();

    m_painter.end();

    update();
}

void GameWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->pos();

    if (!isWin())
    {
        m_index = this->ConvertMousePressToIndex(event->pos());
        qDebug() << m_index;

        play();

        m_winner = isWin();

        this->GameOver();
    }
}

void GameWidget::initChess()
{
    int i, j;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            m_chess[i][j] = 0;
        }
    }
    m_playFlag = true;
}

QPoint GameWidget::ConvertMousePressToIndex(QPoint p)
{
    QPoint index;

    index.setX((p.x() - m_x + m_w / 2) / m_w);
    index.setY((p.y() - m_y + m_w / 2) / m_w);

    return index;
}

void GameWidget::DrawBackground()
{
    QPixmap pix = QPixmap(":/res/background.png");
    m_painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);

    pix = QPixmap(":/res/qipan.png");
    m_painter.drawPixmap(0, 0, pix.width(), pix.height(), pix);

    QPen *pen = new QPen;//创建画笔对象
    m_painter.setFont(QFont("华文行楷", 20));//设置字体的字体和大小

    m_painter.setPen(*pen);//将画笔交给画家

    m_painter.drawText(630, 30, QString("玩家"));


    if (m_playFlag == true)
    {
        pix = QPixmap(":/res/white.png");
        m_painter.drawPixmap(640, 40, pix.width(), pix.height(), pix);
    }
    else
    {
        pix = QPixmap(":/res/black.png");
        m_painter.drawPixmap(640, 40, pix.width(), pix.height(), pix);
    }
}

void GameWidget::DrawChess()
{
    int i, j;
    QPixmap pix;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (m_chess[i][j] == -1)  //黑棋
            {
                pix = QPixmap(":/res/black.png");
                m_painter.drawPixmap(m_x + i * m_w - 15, m_y + j * m_w - 15, pix.width(), pix.height(), pix);
            }
            if (m_chess[i][j] == 1)  //白起
            {
                pix = QPixmap(":/res/white.png");
                m_painter.drawPixmap(m_x + i * m_w - 15, m_y + j * m_w - 15, pix.width(), pix.height(), pix);
            }
        }
    }
}

void GameWidget::play()
{
    if (m_chess[m_index.x()][m_index.y()] == 0)   //没有棋子时才能下棋
    {
        if (m_playFlag)
        {
            m_chess[m_index.x()][m_index.y()] = 1;
            m_playFlag = false;
        }
        else
        {
            m_chess[m_index.x()][m_index.y()] = -1;
            m_playFlag = true;
        }
    }

}

int GameWidget::isWin()
{
    int i;

    //八个方向相同颜色棋子的数量
    int up = 0, down = 0;
    int left = 0, right = 0;
    int leftup = 0, rightdown = 0;
    int leftdown = 0, rightup = 0;

    //计算数量
    int color;
    if (m_playFlag == false)   //判断白棋
        color = 1;
    else
        color = -1;        //判断黑棋

    //上下方向
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x() - i][m_index.y()] == color)
            up++;
        else
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x() + i][m_index.y()] == color)
            down++;
        else
            break;
    }
    //左右方向
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x()][m_index.y() - i] == color)
            left++;
        else
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x()][m_index.y() + i] == color)
            right++;
        else
            break;
    }
    //左上右下方向
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x() - i][m_index.y() - i] == color)
            leftup++;
        else
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x() + i][m_index.y() + i] == color)
            rightdown++;
        else
            break;
    }
    //左下右上方向
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x() + i][m_index.y() - i] == color)
            leftdown++;
        else
            break;
    }
    for (i = 1; i < 5; i++)
    {
        if (m_index.x() - i < 0 && m_index.x() - i >= m_num)
            break;
        if (m_chess[m_index.x() - i][m_index.y() + i] == color)
            rightup++;
        else
            break;
    }

    //判断输赢
    if (up + down >= 4 || left + right >= 4 || leftup + rightdown >= 4 || leftdown + rightup >= 4)
    {
        emit SandWinnerInfo(color);
        return color;    //返回1白棋胜利，返回-1黑棋胜利
    }
    else
        return 0;  //没有胜利，游戏继续进行
}

void GameWidget::GameOver()
{
    m_gameover->m_winner = this->m_winner;

    if (m_winner == 1 || m_winner == -1)
    {
        emit m_gameover->SandGameOver();
    }
}

