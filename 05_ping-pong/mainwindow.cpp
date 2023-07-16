#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(&m_form,SIGNAL(CanShuSignal_xy(float,float)),SLOT(CanShuSlot_xy(float,float)));
//    connect(&m_form,SIGNAL(CanShuSignal_vxvy(float,float)),SLOT(CanShuSlot_vxvy(float,float)));

    connect(&m_form, &FormCanShu::CanShuSignal_xy, this, &MainWindow::CanShuSlot_xy);
    connect(&m_form, &FormCanShu::CanShuSignal_vxvy, this, &MainWindow::CanShuSlot_vxvy);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CanShuSlot_xy(float x, float y)
{
    qDebug().nospace() << "x = " << x << ", " << "y = " << y;
}

void MainWindow::CanShuSlot_vxvy(float vx, float vy)
{
    qDebug().nospace() << "vx = " << vx << ", " << "vy = " << vy;
}


void MainWindow::on_pushButton_clicked()
{
    m_form.show();
}

