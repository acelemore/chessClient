/********************************************************************************
** Form generated from reading UI file 'chesstable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSTABLE_H
#define UI_CHESSTABLE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChessTable
{
public:

    void setupUi(QWidget *ChessTable)
    {
        if (ChessTable->objectName().isEmpty())
            ChessTable->setObjectName(QStringLiteral("ChessTable"));
        ChessTable->resize(300, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChessTable->sizePolicy().hasHeightForWidth());
        ChessTable->setSizePolicy(sizePolicy);
        ChessTable->setMinimumSize(QSize(300, 300));
        ChessTable->setMaximumSize(QSize(5000, 5000));
        ChessTable->setSizeIncrement(QSize(0, 0));
        ChessTable->setBaseSize(QSize(0, 0));
        ChessTable->setLocale(QLocale(QLocale::Chinese, QLocale::China));

        retranslateUi(ChessTable);

        QMetaObject::connectSlotsByName(ChessTable);
    } // setupUi

    void retranslateUi(QWidget *ChessTable)
    {
        ChessTable->setWindowTitle(QApplication::translate("ChessTable", "ChessTable", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChessTable: public Ui_ChessTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSTABLE_H
