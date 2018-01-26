/********************************************************************************
** Form generated from reading UI file 'cregister.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREGISTER_H
#define UI_CREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cRegister
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *leUsr;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lePsw;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *leCfPsw;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *cRegister)
    {
        if (cRegister->objectName().isEmpty())
            cRegister->setObjectName(QStringLiteral("cRegister"));
        cRegister->resize(277, 133);
        gridLayout = new QGridLayout(cRegister);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(cRegister);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        leUsr = new QLineEdit(cRegister);
        leUsr->setObjectName(QStringLiteral("leUsr"));

        horizontalLayout_3->addWidget(leUsr);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(cRegister);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lePsw = new QLineEdit(cRegister);
        lePsw->setObjectName(QStringLiteral("lePsw"));
        lePsw->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lePsw);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(cRegister);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        leCfPsw = new QLineEdit(cRegister);
        leCfPsw->setObjectName(QStringLiteral("leCfPsw"));
        leCfPsw->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(leCfPsw);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(cRegister);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        retranslateUi(cRegister);

        QMetaObject::connectSlotsByName(cRegister);
    } // setupUi

    void retranslateUi(QWidget *cRegister)
    {
        cRegister->setWindowTitle(QApplication::translate("cRegister", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("cRegister", "\347\224\250\346\210\267\345\220\215  ", Q_NULLPTR));
        label_2->setText(QApplication::translate("cRegister", "\345\257\206\347\240\201    ", Q_NULLPTR));
        label_3->setText(QApplication::translate("cRegister", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cRegister", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cRegister: public Ui_cRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREGISTER_H
