#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphical.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);


    Graphical m_gra;
    QPainter * m_painter;
    QPoint m_mousePress;
    QPoint m_mouseRelease;

    bool m_isMousePress;

private slots:
    void on_actionCricle_triggered();

    void on_actionRectangle_triggered();

    void on_actionDraw_triggered();

    void on_actionMove_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
