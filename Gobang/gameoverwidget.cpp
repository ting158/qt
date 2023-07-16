#include "gameoverwidget.h"
#include <QPainter>

GameOverWidget::GameOverWidget(QWidget *parent)
    : QWidget{parent}
{

}

void GameOverWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPixmap pix;

    if (m_winner == 1)
    {
        pix = QPixmap(":/res/whiteWin.png");
        p.drawPixmap(0, 0, pix.width(), pix.height(), pix);
    }
    if (m_winner == -1)
    {
        pix = QPixmap(":/res/blackWin.png");
        p.drawPixmap(0, 0, pix.width(), pix.height(), pix);
    }

    update();
}
