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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_restart;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName("GameWidget");
        GameWidget->resize(1000, 600);
        GameWidget->setMinimumSize(QSize(1000, 600));
        GameWidget->setMaximumSize(QSize(1000, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        GameWidget->setWindowIcon(icon);
        layoutWidget = new QWidget(GameWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(870, 70, 95, 277));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_start = new QPushButton(layoutWidget);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_start->setIcon(icon1);
        pushButton_start->setIconSize(QSize(80, 80));
        pushButton_start->setFlat(true);

        verticalLayout->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(layoutWidget);
        pushButton_stop->setObjectName("pushButton_stop");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon2);
        pushButton_stop->setIconSize(QSize(80, 80));
        pushButton_stop->setFlat(true);

        verticalLayout->addWidget(pushButton_stop);

        pushButton_restart = new QPushButton(layoutWidget);
        pushButton_restart->setObjectName("pushButton_restart");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_restart->setIcon(icon3);
        pushButton_restart->setIconSize(QSize(80, 80));
        pushButton_restart->setFlat(true);

        verticalLayout->addWidget(pushButton_restart);


        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "\350\264\252\345\220\203\350\233\207", nullptr));
        pushButton_start->setText(QString());
        pushButton_stop->setText(QString());
        pushButton_restart->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
