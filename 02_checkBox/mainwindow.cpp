#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->m_str_merge = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        m_str_merge.append(ui->lineEdit_str1->text());
        ui->lineEdit_merge->setText(m_str_merge);
    }

}


void MainWindow::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked())
    {
        m_str_merge.append(ui->lineEdit_str2->text());
        ui->lineEdit_merge->setText(m_str_merge);
    }
}


void MainWindow::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked())
    {
        m_str_merge.append(ui->lineEdit_str3->text());
        ui->lineEdit_merge->setText(m_str_merge);
    }
}

