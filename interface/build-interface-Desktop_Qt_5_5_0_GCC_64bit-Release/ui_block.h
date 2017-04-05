/********************************************************************************
** Form generated from reading UI file 'block.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCK_H
#define UI_BLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "interface/image.hpp"

QT_BEGIN_NAMESPACE

class Ui_Block
{
public:
    QGridLayout *gridLayout;
    QLabel *blockTitleLabel;
    Image *iconImage;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Block)
    {
        if (Block->objectName().isEmpty())
            Block->setObjectName(QStringLiteral("Block"));
        Block->resize(400, 300);
        gridLayout = new QGridLayout(Block);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        blockTitleLabel = new QLabel(Block);
        blockTitleLabel->setObjectName(QStringLiteral("blockTitleLabel"));
        QFont font;
        font.setPointSize(12);
        blockTitleLabel->setFont(font);
        blockTitleLabel->setAlignment(Qt::AlignCenter);
        blockTitleLabel->setWordWrap(true);

        gridLayout->addWidget(blockTitleLabel, 3, 0, 1, 1);

        iconImage = new Image(Block);
        iconImage->setObjectName(QStringLiteral("iconImage"));
        gridLayout_2 = new QGridLayout(iconImage);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 67, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout->addWidget(iconImage, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 0, 1, 1);


        retranslateUi(Block);

        QMetaObject::connectSlotsByName(Block);
    } // setupUi

    void retranslateUi(QWidget *Block)
    {
        Block->setWindowTitle(QApplication::translate("Block", "Block", 0));
        blockTitleLabel->setText(QApplication::translate("Block", "blockTitle", 0));
    } // retranslateUi

};

namespace Ui {
    class Block: public Ui_Block {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCK_H
