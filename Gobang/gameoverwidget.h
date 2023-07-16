#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H

#include <QWidget>

class GameOverWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameOverWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);


    int m_winner;

signals:
    void SandGameOver();
};

#endif // GAMEOVERWIDGET_H
