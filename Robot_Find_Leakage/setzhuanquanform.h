#ifndef SETZHUANQUANFORM_H
#define SETZHUANQUANFORM_H

#include <QWidget>

namespace Ui {
class SetZhuanQuanForm;
}

class SetZhuanQuanForm : public QWidget
{
    Q_OBJECT

public:
    explicit SetZhuanQuanForm(QWidget *parent = nullptr);
    ~SetZhuanQuanForm();

    float m_r;
    float m_vJD;
    float m_dir;
    float m_sn;

signals:
    void setLineEdit(float, float, float, int);
    void sandToSetCar(float, float, float, int);

private slots:
    void receiveParameter(float r, float vJD, float dir, int sn);

    void on_pushButton_ok_clicked();

private:
    Ui::SetZhuanQuanForm *ui;
};

#endif // SETZHUANQUANFORM_H
