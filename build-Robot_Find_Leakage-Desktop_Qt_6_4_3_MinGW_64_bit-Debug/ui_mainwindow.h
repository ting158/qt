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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShow_LiZi;
    QAction *actionhideLiZi;
    QAction *actionmoveStart;
    QAction *actionmoveStop;
    QAction *actionleakgge_Start;
    QAction *actionleakage_Stop;
    QAction *actionShunYi;
    QAction *actionYunSu;
    QAction *actionZhuanQuan;
    QAction *actionLuJing;
    QAction *actionFindXieLou;
    QAction *actionStop;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionShow_LiZi = new QAction(MainWindow);
        actionShow_LiZi->setObjectName("actionShow_LiZi");
        actionhideLiZi = new QAction(MainWindow);
        actionhideLiZi->setObjectName("actionhideLiZi");
        actionmoveStart = new QAction(MainWindow);
        actionmoveStart->setObjectName("actionmoveStart");
        actionmoveStop = new QAction(MainWindow);
        actionmoveStop->setObjectName("actionmoveStop");
        actionleakgge_Start = new QAction(MainWindow);
        actionleakgge_Start->setObjectName("actionleakgge_Start");
        actionleakage_Stop = new QAction(MainWindow);
        actionleakage_Stop->setObjectName("actionleakage_Stop");
        actionShunYi = new QAction(MainWindow);
        actionShunYi->setObjectName("actionShunYi");
        actionYunSu = new QAction(MainWindow);
        actionYunSu->setObjectName("actionYunSu");
        actionZhuanQuan = new QAction(MainWindow);
        actionZhuanQuan->setObjectName("actionZhuanQuan");
        actionLuJing = new QAction(MainWindow);
        actionLuJing->setObjectName("actionLuJing");
        actionFindXieLou = new QAction(MainWindow);
        actionFindXieLou->setObjectName("actionFindXieLou");
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName("actionStop");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionShow_LiZi);
        menu->addAction(actionhideLiZi);
        menu_2->addAction(actionmoveStart);
        menu_2->addAction(actionmoveStop);
        menu_3->addAction(actionleakgge_Start);
        menu_3->addAction(actionleakage_Stop);
        menu_4->addAction(actionShunYi);
        menu_4->addAction(actionYunSu);
        menu_4->addAction(actionZhuanQuan);
        menu_4->addAction(actionLuJing);
        menu_4->addAction(actionFindXieLou);
        menu_4->addAction(actionStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionShow_LiZi->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272", nullptr));
        actionhideLiZi->setText(QCoreApplication::translate("MainWindow", "\351\232\220\350\227\217", nullptr));
        actionmoveStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        actionmoveStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        actionleakgge_Start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        actionleakage_Stop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        actionShunYi->setText(QCoreApplication::translate("MainWindow", "\347\236\254\347\247\273", nullptr));
        actionYunSu->setText(QCoreApplication::translate("MainWindow", "\345\214\200\351\200\237", nullptr));
        actionZhuanQuan->setText(QCoreApplication::translate("MainWindow", "\350\275\254\345\234\210", nullptr));
        actionLuJing->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204\350\247\204\345\210\222", nullptr));
        actionFindXieLou->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\346\263\204\346\274\217\347\202\271", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "\351\235\231\346\255\242", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\262\222\345\255\220", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\263\204\351\234\262", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\345\260\217\350\275\246\350\277\220\345\212\250\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
