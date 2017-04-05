/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QHBoxLayout *blocksLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *calibrateButton;
    QLabel *nodeTitleLabel;
    QLabel *sentenceLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *pbstart;

    void setupUi(QWidget *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QStringLiteral("Interface"));
        Interface->resize(481, 399);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI Light"));
        font.setPointSize(24);
        Interface->setFont(font);
        gridLayout = new QGridLayout(Interface);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(Interface);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 463, 68));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        blocksLayout = new QHBoxLayout();
        blocksLayout->setObjectName(QStringLiteral("blocksLayout"));

        gridLayout_2->addLayout(blocksLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 3, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        calibrateButton = new QPushButton(Interface);
        calibrateButton->setObjectName(QStringLiteral("calibrateButton"));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(10);
        calibrateButton->setFont(font1);

        horizontalLayout->addWidget(calibrateButton);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 2);

        nodeTitleLabel = new QLabel(Interface);
        nodeTitleLabel->setObjectName(QStringLiteral("nodeTitleLabel"));
        QFont font2;
        font2.setFamily(QStringLiteral("Sans Serif"));
        font2.setPointSize(10);
        nodeTitleLabel->setFont(font2);

        gridLayout->addWidget(nodeTitleLabel, 0, 0, 1, 2);

        sentenceLabel = new QLabel(Interface);
        sentenceLabel->setObjectName(QStringLiteral("sentenceLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe UI"));
        font3.setPointSize(36);
        sentenceLabel->setFont(font3);
        sentenceLabel->setAlignment(Qt::AlignCenter);
        sentenceLabel->setWordWrap(true);

        gridLayout->addWidget(sentenceLabel, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 2);

        pbstart = new QPushButton(Interface);
        pbstart->setObjectName(QStringLiteral("pbstart"));

        gridLayout->addWidget(pbstart, 6, 0, 1, 1);


        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QWidget *Interface)
    {
        Interface->setWindowTitle(QApplication::translate("Interface", "Interface", 0));
        calibrateButton->setText(QApplication::translate("Interface", "Calibrar", 0));
        nodeTitleLabel->setText(QApplication::translate("Interface", "nodeTitle", 0));
        sentenceLabel->setText(QString());
        pbstart->setText(QApplication::translate("Interface", "start process", 0));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
