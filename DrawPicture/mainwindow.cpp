#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_isMousePress = false;
    m_painter = new QPainter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_isMousePress = true;

    if (m_isMousePress)
    {
        m_mousePress = event->pos();

        if (m_gra.m_modeType == DRAW)
            m_gra.SetOpt("绘制");

        if (m_gra.m_modeType == MOVE)
        {
            m_gra.m_indexChoose = m_gra.GetIndexChoosingGraphical(event->pos());
        }
    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_isMousePress = false;

    if (m_isMousePress == false)
    {
        if (m_gra.m_modeType == DRAW)
        {
            m_gra.SaveGraphical(m_mousePress, event->pos());


            m_gra.SetOpt("无操作");
        }

        if (m_gra.m_modeType == MOVE)
        {
            m_gra.OverMove();
        }

        m_gra.DeleteTempGraphical();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isMousePress)
    {
        if (m_gra.m_modeType == DRAW)
        {
            m_gra.SaveTempGraphical(m_mousePress, event->pos());
        }
        if (m_gra.m_modeType == MOVE)
        {
            m_gra.MoveGraphical(m_mousePress, event->pos());
        }
    }

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);

    m_gra.Draw(m_painter);

    m_painter->end();

    update();
}


void MainWindow::on_actionCricle_triggered()
{
    m_gra.m_graphicalType = CIRCLE;
}


void MainWindow::on_actionRectangle_triggered()
{
    m_gra.m_graphicalType = RECTANGLE;
}


void MainWindow::on_actionDraw_triggered()
{
    m_gra.m_modeType = DRAW;
    m_gra.m_graphicalType = CIRCLE;

    m_gra.m_optDraw = "绘制模式";
}


void MainWindow::on_actionMove_triggered()
{
    m_gra.m_modeType = MOVE;

    m_gra.m_optDraw = "选择的图形：未选择";
}

