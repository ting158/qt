/********************************************************************************
** Form generated from reading UI file 'formgameover.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAMEOVER_H
#define UI_FORMGAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGameOver
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *FormGameOver)
    {
        if (FormGameOver->objectName().isEmpty())
            FormGameOver->setObjectName("FormGameOver");
        FormGameOver->resize(689, 161);
        gridLayout = new QGridLayout(FormGameOver);
        gridLayout->setObjectName("gridLayout");

        retranslateUi(FormGameOver);

        QMetaObject::connectSlotsByName(FormGameOver);
    } // setupUi

    void retranslateUi(QWidget *FormGameOver)
    {
        FormGameOver->setWindowTitle(QCoreApplication::translate("FormGameOver", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormGameOver: public Ui_FormGameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMEOVER_H
