#ifndef FORMGAMEOVER_H
#define FORMGAMEOVER_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class FormGameOver;
}

class FormGameOver : public QWidget
{
    Q_OBJECT

public:
    explicit FormGameOver(QWidget *parent = nullptr);
    ~FormGameOver();


    void paintEvent(QPaintEvent *event);

    void GetWinnerInfo(int winner);    //从游戏场景获取信息

    QPixmap m_pix;   //获取图片素材
    int m_winner;    //获胜者
    QPainter m_painter;  //画家

private:
    Ui::FormGameOver *ui;
};

#endif // FORMGAMEOVER_H
