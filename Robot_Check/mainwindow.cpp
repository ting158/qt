#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

#include <QFile>
#include <QTextStream>
#include <QDebug>


struct Student {
    char name[100];
    float score;
    int age;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_painter = new QPainter();

//    QString fileName = "E:\\Qt Creator\\train\\Robot_Check\\test.txt"; // 替换为你的文件路径

//    QFile file(fileName);
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        qDebug() << "Failed to open the file.";
//        return;
//    }

//    QTextStream in(&file);
//    in.setCodec("UTF-8"); // 设置文件的编码方式为UTF-8
//    in << "\ufeff"; // 添加BOM

//    // 创建一个容器来存储多行数据
//    QList<Student> students;

//    // 循环逐行读取数据并格式化存储到变量中
//    while (!in.atEnd())
//    {
//        QString line = in.readLine();

//        // 使用 sscanf 解析每行的数据
//        Student student;
//        std::sscanf(line.toLatin1().data(), "%s %f %d", student.name, &student.score, &student.age);

//        // 将解析后的数据添加到容器中
//        students.append(student);
//    }

//    // 打印读取到的数据
//    for (const auto& student : students)
//    {
//        qDebug() << "Name: " << student.name;
//        qDebug() << "Score: " << student.score;
//        qDebug() << "Age: " << student.age;
//    }

//    file.close();


//    QFile file("E:\\Qt Creator\\train\\Robot_Check\\test2.txt");
//    file.open(QIODevice::ReadWrite);

//    QString str = QString("J楼 -310 686 -302 585 -213 610 -220 694 -300 640");

//    file.write(str.toUtf8().data());

//    QTextStream in(&file);

//    char name[20];
//    float num;

//    in >> name >> num;

//    qDebug() << name;
//    qDebug() << num;

//    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);

    m_cj.Draw(m_painter);

    m_painter->end();
}

