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
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Restart;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName("GameWidget");
        GameWidget->resize(800, 631);
        widget = new QWidget(GameWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(640, 400, 102, 120));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_Start = new QPushButton(widget);
        pushButton_Start->setObjectName("pushButton_Start");

        verticalLayout->addWidget(pushButton_Start);

        pushButton_Stop = new QPushButton(widget);
        pushButton_Stop->setObjectName("pushButton_Stop");

        verticalLayout->addWidget(pushButton_Stop);

        pushButton_Restart = new QPushButton(widget);
        pushButton_Restart->setObjectName("pushButton_Restart");

        verticalLayout->addWidget(pushButton_Restart);


        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "GameWidget", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("GameWidget", "\345\274\200\345\247\213", nullptr));
        pushButton_Stop->setText(QCoreApplication::translate("GameWidget", "\346\232\202\345\201\234", nullptr));
        pushButton_Restart->setText(QCoreApplication::translate("GameWidget", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
