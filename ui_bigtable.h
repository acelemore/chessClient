/********************************************************************************
** Form generated from reading UI file 'bigtable.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIGTABLE_H
#define UI_BIGTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chesstable.h"

QT_BEGIN_NAMESPACE

class Ui_BigTable
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QLCDNumber *lcdNumberBCount;
    QSpacerItem *verticalSpacer_2;
    ChessTable *chessWidget;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QLCDNumber *lcdNumberWCount;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelPix;
    QLabel *lableCount;
    QLCDNumber *lcdNumberCount;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *BigTable)
    {
        if (BigTable->objectName().isEmpty())
            BigTable->setObjectName(QStringLiteral("BigTable"));
        BigTable->resize(800, 600);
        BigTable->setMinimumSize(QSize(800, 600));
        gridLayout = new QGridLayout(BigTable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        widget_3 = new QWidget(BigTable);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 166, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/black.png")));
        label_5->setScaledContents(true);

        verticalLayout->addWidget(label_5);

        lcdNumberBCount = new QLCDNumber(widget_3);
        lcdNumberBCount->setObjectName(QStringLiteral("lcdNumberBCount"));

        verticalLayout->addWidget(lcdNumberBCount);

        verticalSpacer_2 = new QSpacerItem(20, 166, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 5);

        gridLayout->addWidget(widget_3, 1, 0, 1, 1);

        chessWidget = new ChessTable(BigTable);
        chessWidget->setObjectName(QStringLiteral("chessWidget"));

        gridLayout->addWidget(chessWidget, 1, 1, 1, 1);

        widget_4 = new QWidget(BigTable);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 166, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/white.png")));
        label_6->setScaledContents(true);

        verticalLayout_2->addWidget(label_6);

        lcdNumberWCount = new QLCDNumber(widget_4);
        lcdNumberWCount->setObjectName(QStringLiteral("lcdNumberWCount"));

        verticalLayout_2->addWidget(lcdNumberWCount);

        verticalSpacer_4 = new QSpacerItem(20, 166, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 2);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 5);

        gridLayout->addWidget(widget_4, 1, 2, 1, 1);

        widget_2 = new QWidget(BigTable);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(141, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(256, 46));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        labelPix = new QLabel(widget);
        labelPix->setObjectName(QStringLiteral("labelPix"));
        labelPix->setMinimumSize(QSize(40, 40));
        labelPix->setMaximumSize(QSize(40, 40));
        labelPix->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/black.png")));
        labelPix->setScaledContents(true);

        horizontalLayout_3->addWidget(labelPix);

        lableCount = new QLabel(widget);
        lableCount->setObjectName(QStringLiteral("lableCount"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        lableCount->setFont(font);
        lableCount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lableCount);

        lcdNumberCount = new QLCDNumber(widget);
        lcdNumberCount->setObjectName(QStringLiteral("lcdNumberCount"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumberCount->sizePolicy().hasHeightForWidth());
        lcdNumberCount->setSizePolicy(sizePolicy1);
        lcdNumberCount->setMinimumSize(QSize(60, 41));
        lcdNumberCount->setMaximumSize(QSize(60, 41));
        lcdNumberCount->setFrameShape(QFrame::NoFrame);
        lcdNumberCount->setDigitCount(2);

        horizontalLayout_3->addWidget(lcdNumberCount);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 2);

        horizontalLayout_2->addWidget(widget);

        horizontalSpacer_4 = new QSpacerItem(141, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addWidget(widget_2, 0, 0, 1, 3);

        widget_5 = new QWidget(BigTable);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget_5);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(widget_5);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget_5, 2, 0, 1, 3);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 8);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 8);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(BigTable);

        QMetaObject::connectSlotsByName(BigTable);
    } // setupUi

    void retranslateUi(QWidget *BigTable)
    {
        BigTable->setWindowTitle(QApplication::translate("BigTable", "Form", Q_NULLPTR));
        label_5->setText(QString());
        label_6->setText(QString());
        labelPix->setText(QString());
        lableCount->setText(QApplication::translate("BigTable", "\346\210\221\346\226\271\351\273\221\345\255\220\344\270\213", Q_NULLPTR));
        label->setText(QApplication::translate("BigTable", "\350\203\234\345\234\272\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BigTable: public Ui_BigTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIGTABLE_H
