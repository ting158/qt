#include "formgameover.h"
#include "ui_formgameover.h"
#include <QPixmap>
#include <QPaintEvent>


FormGameOver::FormGameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGameOver)
{
    ui->setupUi(this);

}

FormGameOver::~FormGameOver()
{
    delete ui;
}

void FormGameOver::paintEvent(QPaintEvent *event)
{
    if (m_winner == 1)
    {
        m_pix = QPixmap(":/res/whiteWin.png");
    }
    if (m_winner == -1)
    {
        m_pix = QPixmap(":/res/blackWin.png");
    }

    m_painter.begin(this);
    m_painter.drawPixmap(0, 0, m_pix.width(), m_pix.height(), m_pix);
    m_painter.end();
}

void FormGameOver::GetWinnerInfo(int winner)
{
    m_winner = winner;

}
