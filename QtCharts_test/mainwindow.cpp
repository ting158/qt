#include "mainwindow.h"
#include <QtCharts>
#include <QPointF>
#include "ui_mainwindow.h"


QT_CHARTS_USE_NAMESPACE



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initChart();
    initChart2();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initChart()
{
    QLineSeries* series = new QLineSeries();         // 创建一个折线图series
    series->setName("线段名称");


//    // 添加数据方法1
//    series->append(0, 5);
//    series->append(1, 4);
//    series->append(3, 8);
    // 添加数据方法2
//    *series << QPointF(4, 10)  << QPointF(5, 2)  << QPointF(6, 5);

    // 添加数据方法3，一次更新所有数据，速度比较快
//    QList<QPointF> points;
//    for(int i = 0; i < 20; i++)
//    {
//        points.append(QPointF(i, i %5));
//    }
    QList<QPointF> sinCurve;
    for (int i = 0; i < 20; i++)
    {
        sinCurve.append(QPointF(i, qSin(i * 10 / 180.0 * 3.1415)));
    }

    series->replace(sinCurve);

    QChart* chart = ui->chartView->chart();     // 获取QchartView内置的chart
    chart->addSeries(series);                   // 将创建好的折线图series添加进chart中
    chart->createDefaultAxes();                 // 基于已添加到图表中的series为图表创建轴。以前添加到图表中的任何轴都将被删除。
    chart->setTitle("折线图图表标题");            // 设置标题

    ui->chartView->setRenderHint(QPainter::Antialiasing);  // 设置抗锯齿
}

void MainWindow::initChart2()
{
    QSplineSeries* series = new QSplineSeries();   // 创建一个样条曲线对象
    series->setName("曲线");


    // 添加数据方式1
    series->append(0, 10);
//    series->append(1, 1);
    series->append(2, 4);
//    series->append(3, 7);
    series->append(4, 13);
//    // 添加数据方式2
//    *series << QPointF(5, 3)<< QPointF(6, 6)<< QPointF(7, 13)<< QPointF(8, 5);
//    // 添加数据方式3，一次性更新所有数据
//    QList<QPointF> points;
//    for(int i = 0; i < 20; i++)
//    {
//        points.append(QPointF(i, i %7));
//    }
//    series->replace(points);


    QChart* chart = ui->chartView->chart();    // 获取一个chart用于管理不同类型的series和其他图表相关对象
    //chart->legend()->hide();                   // 隐藏图例
    chart->addSeries(series);                  // 添加创建好的曲线图对象
    chart->setTitle("曲线图图表标题");           // 设置标题
    chart->createDefaultAxes();                // 基于已添加到图表中的series为图表创建轴。以前添加到图表中的任何轴都将被删除。
    chart->axes(Qt::Vertical).first()->setRange(0, 20);  // 设置Y轴的范围

    ui->chartView->setRenderHint(QPainter::Antialiasing);  // 设置抗锯齿

}

