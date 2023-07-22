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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(902, 571);
        actionShow_LiZi = new QAction(MainWindow);
        actionShow_LiZi->setObjectName(QStringLiteral("actionShow_LiZi"));
        actionhideLiZi = new QAction(MainWindow);
        actionhideLiZi->setObjectName(QStringLiteral("actionhideLiZi"));
        actionmoveStart = new QAction(MainWindow);
        actionmoveStart->setObjectName(QStringLiteral("actionmoveStart"));
        actionmoveStop = new QAction(MainWindow);
        actionmoveStop->setObjectName(QStringLiteral("actionmoveStop"));
        actionleakgge_Start = new QAction(MainWindow);
        actionleakgge_Start->setObjectName(QStringLiteral("actionleakgge_Start"));
        actionleakage_Stop = new QAction(MainWindow);
        actionleakage_Stop->setObjectName(QStringLiteral("actionleakage_Stop"));
        actionShunYi = new QAction(MainWindow);
        actionShunYi->setObjectName(QStringLiteral("actionShunYi"));
        actionYunSu = new QAction(MainWindow);
        actionYunSu->setObjectName(QStringLiteral("actionYunSu"));
        actionZhuanQuan = new QAction(MainWindow);
        actionZhuanQuan->setObjectName(QStringLiteral("actionZhuanQuan"));
        actionLuJing = new QAction(MainWindow);
        actionLuJing->setObjectName(QStringLiteral("actionLuJing"));
        actionFindXieLou = new QAction(MainWindow);
        actionFindXieLou->setObjectName(QStringLiteral("actionFindXieLou"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 902, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionShow_LiZi->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272", Q_NULLPTR));
        actionhideLiZi->setText(QApplication::translate("MainWindow", "\351\232\220\350\227\217", Q_NULLPTR));
        actionmoveStart->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        actionmoveStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        actionleakgge_Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        actionleakage_Stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", Q_NULLPTR));
        actionShunYi->setText(QApplication::translate("MainWindow", "\347\236\254\347\247\273", Q_NULLPTR));
        actionYunSu->setText(QApplication::translate("MainWindow", "\345\214\200\351\200\237", Q_NULLPTR));
        actionZhuanQuan->setText(QApplication::translate("MainWindow", "\350\275\254\345\234\210", Q_NULLPTR));
        actionLuJing->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204\350\247\204\345\210\222", Q_NULLPTR));
        actionFindXieLou->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\346\263\204\346\274\217\347\202\271", Q_NULLPTR));
        actionStop->setText(QApplication::translate("MainWindow", "\351\235\231\346\255\242", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\347\262\222\345\255\220", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\277\220\345\212\250", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\263\204\351\234\262", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\260\217\350\275\246\350\277\220\345\212\250\346\250\241\345\274\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
