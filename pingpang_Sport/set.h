#ifndef SET_H
#define SET_H

#include <QWidget>

namespace Ui {
class Set;
}

class Set : public QWidget
{
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);
    ~Set();

    void showDateToLineEdit(float x, float y, float z, float vx, float vy, float vz);

signals:
    void sandDate(float x, float y, float z, float vx, float vy, float vz);
    void stop();

private slots:
    void on_pushButton_OK_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::Set *ui;
};

#endif // SET_H
