#ifndef SPRINGWIDGET_H
#define SPRINGWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class SpringWidget : public QWidget
{
    Q_OBJECT

public:
    SpringWidget(QWidget *parent = nullptr);
    ~SpringWidget();

private:
    Ui::Widget *ui;
};
#endif // SPRINGWIDGET_H
