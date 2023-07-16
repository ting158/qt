/********************************************************************************
** Form generated from reading UI file 'formcanshu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCANSHU_H
#define UI_FORMCANSHU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCanShu
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_y;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_x;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_xy;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QLineEdit *lineEdit_vx;
    QLabel *label_4;
    QLineEdit *lineEdit_vy;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton_vxvy;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FormCanShu)
    {
        if (FormCanShu->objectName().isEmpty())
            FormCanShu->setObjectName("FormCanShu");
        FormCanShu->resize(569, 389);
        horizontalLayout = new QHBoxLayout(FormCanShu);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(FormCanShu);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit_y = new QLineEdit(widget);
        lineEdit_y->setObjectName("lineEdit_y");

        gridLayout->addWidget(lineEdit_y, 3, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        lineEdit_x = new QLineEdit(widget);
        lineEdit_x->setObjectName("lineEdit_x");

        gridLayout->addWidget(lineEdit_x, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        pushButton_xy = new QPushButton(widget);
        pushButton_xy->setObjectName("pushButton_xy");

        gridLayout->addWidget(pushButton_xy, 5, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 6, 1, 1, 1);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(FormCanShu);
        widget_2->setObjectName("widget_2");
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_vx = new QLineEdit(widget_2);
        lineEdit_vx->setObjectName("lineEdit_vx");

        gridLayout_2->addWidget(lineEdit_vx, 1, 1, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_vy = new QLineEdit(widget_2);
        lineEdit_vy->setObjectName("lineEdit_vy");

        gridLayout_2->addWidget(lineEdit_vy, 3, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 1, 1, 1);

        pushButton_vxvy = new QPushButton(widget_2);
        pushButton_vxvy->setObjectName("pushButton_vxvy");

        gridLayout_2->addWidget(pushButton_vxvy, 5, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 4, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 6, 1, 1, 1);


        horizontalLayout->addWidget(widget_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(FormCanShu);

        QMetaObject::connectSlotsByName(FormCanShu);
    } // setupUi

    void retranslateUi(QWidget *FormCanShu)
    {
        FormCanShu->setWindowTitle(QCoreApplication::translate("FormCanShu", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormCanShu", "x\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("FormCanShu", "y\357\274\232", nullptr));
        pushButton_xy->setText(QCoreApplication::translate("FormCanShu", "\350\256\276\347\275\256x, y", nullptr));
        label_3->setText(QCoreApplication::translate("FormCanShu", "vx\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FormCanShu", "vy\357\274\232", nullptr));
        pushButton_vxvy->setText(QCoreApplication::translate("FormCanShu", "\350\256\276\347\275\256vx, vy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCanShu: public Ui_FormCanShu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCANSHU_H
