/********************************************************************************
** Form generated from reading UI file 'coins.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COINS_H
#define UI_COINS_H

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

class Ui_Coins
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *En;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *Coin1;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QSpinBox *Coin2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *Quantaty;
    QSpacerItem *verticalSpacer_3;
    QPushButton *ModelButton;
    QSpacerItem *verticalSpacer_4;
    QTextBrowser *Result;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *coinPrevButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *statisticsButton;
    QLabel *coinsLbl;
    QLabel *coinGif;

    void setupUi(QDialog *Coins)
    {
        if (Coins->objectName().isEmpty())
            Coins->setObjectName(QStringLiteral("Coins"));
        Coins->resize(600, 500);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush3(QColor(170, 170, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        QBrush brush5(QColor(170, 85, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        Coins->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        Coins->setFont(font);
        Coins->setCursor(QCursor(Qt::ArrowCursor));
        Coins->setTabletTracking(false);
        Coins->setModal(false);
        layoutWidget = new QWidget(Coins);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 10, 275, 452));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        En = new QLabel(layoutWidget);
        En->setObjectName(QStringLiteral("En"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        En->setFont(font1);
        En->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(En);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        Coin1 = new QSpinBox(layoutWidget);
        Coin1->setObjectName(QStringLiteral("Coin1"));
        Coin1->setMaximum(100);

        horizontalLayout->addWidget(Coin1);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        Coin2 = new QSpinBox(layoutWidget);
        Coin2->setObjectName(QStringLiteral("Coin2"));
        Coin2->setMaximum(100);

        horizontalLayout->addWidget(Coin2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(12);
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        Quantaty = new QSpinBox(layoutWidget);
        Quantaty->setObjectName(QStringLiteral("Quantaty"));
        Quantaty->setMinimum(1);
        Quantaty->setMaximum(200);
        Quantaty->setDisplayIntegerBase(10);

        horizontalLayout_2->addWidget(Quantaty);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        ModelButton = new QPushButton(layoutWidget);
        ModelButton->setObjectName(QStringLiteral("ModelButton"));
        ModelButton->setFont(font);
        ModelButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(ModelButton);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        Result = new QTextBrowser(layoutWidget);
        Result->setObjectName(QStringLiteral("Result"));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(10);
        font3.setItalic(true);
        Result->setFont(font3);
        Result->setFrameShape(QFrame::Box);
        Result->setTabStopWidth(80);

        verticalLayout_2->addWidget(Result);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        coinPrevButton = new QPushButton(layoutWidget);
        coinPrevButton->setObjectName(QStringLiteral("coinPrevButton"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(10);
        coinPrevButton->setFont(font4);
        coinPrevButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(coinPrevButton);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        statisticsButton = new QPushButton(layoutWidget);
        statisticsButton->setObjectName(QStringLiteral("statisticsButton"));
        QFont font5;
        font5.setPointSize(10);
        statisticsButton->setFont(font5);
        statisticsButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(statisticsButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        coinsLbl = new QLabel(Coins);
        coinsLbl->setObjectName(QStringLiteral("coinsLbl"));
        coinsLbl->setGeometry(QRect(10, 30, 161, 131));
        coinsLbl->setPixmap(QPixmap(QString::fromUtf8("Images/Coins.png")));
        coinsLbl->setScaledContents(true);
        coinGif = new QLabel(Coins);
        coinGif->setObjectName(QStringLiteral("coinGif"));
        coinGif->setGeometry(QRect(270, 190, 111, 181));
        coinGif->setPixmap(QPixmap(QString::fromUtf8("coinAnimation.gif")));
        coinGif->setScaledContents(true);

        retranslateUi(Coins);

        QMetaObject::connectSlotsByName(Coins);
    } // setupUi

    void retranslateUi(QDialog *Coins)
    {
        Coins->setWindowTitle(QApplication::translate("Coins", "Coins", nullptr));
        En->setText(QApplication::translate("Coins", "<html><head/><body><h2><p align=\"center\"><span style=\" font-style:italic; color:#c80c06;\">Enter probability (%)</span></p></h2></body></html>", nullptr));
        label_2->setText(QApplication::translate("Coins", "<html><head/><body><p><span style=\" font-size:10pt;\">Tail: </span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Coins", "<html><head/><body><p><span style=\" font-size:10pt;\">Head: </span></p></body></html>", nullptr));
        label->setText(QApplication::translate("Coins", "<html><head/><body><p><span style=\" font-size:10pt;\">Enter number of experiments</span></p></body></html>", nullptr));
        ModelButton->setText(QApplication::translate("Coins", "Model", nullptr));
        coinPrevButton->setText(QApplication::translate("Coins", "Previous experiment", nullptr));
        statisticsButton->setText(QApplication::translate("Coins", "Statistics", nullptr));
        coinsLbl->setText(QString());
        coinGif->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Coins: public Ui_Coins {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COINS_H
