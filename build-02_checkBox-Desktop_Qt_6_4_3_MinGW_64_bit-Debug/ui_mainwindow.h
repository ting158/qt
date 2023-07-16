/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_str1;
    QLineEdit *lineEdit_str2;
    QLineEdit *lineEdit_str3;
    QLineEdit *lineEdit_merge;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(350, 190, 164, 117));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEdit_str1 = new QLineEdit(widget_2);
        lineEdit_str1->setObjectName("lineEdit_str1");

        verticalLayout_2->addWidget(lineEdit_str1);

        lineEdit_str2 = new QLineEdit(widget_2);
        lineEdit_str2->setObjectName("lineEdit_str2");

        verticalLayout_2->addWidget(lineEdit_str2);

        lineEdit_str3 = new QLineEdit(widget_2);
        lineEdit_str3->setObjectName("lineEdit_str3");

        verticalLayout_2->addWidget(lineEdit_str3);

        lineEdit_merge = new QLineEdit(centralwidget);
        lineEdit_merge->setObjectName("lineEdit_merge");
        lineEdit_merge->setGeometry(QRect(360, 330, 141, 27));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(90, 200, 128, 139));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName("checkBox_3");

        verticalLayout->addWidget(checkBox_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_str1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lineEdit_str2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        lineEdit_str3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\350\277\275\345\212\2401", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\350\277\275\345\212\2402", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "\350\277\275\345\212\2403", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
