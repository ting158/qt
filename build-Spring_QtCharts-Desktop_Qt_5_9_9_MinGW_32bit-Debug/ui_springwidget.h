/********************************************************************************
** Form generated from reading UI file 'springwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRINGWIDGET_H
#define UI_SPRINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <qchartview.h>

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
            SpringWidget->setObjectName(QStringLiteral("SpringWidget"));
        SpringWidget->resize(1138, 700);
        graphicsView_y = new QChartView(SpringWidget);
        graphicsView_y->setObjectName(QStringLiteral("graphicsView_y"));
        graphicsView_y->setGeometry(QRect(460, 30, 300, 300));
        graphicsView_v = new QChartView(SpringWidget);
        graphicsView_v->setObjectName(QStringLiteral("graphicsView_v"));
        graphicsView_v->setGeometry(QRect(760, 30, 300, 300));
        graphicsView_a = new QChartView(SpringWidget);
        graphicsView_a->setObjectName(QStringLiteral("graphicsView_a"));
        graphicsView_a->setGeometry(QRect(460, 330, 300, 300));
        graphicsView_f = new QChartView(SpringWidget);
        graphicsView_f->setObjectName(QStringLiteral("graphicsView_f"));
        graphicsView_f->setGeometry(QRect(760, 330, 300, 300));
        widget = new QWidget(SpringWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 10, 276, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_start = new QPushButton(widget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));

        horizontalLayout->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(widget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));

        horizontalLayout->addWidget(pushButton_stop);

        pushButton_restart = new QPushButton(widget);
        pushButton_restart->setObjectName(QStringLiteral("pushButton_restart"));

        horizontalLayout->addWidget(pushButton_restart);

        groupBox = new QGroupBox(SpringWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 530, 324, 146));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_m = new QLineEdit(groupBox);
        lineEdit_m->setObjectName(QStringLiteral("lineEdit_m"));

        gridLayout->addWidget(lineEdit_m, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_kSpring = new QLineEdit(groupBox);
        lineEdit_kSpring->setObjectName(QStringLiteral("lineEdit_kSpring"));

        gridLayout->addWidget(lineEdit_kSpring, 1, 1, 1, 1);

        pushButton_save = new QPushButton(groupBox);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        gridLayout->addWidget(pushButton_save, 1, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_damping = new QLineEdit(groupBox);
        lineEdit_damping->setObjectName(QStringLiteral("lineEdit_damping"));

        gridLayout->addWidget(lineEdit_damping, 2, 1, 1, 1);


        retranslateUi(SpringWidget);

        QMetaObject::connectSlotsByName(SpringWidget);
    } // setupUi

    void retranslateUi(QWidget *SpringWidget)
    {
        SpringWidget->setWindowTitle(QApplication::translate("SpringWidget", "SpringWidget", Q_NULLPTR));
        pushButton_start->setText(QApplication::translate("SpringWidget", "\345\274\200\345\247\213", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("SpringWidget", "\346\232\202\345\201\234", Q_NULLPTR));
        pushButton_restart->setText(QApplication::translate("SpringWidget", "\351\207\215\346\226\260\345\274\200\345\247\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SpringWidget", "\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("SpringWidget", "\345\260\217\347\220\203\350\264\250\351\207\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("SpringWidget", "\345\274\271\346\200\247\347\263\273\346\225\260", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("SpringWidget", "\344\277\235\345\255\230", Q_NULLPTR));
        label_3->setText(QApplication::translate("SpringWidget", "\351\230\273\345\260\274\347\263\273\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SpringWidget: public Ui_SpringWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRINGWIDGET_H
