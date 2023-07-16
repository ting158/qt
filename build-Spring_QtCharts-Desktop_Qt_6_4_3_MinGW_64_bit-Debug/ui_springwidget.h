/********************************************************************************
** Form generated from reading UI file 'springwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRINGWIDGET_H
#define UI_SPRINGWIDGET_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpringWidget
{
public:
    QChartView *graphicsView_y;
    QChartView *graphicsView_v;
    QChartView *graphicsView_a;
    QChartView *graphicsView_f;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_restart;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_m;
    QLabel *label_2;
    QLineEdit *lineEdit_kSpring;
    QPushButton *pushButton_save;
    QLabel *label_3;
    QLineEdit *lineEdit_damping;

    void setupUi(QWidget *SpringWidget)
    {
        if (SpringWidget->objectName().isEmpty())
            SpringWidget->setObjectName("SpringWidget");
        SpringWidget->resize(1138, 700);
        graphicsView_y = new QChartView(SpringWidget);
        graphicsView_y->setObjectName("graphicsView_y");
        graphicsView_y->setGeometry(QRect(460, 30, 300, 300));
        graphicsView_v = new QChartView(SpringWidget);
        graphicsView_v->setObjectName("graphicsView_v");
        graphicsView_v->setGeometry(QRect(760, 30, 300, 300));
        graphicsView_a = new QChartView(SpringWidget);
        graphicsView_a->setObjectName("graphicsView_a");
        graphicsView_a->setGeometry(QRect(460, 330, 300, 300));
        graphicsView_f = new QChartView(SpringWidget);
        graphicsView_f->setObjectName("graphicsView_f");
        graphicsView_f->setGeometry(QRect(760, 330, 300, 300));
        widget = new QWidget(SpringWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 10, 276, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_start = new QPushButton(widget);
        pushButton_start->setObjectName("pushButton_start");

        horizontalLayout->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(widget);
        pushButton_stop->setObjectName("pushButton_stop");

        horizontalLayout->addWidget(pushButton_stop);

        pushButton_restart = new QPushButton(widget);
        pushButton_restart->setObjectName("pushButton_restart");

        horizontalLayout->addWidget(pushButton_restart);

        groupBox = new QGroupBox(SpringWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(60, 530, 324, 146));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_m = new QLineEdit(groupBox);
        lineEdit_m->setObjectName("lineEdit_m");

        gridLayout->addWidget(lineEdit_m, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_kSpring = new QLineEdit(groupBox);
        lineEdit_kSpring->setObjectName("lineEdit_kSpring");

        gridLayout->addWidget(lineEdit_kSpring, 1, 1, 1, 1);

        pushButton_save = new QPushButton(groupBox);
        pushButton_save->setObjectName("pushButton_save");

        gridLayout->addWidget(pushButton_save, 1, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_damping = new QLineEdit(groupBox);
        lineEdit_damping->setObjectName("lineEdit_damping");

        gridLayout->addWidget(lineEdit_damping, 2, 1, 1, 1);


        retranslateUi(SpringWidget);

        QMetaObject::connectSlotsByName(SpringWidget);
    } // setupUi

    void retranslateUi(QWidget *SpringWidget)
    {
        SpringWidget->setWindowTitle(QCoreApplication::translate("SpringWidget", "SpringWidget", nullptr));
        pushButton_start->setText(QCoreApplication::translate("SpringWidget", "\345\274\200\345\247\213", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("SpringWidget", "\346\232\202\345\201\234", nullptr));
        pushButton_restart->setText(QCoreApplication::translate("SpringWidget", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SpringWidget", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("SpringWidget", "\345\260\217\347\220\203\350\264\250\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("SpringWidget", "\345\274\271\346\200\247\347\263\273\346\225\260", nullptr));
        pushButton_save->setText(QCoreApplication::translate("SpringWidget", "\344\277\235\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("SpringWidget", "\351\230\273\345\260\274\347\263\273\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpringWidget: public Ui_SpringWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRINGWIDGET_H
