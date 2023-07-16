#include "springwidget.h"
#include "ui_widget.h"
#include "QTimer"

SpringWidget::SpringWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

SpringWidget::~SpringWidget()
{
    delete ui;
}

void SpringWidget::paintEvent(QPaintEvent *event)
{

}

