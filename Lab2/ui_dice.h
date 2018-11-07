/********************************************************************************
** Form generated from reading UI file 'dice.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICE_H
#define UI_DICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dice
{
public:
    QLabel *RedDice;
    QLabel *GreenDice;
    QLabel *diceGif;
    QTextBrowser *diceResult;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *side1;
    QLabel *label_3;
    QSpinBox *side2;
    QLabel *label_6;
    QSpinBox *side3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *side4;
    QLabel *label_4;
    QSpinBox *side5;
    QLabel *label_5;
    QSpinBox *side6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QSpinBox *diceQuantaty;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *diceModelButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *statisticsButton;

    void setupUi(QDialog *Dice)
    {
        if (Dice->objectName().isEmpty())
            Dice->setObjectName(QStringLiteral("Dice"));
        Dice->setWindowModality(Qt::NonModal);
        Dice->resize(600, 500);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Dice->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        Dice->setFont(font);
        RedDice = new QLabel(Dice);
        RedDice->setObjectName(QStringLiteral("RedDice"));
        RedDice->setGeometry(QRect(440, 370, 111, 71));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        RedDice->setPalette(palette1);
        RedDice->setFont(font);
        RedDice->setPixmap(QPixmap(QString::fromUtf8("FlyingDices.png")));
        RedDice->setScaledContents(true);
        GreenDice = new QLabel(Dice);
        GreenDice->setObjectName(QStringLiteral("GreenDice"));
        GreenDice->setGeometry(QRect(20, 30, 91, 81));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        GreenDice->setPalette(palette2);
        GreenDice->setFont(font);
        GreenDice->setPixmap(QPixmap(QString::fromUtf8("GreenDices.png")));
        GreenDice->setScaledContents(true);
        diceGif = new QLabel(Dice);
        diceGif->setObjectName(QStringLiteral("diceGif"));
        diceGif->setGeometry(QRect(170, 250, 191, 171));
        diceGif->setPixmap(QPixmap(QString::fromUtf8("DicesAnimation.gif")));
        diceGif->setScaledContents(true);
        diceResult = new QTextBrowser(Dice);
        diceResult->setObjectName(QStringLiteral("diceResult"));
        diceResult->setGeometry(QRect(150, 260, 256, 165));
        layoutWidget = new QWidget(Dice);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(142, 2, 270, 237));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setItalic(true);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        side1 = new QSpinBox(layoutWidget);
        side1->setObjectName(QStringLiteral("side1"));
        side1->setMaximum(100);

        horizontalLayout->addWidget(side1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        side2 = new QSpinBox(layoutWidget);
        side2->setObjectName(QStringLiteral("side2"));
        side2->setMaximum(100);

        horizontalLayout->addWidget(side2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        side3 = new QSpinBox(layoutWidget);
        side3->setObjectName(QStringLiteral("side3"));
        side3->setMaximum(100);

        horizontalLayout->addWidget(side3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        side4 = new QSpinBox(layoutWidget);
        side4->setObjectName(QStringLiteral("side4"));
        side4->setMaximum(100);

        horizontalLayout_2->addWidget(side4);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        side5 = new QSpinBox(layoutWidget);
        side5->setObjectName(QStringLiteral("side5"));
        side5->setMaximum(100);

        horizontalLayout_2->addWidget(side5);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        side6 = new QSpinBox(layoutWidget);
        side6->setObjectName(QStringLiteral("side6"));
        side6->setMaximum(100);

        horizontalLayout_2->addWidget(side6);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_3->addWidget(label_8);

        diceQuantaty = new QSpinBox(layoutWidget);
        diceQuantaty->setObjectName(QStringLiteral("diceQuantaty"));
        diceQuantaty->setMinimum(1);
        diceQuantaty->setMaximum(200);

        horizontalLayout_3->addWidget(diceQuantaty);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        diceModelButton = new QPushButton(layoutWidget);
        diceModelButton->setObjectName(QStringLiteral("diceModelButton"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(10);
        diceModelButton->setFont(font2);
        diceModelButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(diceModelButton);

        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_4);

        statisticsButton = new QPushButton(Dice);
        statisticsButton->setObjectName(QStringLiteral("statisticsButton"));
        statisticsButton->setGeometry(QRect(330, 440, 75, 23));
        QFont font3;
        font3.setPointSize(10);
        statisticsButton->setFont(font3);
        statisticsButton->setCursor(QCursor(Qt::PointingHandCursor));
        diceResult->raise();
        RedDice->raise();
        GreenDice->raise();
        layoutWidget->raise();
        diceGif->raise();
        statisticsButton->raise();

        retranslateUi(Dice);

        QMetaObject::connectSlotsByName(Dice);
    } // setupUi

    void retranslateUi(QDialog *Dice)
    {
        Dice->setWindowTitle(QApplication::translate("Dice", "Dices", nullptr));
        RedDice->setText(QString());
        GreenDice->setText(QString());
        diceGif->setText(QString());
        label->setText(QApplication::translate("Dice", "<html><head/><body><h2><p align=\"center\"><span style=\" font-size:10pt; font-weight:600; color:#aa0000;\">Enter probabilities (%)</span></p></h2></body></html>", nullptr));
        label_2->setText(QApplication::translate("Dice", "1: ", nullptr));
        label_3->setText(QApplication::translate("Dice", "2: ", nullptr));
        label_6->setText(QApplication::translate("Dice", "3: ", nullptr));
        label_7->setText(QApplication::translate("Dice", "4: ", nullptr));
        label_4->setText(QApplication::translate("Dice", "5: ", nullptr));
        label_5->setText(QApplication::translate("Dice", "6: ", nullptr));
        label_8->setText(QApplication::translate("Dice", "<html><head/><body><p><span style=\" font-size:10pt;\">Enter number of experiments: </span></p></body></html>", nullptr));
        label_9->setText(QString());
        diceModelButton->setText(QApplication::translate("Dice", "Model", nullptr));
        statisticsButton->setText(QApplication::translate("Dice", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dice: public Ui_Dice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICE_H
