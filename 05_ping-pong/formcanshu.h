#ifndef FORMCANSHU_H
#define FORMCANSHU_H

#include <QWidget>

namespace Ui {
class FormCanShu;
}

class FormCanShu : public QWidget
{
    Q_OBJECT

public:
    explicit FormCanShu(QWidget *parent = nullptr);
    ~FormCanShu();

signals:
    void CanShuSignal_xy(float, float);
    void CanShuSignal_vxvy(float, float);

private slots:
    void on_pushButton_xy_clicked();

    void on_pushButton_vxvy_clicked();

private:
    Ui::FormCanShu *ui;
};

#endif // FORMCANSHU_H
