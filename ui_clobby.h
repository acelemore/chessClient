/********************************************************************************
** Form generated from reading UI file 'clobby.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOBBY_H
#define UI_CLOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cLobby
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *cLobby)
    {
        if (cLobby->objectName().isEmpty())
            cLobby->setObjectName(QStringLiteral("cLobby"));
        cLobby->resize(409, 518);
        gridLayout = new QGridLayout(cLobby);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_3 = new QPushButton(cLobby);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        listWidget = new QListWidget(cLobby);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(cLobby);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(cLobby);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(cLobby);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(cLobby);

        QMetaObject::connectSlotsByName(cLobby);
    } // setupUi

    void retranslateUi(QWidget *cLobby)
    {
        cLobby->setWindowTitle(QApplication::translate("cLobby", "Form", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("cLobby", "\345\210\267\346\226\260", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cLobby", "\345\207\206\345\244\207", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("cLobby", "\345\217\226\346\266\210\345\207\206\345\244\207", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("cLobby", "\351\232\217\346\234\272\345\212\240\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cLobby: public Ui_cLobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOBBY_H
