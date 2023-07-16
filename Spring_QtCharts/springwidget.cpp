#include "springwidget.h"
#include "ui_springwidget.h"
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>


SpringWidget::SpringWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpringWidget)
{
    ui->setupUi(this);

    m_k = 200;

    m_Point.setX(200);
    m_Point.setY(100);
    m_LUp = 0.25;
    m_LDown = 0.14;
    m_L0 = 0.1;
    m_kSpring = 10;
    m_damping = 0.9;
    m_w = 0.25;
    m_m = 0.8;
    m_r = 0.05;
    m_v = 1;
    m_y = 0;
    m_L = 0.5;
    m_x = 0;
    ui->lineEdit_m->setText(QString::number(m_m, 'f', 2));
    ui->lineEdit_kSpring->setText(QString::number(m_kSpring, 'f', 2));
    ui->lineEdit_damping->setText(QString::number(m_damping, 'f', 2));

    m_painter = new QPainter;
    m_timer = new QTimer(this);

    initCharts();

    //时钟事件
    connect(m_timer, &QTimer::timeout, this, &SpringWidget::Move);

    //开始按钮
    connect(ui->pushButton_start, &QPushButton::clicked, this, [=](){
        m_timer->start(100);
    });

    //停止按钮
    connect(ui->pushButton_stop, &QPushButton::clicked, m_timer, &QTimer::stop);

    //重新开始按钮
    connect(ui->pushButton_restart, &QPushButton::clicked, this, &SpringWidget::initSport);

    //设置按钮
    connect(ui->pushButton_save, &QPushButton::clicked, this, [=](){
        m_m = ui->lineEdit_m->text().toDouble();
        m_kSpring = ui->lineEdit_kSpring->text().toDouble();
        m_damping = ui->lineEdit_damping->text().toDouble();
        this->initSport();
    });
}

SpringWidget::~SpringWidget()
{
    delete ui;
}

void SpringWidget::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);

    this->DrawSpring();

    m_painter->end();

    update();
}

void SpringWidget::initSport()
{
    m_y = 0;
    m_L = 0.5;

    m_series_y->clear();
    m_series_v->clear();
    m_series_a->clear();
    m_series_f->clear();

    m_x = 0;
}

void SpringWidget::Move()
{
    m_f = m_m * 9.8 - m_kSpring * (m_L - m_L0);
    m_a = m_f / m_m;
    m_y = m_v * 0.1 + 0.5 * m_a * 0.1 * 0.1;
    m_L += m_y;
    m_v += m_a * 0.1;
    m_v *= m_damping;

    //保存数据
    m_series_y->append(QPointF(m_x, m_y));
    m_series_v->append(QPointF(m_x, m_v));
    m_series_a->append(QPointF(m_x, m_a));
    m_series_f->append(QPointF(m_x, m_f));

    //曲线滚动效果
    if (m_series_y->count() >= 100)
    {
        //删除第一个点
        m_series_y->remove(0);
        m_series_v->remove(0);
        m_series_a->remove(0);
        m_series_f->remove(0);

        //将后面点的横坐标重置为从0开始
        for (int i = 0; i < m_series_y->count(); i++)
        {
            m_series_y->replace(i, 0.1 * i, m_series_y->at(i).y());
            m_series_v->replace(i, 0.1 * i, m_series_v->at(i).y());
            m_series_a->replace(i, 0.1 * i, m_series_a->at(i).y());
            m_series_f->replace(i, 0.1 * i, m_series_f->at(i).y());
        }
    }

    m_x += 0.1;
}

void SpringWidget::DrawSpring()
{
    float x1, y1, x2, y2, w, h, r;

    x1 = m_Point.x() - 50;
    y1 = m_Point.y();
    x2 = m_Point.x() + 50;
    y2 = m_Point.y();
    m_painter->drawLine(x1, y1, x2, y2);
    x1 = m_Point.x();
    y1 += m_LUp * m_k;
    m_painter->drawLine(QPoint(m_Point), QPoint(x1, y1));

    w = m_w * m_k;
    h = m_L * m_k;
    x1 -= w / 2;
    m_painter->drawRect(x1, y1, w, h);

    x1 = m_Point.x();
    y1 += m_L * m_k;
    x2 = x1;
    y2 = y1 + m_LDown * m_k;
    m_painter->drawLine(x1, y1, x2, y2);
    y1 = y2 + m_r * m_k;
    r = m_r * m_k;
    m_painter->drawEllipse(QPointF(x1, y1), r, r);
}

void SpringWidget::initCharts()
{
    m_series_y = new QSplineSeries(this);
    m_series_v = new QSplineSeries(this);
    m_series_a = new QSplineSeries(this);
    m_series_f = new QSplineSeries(this);

    m_chart_y = ui->graphicsView_y->chart();
    m_chart_v = ui->graphicsView_v->chart();
    m_chart_a = ui->graphicsView_a->chart();
    m_chart_f = ui->graphicsView_f->chart();

    m_chart_y->addSeries(m_series_y);
    m_chart_v->addSeries(m_series_v);
    m_chart_a->addSeries(m_series_a);
    m_chart_f->addSeries(m_series_f);

    m_chart_y->legend()->hide();
    m_chart_v->legend()->hide();
    m_chart_a->legend()->hide();
    m_chart_f->legend()->hide();

    m_chart_y->setTitle("位移（米）");
    m_chart_v->setTitle("速度（米/秒）");
    m_chart_a->setTitle("加速度（米/秒*秒）");
    m_chart_f->setTitle("受力（牛顿）");

    m_chart_y->createDefaultAxes();
    m_chart_v->createDefaultAxes();
    m_chart_a->createDefaultAxes();
    m_chart_f->createDefaultAxes();

    m_chart_y->axes(Qt::Horizontal).constLast()->setRange(0,10);
    m_chart_v->axes(Qt::Horizontal).constLast()->setRange(0,10);
    m_chart_a->axes(Qt::Horizontal).constLast()->setRange(0,10);
    m_chart_f->axes(Qt::Horizontal).constLast()->setRange(0,10);

    m_chart_y->axes(Qt::Vertical).constLast()->setRange(-0.18, 0.18);
    m_chart_v->axes(Qt::Vertical).constLast()->setRange(-1.5, 1.5);
    m_chart_a->axes(Qt::Vertical).constLast()->setRange(-5, 5);
    m_chart_f->axes(Qt::Vertical).constLast()->setRange(-4, 4);

    ui->graphicsView_y->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_v->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_a->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_f->setRenderHint(QPainter::Antialiasing);
}
