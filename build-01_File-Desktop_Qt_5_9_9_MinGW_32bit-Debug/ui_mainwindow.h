/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *btn_saveToFile;
    QPushButton *btn_toTab2;
    QLineEdit *lineEdit_tab1;
    QWidget *tab_2;
    QLineEdit *lineEdit_tab2;
    QPushButton *btn_open;
    QPushButton *btn_save;
    QPushButton *btn_openForChinese;
    QLineEdit *lineEdit_openChinese;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1030, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(70, 40, 371, 461));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        btn_saveToFile = new QPushButton(tab);
        btn_saveToFile->setObjectName(QStringLiteral("btn_saveToFile"));
        btn_saveToFile->setGeometry(QRect(211, 80, 121, 28));
        btn_toTab2 = new QPushButton(tab);
        btn_toTab2->setObjectName(QStringLiteral("btn_toTab2"));
        btn_toTab2->setGeometry(QRect(220, 180, 92, 28));
        lineEdit_tab1 = new QLineEdit(tab);
        lineEdit_tab1->setObjectName(QStringLiteral("lineEdit_tab1"));
        lineEdit_tab1->setGeometry(QRect(40, 80, 113, 27));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEdit_tab2 = new QLineEdit(tab_2);
        lineEdit_tab2->setObjectName(QStringLiteral("lineEdit_tab2"));
        lineEdit_tab2->setGeometry(QRect(70, 140, 113, 27));
        tabWidget->addTab(tab_2, QString());
        btn_open = new QPushButton(centralwidget);
        btn_open->setObjectName(QStringLiteral("btn_open"));
        btn_open->setGeometry(QRect(600, 50, 92, 28));
        btn_save = new QPushButton(centralwidget);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(790, 50, 92, 28));
        btn_openForChinese = new QPushButton(centralwidget);
        btn_openForChinese->setObjectName(QStringLiteral("btn_openForChinese"));
        btn_openForChinese->setGeometry(QRect(830, 450, 131, 28));
        lineEdit_openChinese = new QLineEdit(centralwidget);
        lineEdit_openChinese->setObjectName(QStringLiteral("lineEdit_openChinese"));
        lineEdit_openChinese->setGeometry(QRect(620, 450, 171, 27));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(600, 120, 311, 261));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1030, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_saveToFile->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\210\260\346\226\207\346\234\254\346\226\207\344\273\266", Q_NULLPTR));
        btn_toTab2->setText(QApplication::translate("MainWindow", "\344\274\240\351\200\222\345\210\260Tab2", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        btn_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
        btn_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        btn_openForChinese->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207\350\267\257\345\276\204\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
