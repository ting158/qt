/********************************************************************************
** Form generated from reading UI file 'springmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRINGMAINWINDOW_H
#define UI_SPRINGMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpringMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SpringMainWindow)
    {
        if (SpringMainWindow->objectName().isEmpty())
            SpringMainWindow->setObjectName("SpringMainWindow");
        SpringMainWindow->resize(800, 600);
        centralwidget = new QWidget(SpringMainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setGeometry(QRect(70, 400, 92, 28));
        SpringMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SpringMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        SpringMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SpringMainWindow);
        statusbar->setObjectName("statusbar");
        SpringMainWindow->setStatusBar(statusbar);

        retranslateUi(SpringMainWindow);

        QMetaObject::connectSlotsByName(SpringMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpringMainWindow)
    {
        SpringMainWindow->setWindowTitle(QCoreApplication::translate("SpringMainWindow", "SpringMainWindow", nullptr));
        pushButton_start->setText(QCoreApplication::translate("SpringMainWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpringMainWindow: public Ui_SpringMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRINGMAINWINDOW_H
