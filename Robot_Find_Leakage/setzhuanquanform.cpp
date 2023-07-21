#include "setzhuanquanform.h"
#include "ui_setzhuanquanform.h"

SetZhuanQuanForm::SetZhuanQuanForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetZhuanQuanForm)
{
    ui->setupUi(this);

    connect(this, &SetZhuanQuanForm::setLineEdit, this, &SetZhuanQuanForm::receiveParameter);
}

SetZhuanQuanForm::~SetZhuanQuanForm()
{
    delete ui;
}

void SetZhuanQuanForm::receiveParameter(float r, float vJD, float dir, int sn)
{
    ui->lineEdit_r->setText(QString::number(r, 'f', 2));
    ui->lineEdit_vJD->setText(QString::number(vJD, 'f', 2));
    ui->lineEdit_dir->setText(QString::number(dir, 'f', 2));
    ui->lineEdit_sn->setText(QString::number(sn));
}


void SetZhuanQuanForm::on_pushButton_ok_clicked()
{
    emit this->sandToSetCar(ui->lineEdit_r->text().toFloat(), ui->lineEdit_vJD->text().toFloat(),
                            ui->lineEdit_dir->text().toFloat(), ui->lineEdit_sn->text().toInt());

    this->close();
}

