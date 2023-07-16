#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_Group = new QButtonGroup(this);
    m_Group->addButton(ui->radioButton_add,1);
    m_Group->addButton(ui->radioButton_reduce,2);
    m_Group->addButton(ui->radioButton_mul,3);
    m_Group->addButton(ui->radioButton_div,4);

    connect(m_Group, &QButtonGroup::buttonClicked, this, [=](){
        if (ui->radioButton_add->isChecked())
        {
            m_result = m_x + m_y;
            qDebug() << m_x << "+" << m_y << "=" << m_result;
        }
        if(ui->radioButton_reduce->isChecked())
        {
            m_result = m_x - m_y;
            qDebug() << m_x << "-" << m_y << "=" << m_result;
        }

        if(ui->radioButton_mul->isChecked())
        {
            m_result = m_x * m_y;
            qDebug() << m_x << "*" << m_y << "=" << m_result;
        }

        if(ui->radioButton_div->isChecked())
        {
            m_result = m_x / m_y;
            qDebug() << m_x << "/" << m_y << "=" << m_result;
        }

    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
