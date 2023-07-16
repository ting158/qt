/********************************************************************************
** Form generated from reading UI file 'springmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRINGMAINWINDOW_H
#define UI_SPRINGMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            SpringMainWindow->setObjectName(QStringLiteral("SpringMainWindow"));
        SpringMainWindow->resize(1213, 600);
        centralwidget = new QWidget(SpringMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(70, 400, 92, 28));
        SpringMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SpringMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1213, 24));
        SpringMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SpringMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SpringMainWindow->setStatusBar(statusbar);

        retranslateUi(SpringMainWindow);

        QMetaObject::connectSlotsByName(SpringMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpringMainWindow)
    {
        SpringMainWindow->setWindowTitle(QApplication::translate("SpringMainWindow", "SpringMainWindow", Q_NULLPTR));
        pushButton_start->setText(QApplication::translate("SpringMainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SpringMainWindow: public Ui_SpringMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRINGMAINWINDOW_H
