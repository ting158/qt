/********************************************************************************
** Form generated from reading UI file 'setzhuanquanform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETZHUANQUANFORM_H
#define UI_SETZHUANQUANFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetZhuanQuanForm
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_r;
    QLineEdit *lineEdit_dir;
    QLabel *label_4;
    QLineEdit *lineEdit_vJD;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_sn;
    QLabel *label;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *SetZhuanQuanForm)
    {
        if (SetZhuanQuanForm->objectName().isEmpty())
            SetZhuanQuanForm->setObjectName(QStringLiteral("SetZhuanQuanForm"));
        SetZhuanQuanForm->resize(588, 440);
        widget = new QWidget(SetZhuanQuanForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 110, 405, 151));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_r = new QLineEdit(widget);
        lineEdit_r->setObjectName(QStringLiteral("lineEdit_r"));

        gridLayout->addWidget(lineEdit_r, 0, 1, 1, 1);

        lineEdit_dir = new QLineEdit(widget);
        lineEdit_dir->setObjectName(QStringLiteral("lineEdit_dir"));

        gridLayout->addWidget(lineEdit_dir, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_vJD = new QLineEdit(widget);
        lineEdit_vJD->setObjectName(QStringLiteral("lineEdit_vJD"));
        lineEdit_vJD->setEnabled(true);

        gridLayout->addWidget(lineEdit_vJD, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_sn = new QLineEdit(widget);
        lineEdit_sn->setObjectName(QStringLiteral("lineEdit_sn"));

        gridLayout->addWidget(lineEdit_sn, 3, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_ok = new QPushButton(SetZhuanQuanForm);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(400, 320, 92, 28));

        retranslateUi(SetZhuanQuanForm);

        QMetaObject::connectSlotsByName(SetZhuanQuanForm);
    } // setupUi

    void retranslateUi(QWidget *SetZhuanQuanForm)
    {
        SetZhuanQuanForm->setWindowTitle(QApplication::translate("SetZhuanQuanForm", "Form", Q_NULLPTR));
        label_4->setText(QApplication::translate("SetZhuanQuanForm", "\350\275\254\345\212\250\346\226\271\345\220\221\357\274\2101\351\200\206\346\227\266\351\222\210\357\274\214-1\351\241\272\346\227\266\351\222\210\357\274\211\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("SetZhuanQuanForm", "\345\260\217\350\275\246\347\233\270\345\257\271\345\234\206\345\277\203\346\226\271\345\220\221\357\274\210\347\202\271\351\222\237\357\274\211\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("SetZhuanQuanForm", "\350\247\222\351\200\237\345\272\246\357\274\210\302\260/s\357\274\211\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("SetZhuanQuanForm", "\346\227\213\350\275\254\345\215\212\345\276\204\357\274\210m\357\274\211\357\274\232", Q_NULLPTR));
        pushButton_ok->setText(QApplication::translate("SetZhuanQuanForm", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetZhuanQuanForm: public Ui_SetZhuanQuanForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETZHUANQUANFORM_H
