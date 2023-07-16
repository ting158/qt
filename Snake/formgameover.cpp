#include "formgameover.h"
#include "ui_formgameover.h"

FormGameOver::FormGameOver(int score, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGameOver)
{
    ui->setupUi(this);

    QString str = QString("游戏结束，您的得分：");
    str += QString::number(score);
    ui->label->setText(str);
}

FormGameOver::~FormGameOver()
{
    delete ui;
}
