#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QString>
#include <QFileDialog>
#include <QByteArray>
#include <QFile>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //按钮，将lineEdit_tab1的文本传到lineEdit_tab2
    connect(ui->btn_toTab2, &QPushButton::clicked, this, [=](){
        ui->lineEdit_tab2->setText(ui->lineEdit_tab1->text());
    });

    //按钮，保存到文本文件
    connect(ui->btn_saveToFile, &QPushButton::clicked, this, [=](){
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "E:\\Qt Creator\\train\\01_File");
        QFile file(filePath);

        file.open(QIODeviceBase::WriteOnly);   //用只写的方式进行写
        file.write(ui->lineEdit_tab1->text().toUtf8().data());
        file.close();

    });

    //按钮，打开
    connect(ui->btn_open, &QPushButton::clicked, this, [=](){
        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "E:\\Qt Creator\\train\\01_File");
        m_filname_textEdit.setFileName(filePath);

        m_filname_textEdit.open(QIODevice::ReadOnly); //以只读的方式打开
        QByteArray array = m_filname_textEdit.readAll();   //读所有
        ui->textEdit->setText(array);
        m_filname_textEdit.close();
    });

    //按钮，保存
    connect(ui->btn_save, &QPushButton::clicked, this, [=](){
        m_filname_textEdit.open(QIODeviceBase::ReadWrite);   //只写
        QString str = ui->textEdit->toPlainText();
        m_filname_textEdit.write(str.toUtf8().data());
        m_filname_textEdit.close();

    });

    //按钮，打开gbk编码的文本
    connect(ui->btn_openGBKtxt, &QPushButton::clicked, this, [=](){
        //直接打开会乱码
//        QFile filename("E:\\Qt Creator\\train\\01_File\\gbk.txt");
//        filename.open(QIODevice::ReadOnly);
//        QByteArray array = filename.readAll();
//        ui->lineEdit_openChinese->setText(array);

        //使用QTextCodec处理
        QFile filename("E:\\Qt Creator\\train\\01_File\\gbk.txt");
        filename.open(QIODeviceBase::ReadOnly);
        QTextCodec *codec = QTextCodec::codecForName("GBK");
        QString str = codec->toUnicode(filename.readAll());
        ui->lineEdit_openGBKtxt->setText(str);

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

