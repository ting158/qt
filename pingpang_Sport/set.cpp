#include "set.h"
#include "ui_set.h"

Set::Set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set)
{
    ui->setupUi(this);

    //文本居中
    ui->lineEdit_x->setAlignment( Qt::AlignHCenter);
    ui->lineEdit_y->setAlignment( Qt::AlignHCenter);
    ui->lineEdit_z->setAlignment( Qt::AlignHCenter);
    ui->lineEdit_vx->setAlignment( Qt::AlignHCenter);
    ui->lineEdit_vy->setAlignment( Qt::AlignHCenter);
    ui->lineEdit_vz->setAlignment( Qt::AlignHCenter);
}

Set::~Set()
{
    delete ui;
}

void Set::showDateToLineEdit(float x, float y, float z, float vx, float vy, float vz)
{
    ui->lineEdit_x->setText(QString::number(x, 'f', 2));
    ui->lineEdit_y->setText(QString::number(y, 'f', 2));
    ui->lineEdit_z->setText(QString::number(z, 'f', 2));
    ui->lineEdit_vx->setText(QString::number(vx, 'f', 2));
    ui->lineEdit_vy->setText(QString::number(vy, 'f', 2));
    ui->lineEdit_vz->setText(QString::number(vz, 'f', 2));
}

void Set::on_pushButton_OK_clicked()
{
    emit sandDate(ui->lineEdit_x->text().toFloat(),
                  ui->lineEdit_y->text().toFloat(),
                  ui->lineEdit_z->text().toFloat(),
                  ui->lineEdit_vx->text().toFloat(),
                  ui->lineEdit_vy->text().toFloat(),
                  ui->lineEdit_vz->text().toFloat());

    this->hide();

    emit stop();  //发送暂停运动信号
}


void Set::on_pushButton_Cancel_clicked()
{
    this->hide();
}

