/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

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

class Ui_Card
{
public:
    QLabel *spade;
    QLabel *diamond;
    QLabel *club;
    QLabel *hearts;
    QLabel *club_2;
    QLabel *cardGif;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *cardQuantaty;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cardModelButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *cardResult;
    QSpacerItem *verticalSpacer;
    QPushButton *nextButton;

    void setupUi(QDialog *Card)
    {
        if (Card->objectName().isEmpty())
            Card->setObjectName(QStringLiteral("Card"));
        Card->resize(600, 500);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Card->setPalette(palette);
        spade = new QLabel(Card);
        spade->setObjectName(QStringLiteral("spade"));
        spade->setGeometry(QRect(30, 50, 90, 90));
        diamond = new QLabel(Card);
        diamond->setObjectName(QStringLiteral("diamond"));
        diamond->setGeometry(QRect(480, 50, 90, 90));
        club = new QLabel(Card);
        club->setObjectName(QStringLiteral("club"));
        club->setGeometry(QRect(480, 370, 90, 90));
        hearts = new QLabel(Card);
        hearts->setObjectName(QStringLiteral("hearts"));
        hearts->setGeometry(QRect(30, 380, 90, 90));
        club_2 = new QLabel(Card);
        club_2->setObjectName(QStringLiteral("club_2"));
        club_2->setGeometry(QRect(480, 380, 90, 90));
        cardGif = new QLabel(Card);
        cardGif->setObjectName(QStringLiteral("cardGif"));
        cardGif->setGeometry(QRect(120, 150, 381, 141));
        cardGif->setPixmap(QPixmap(QString::fromUtf8("cardAnimation.gif")));
        cardGif->setScaledContents(true);
        layoutWidget = new QWidget(Card);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 41, 260, 301));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        cardQuantaty = new QSpinBox(layoutWidget);
        cardQuantaty->setObjectName(QStringLiteral("cardQuantaty"));
        cardQuantaty->setMinimum(1);
        cardQuantaty->setMaximum(36);

        horizontalLayout->addWidget(cardQuantaty);


        verticalLayout_2->addLayout(horizontalLayout);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cardModelButton = new QPushButton(layoutWidget);
        cardModelButton->setObjectName(QStringLiteral("cardModelButton"));
        cardModelButton->setFont(font);
        cardModelButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(cardModelButton);

        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cardResult = new QTextBrowser(layoutWidget);
        cardResult->setObjectName(QStringLiteral("cardResult"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        cardResult->setFont(font1);

        verticalLayout->addWidget(cardResult);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout);

        nextButton = new QPushButton(Card);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(350, 360, 75, 23));
        nextButton->setFont(font);
        nextButton->setCursor(QCursor(Qt::PointingHandCursor));
        cardGif->raise();
        spade->raise();
        diamond->raise();
        club->raise();
        hearts->raise();
        club_2->raise();
        layoutWidget->raise();
        nextButton->raise();

        retranslateUi(Card);

        QMetaObject::connectSlotsByName(Card);
    } // setupUi

    void retranslateUi(QDialog *Card)
    {
        Card->setWindowTitle(QApplication::translate("Card", "Cards", nullptr));
        spade->setText(QString());
        diamond->setText(QString());
        club->setText(QString());
        hearts->setText(QString());
        club_2->setText(QString());
        cardGif->setText(QString());
        label->setText(QApplication::translate("Card", "Enter number of experiments: ", nullptr));
        label_2->setText(QString());
        cardModelButton->setText(QApplication::translate("Card", "Model", nullptr));
        nextButton->setText(QApplication::translate("Card", "Next card", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Card: public Ui_Card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H
