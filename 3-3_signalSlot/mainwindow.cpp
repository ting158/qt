#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dialog.h>
#include <QLabel>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_dlg = new Dialog();//实例化对话框对象
    connect(this,SIGNAL(sendInfo(QString)),m_dlg,SLOT(onGetInfo(QString)));//连接信号与槽


     //使用lambda表达式
//    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
//        QWidget * wid = new QWidget();
//        wid->resize(400, 400);
//        QLabel * label = new QLabel;

//        //设置背景颜色
//        QPalette palette;
//        palette.setColor(QPalette::Window, QColor(255, 0, 0));
//        label->setAutoFillBackground(true);  //一定要这句，否则不行
//        label->setPalette(palette);

//        label->setParent(wid);
//        label->move(100, 200);
//        QString str = ui->lineEdit_info->text();
//        label->setText(str);
//        wid->show();
//    });
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit_info->text();//获取文本框的值
    emit sendInfo(str);//发送信号
    m_dlg->show();//打开dialog对话框
    m_dlg->exec();//将对话框显示为模态对话框，直到用户将其关闭为止一直处于阻塞状态。
}

