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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormGameOver
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FormGameOver)
    {
        if (FormGameOver->objectName().isEmpty())
            FormGameOver->setObjectName("FormGameOver");
        FormGameOver->resize(479, 183);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormGameOver->setWindowIcon(icon);
        gridLayout = new QGridLayout(FormGameOver);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        label = new QLabel(FormGameOver);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        retranslateUi(FormGameOver);

        QMetaObject::connectSlotsByName(FormGameOver);
    } // setupUi

    void retranslateUi(QWidget *FormGameOver)
    {
        FormGameOver->setWindowTitle(QCoreApplication::translate("FormGameOver", "\346\270\270\346\210\217\347\273\223\346\235\237", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormGameOver: public Ui_FormGameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMEOVER_H
