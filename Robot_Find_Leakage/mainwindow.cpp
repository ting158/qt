#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWheelEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_painter = new QPainter();

    m_timer_CreateLiZi = startTimer(100);
    m_timer_Move = startTimer(100);
    m_timer_CreateLiZi_Start = false;
    m_timer_Move_Start = false;

    connect(&m_set, &SetZhuanQuanForm::sandToSetCar, this, &MainWindow::setFromDlg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    m_painter->begin(this);

    m_scene.Draw(m_painter);
    m_car.Draw(m_painter);
    m_wrj.Draw(m_painter);

    m_painter->end();

    update();
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    // 获取滚轮滚动的角度和滚动方向
    int delta = event->angleDelta().y();

    if (delta > 0)  //放大
    {
        m_scene.m_kx *= 1.2;
        m_scene.m_ky *= 1.2;
        m_car.m_kx = m_scene.m_kx;
        m_car.m_ky = m_scene.m_ky;
        m_wrj.m_kx = m_scene.m_kx;
        m_wrj.m_ky = m_scene.m_ky;
    }
    if (delta < 0)  //缩小
    {
        m_scene.m_kx *= 0.8;
        m_scene.m_ky *= 0.8;
        m_car.m_kx = m_scene.m_kx;
        m_car.m_ky = m_scene.m_ky;
        m_wrj.m_kx = m_scene.m_kx;
        m_wrj.m_ky = m_scene.m_ky;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_bjLBD = true;

    if (m_bjLBD)
    {
        m_LBD.x = event->pos().x();
        m_LBD.y = event->pos().y();
        m_tempYD = m_scene.m_YD;

        this->ChuLiLBD();

        m_car.ZhuanHuaMuBiaoDian(event->pos());

        if (m_car.m_bjCreate == 1)
            m_car.ChuLiGuiJiZuoBiao(event->pos());
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_car.ZhuanHuaMuBiaoDian(event->pos());
    m_car.m_bjCreate = 0;
    m_timer_Move_Start = true;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bjLBD)
    {
        m_scene.m_YD.x = m_tempYD.x + event->pos().x() - m_LBD.x;
        m_scene.m_YD.y = m_tempYD.y + event->pos().y() - m_LBD.y;

        m_car.m_YD.x = m_scene.m_YD.x;
        m_car.m_YD.y = m_scene.m_YD.y;

        m_wrj.m_YD.x = m_scene.m_YD.x;
        m_wrj.m_YD.y = m_scene.m_YD.y;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_bjLBD = false;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timer_CreateLiZi && m_timer_CreateLiZi_Start)
    {
        m_scene.CreateLiZi();
        m_scene.MoveLiZi();
        m_car.m_nd = m_scene.QiuNongDu(m_car.m_x, m_car.m_y);
        m_wrj.m_nd = m_scene.QiuNongDu(m_wrj.m_x, m_wrj.m_y);
        m_wrj.LuoXuanJiangXuanZhuan();
    }
    if (event->timerId() == m_timer_Move && m_timer_Move_Start)
    {
        m_car.Move();

        if (m_car.isOverLuJing() == 1 && m_car.m_mode == LuJing)
            m_timer_Move_Start = false;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    m_wrj.Move(event->key());
}

void MainWindow::ChuLiLBD()
{
    float x, y;

    x = (m_LBD.x - m_scene.m_YD.x) / m_scene.m_kx;
    y = (m_LBD.y - m_scene.m_YD.y) / m_scene.m_ky;

    m_scene.m_nd = m_scene.QiuNongDu(x, y);
}


void MainWindow::on_actionShow_LiZi_triggered()
{
    m_scene.m_flag_drawlz = true;
}


void MainWindow::on_actionhideLiZi_triggered()
{
    m_scene.m_flag_drawlz = false;
}


void MainWindow::on_actionleakgge_Start_triggered()
{
    m_scene.m_XLDx = rand() % (477 + 310 + 1) - 310;
    m_scene.m_XLDy = rand() % (686 + 100 + 1) - 100;
    m_timer_CreateLiZi_Start = true;
}


void MainWindow::on_actionleakage_Stop_triggered()
{
    m_timer_CreateLiZi_Start = false;
}


void MainWindow::on_actionShunYi_triggered()
{
    m_car.m_mode = ShunYi;

    m_timer_Move_Start = false;
}


void MainWindow::on_actionYunSu_triggered()
{
    m_car.m_mode = YunSu;

    m_timer_Move_Start = false;
}


void MainWindow::on_actionZhuanQuan_triggered()
{
    m_car.m_mode = ZhuanQuan;

    emit m_set.setLineEdit(m_car.m_r, m_car.m_vJD, m_car.m_dir, m_car.m_sn);
    m_set.show();

    m_timer_Move_Start = false;
}


void MainWindow::on_actionLuJing_triggered()
{
    m_car.m_mode = LuJing;
    m_car.m_bjCreate = 1;
    m_car.m_nowMB = 1;

    m_timer_Move_Start = false;
}


void MainWindow::on_actionFindXieLou_triggered()
{
    m_car.m_mode = FindXieLou;

    m_car.initCircleNDTest();

    m_timer_Move_Start = false;
}


void MainWindow::on_actionStop_triggered()
{
    m_car.m_mode = -1;
}


void MainWindow::on_actionmoveStart_triggered()
{
    m_timer_Move_Start = true;
}


void MainWindow::on_actionmoveStop_triggered()
{
    m_timer_Move_Start = false;
}

void MainWindow::setFromDlg(float r, float vJD, float dir, int sn)
{
    m_car.m_r = r;
    m_car.m_vJD = vJD;
    m_car.m_dir = dir;
    m_car.m_sn = sn;

    m_car.ChuLiYuanXinCanShu();

    m_timer_Move_Start = true;
}

