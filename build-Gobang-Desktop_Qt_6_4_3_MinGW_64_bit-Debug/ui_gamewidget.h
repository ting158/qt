/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QPushButton *pushButton_restart;
    QLabel *label;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName("GameWidget");
        GameWidget->resize(700, 600);
        GameWidget->setMinimumSize(QSize(700, 600));
        GameWidget->setMaximumSize(QSize(700, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GameWidget->setWindowIcon(icon);
        pushButton_restart = new QPushButton(GameWidget);
        pushButton_restart->setObjectName("pushButton_restart");
        pushButton_restart->setGeometry(QRect(610, 510, 81, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_restart->setIcon(icon1);
        pushButton_restart->setIconSize(QSize(60, 60));
        pushButton_restart->setFlat(true);
        label = new QLabel(GameWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(600, 470, 131, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267")});
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "\344\272\224\345\255\220\346\243\213", nullptr));
        pushButton_restart->setText(QString());
        label->setText(QCoreApplication::translate("GameWidget", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
