#include "formcanshu.h"
#include "ui_formcanshu.h"

FormCanShu::FormCanShu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCanShu)
{
    ui->setupUi(this);
}

FormCanShu::~FormCanShu()
{
    delete ui;
}

void FormCanShu::on_pushButton_xy_clicked()
{
    float x = ui->lineEdit_x->text().toFloat();
    float y = ui->lineEdit_y->text().toFloat();
    emit CanShuSignal_xy(x, y);
}


void FormCanShu::on_pushButton_vxvy_clicked()
{
    float vx = ui->lineEdit_vx->text().toFloat();
    float vy = ui->lineEdit_vy->text().toFloat();
    emit CanShuSignal_vxvy(vx, vy);
}

