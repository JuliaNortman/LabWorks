#include <QRandomGenerator>
#include <QDateTime>
#include "card.h"
#include "ui_card.h"
#include <QDebug>

Card::Card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Card)
{
    ui->setupUi(this);

   //qDebug() << QApplication::applicationDirPath();

    QPixmap spadePix("D:/VSprojects/LabWorks/Lab2/Spade.png");
    ui->spade->setPixmap(spadePix);
    ui->spade->setScaledContents(true);

    QPixmap diamondPix("D:/VSprojects/LabWorks/Lab2/Diamond.png");
    ui->diamond->setPixmap(diamondPix);
    ui->diamond->setScaledContents(true);

    QPixmap heartPix("D:/VSprojects/LabWorks/Lab2/Heart.png");
    ui->hearts->setPixmap(heartPix);
    ui->hearts->setScaledContents(true);

    QPixmap clubPix("D:/VSprojects/LabWorks/Lab2/Clubs.png");
    ui->club->setPixmap(clubPix);
    ui->club->setScaledContents(true);
}

Card::~Card()
{
    delete ui;
}

void Card::cardChosen(int r)
{
    if(r < 9)
    {
        ui->cardResult->QTextEdit::append("Hearts");
    }
    else if(r < 18)
    {
        ui->cardResult->QTextEdit::append("Spades ");
    }
    else if(r < 27)
    {
        ui->cardResult->QTextEdit::append("Diamonds ");
    }
    else
    {
        ui->cardResult->QTextEdit::append("Clubs ");
    }
    int rest = r % 9;
    if(rest < 5)
    {
        ui->cardResult->QTextEdit::insertPlainText(QString::number(rest + 6));
    }
    else if(rest == 5)
    {
         ui->cardResult->QTextEdit::insertPlainText("Jack ");
    }
    else if(rest == 6)
    {
         ui->cardResult->QTextEdit::insertPlainText("Queen ");
    }
    else if(rest == 7)
    {
         ui->cardResult->QTextEdit::insertPlainText("King ");
    }
    else
    {
         ui->cardResult->QTextEdit::insertPlainText("Ace ");
    }
}

void Card::Model(int n)
{
    qsrand(QDateTime::currentMSecsSinceEpoch());
    for(int i = 0; i < n; ++i)
    {
        int r = qrand() % 36 + 1;
        if(!taken[r])
        {
            cardChosen(r);
            taken[r] = true;
        }
        else
        {
            int j = 1;
            while(taken[(r+j) % 36])
            {
                j++;
            }
            cardChosen((r+j)%36);
            taken[(r+j)%36] = true;
        }
    }

}

void Card::on_cardModelButton_clicked()
{
    taken = new bool[36];
    for(int i = 0; i < 36; ++i)
    {
        taken[i] = false;
    }
    ui->cardResult->clear();
    ui->cardResult->append("Path: " + QApplication::applicationDirPath());
    int n = ui->cardQuantaty->value();
    Model(n);
    delete [] taken;
}
