#include <QRandomGenerator>
#include <QDateTime>
#include "card.h"
#include "ui_card.h"
#include <QTime>
#include <QTimer>

Card::Card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Card)
{
    ui->setupUi(this);
    Card::setWindowIcon(QIcon("Images/Clubs.png"));
    ui->cardResult->hide();

    mo = new QMovie();
    mo->setFileName("Images/cardAnimation.gif");
    ui->cardGif->setMovie(mo);
    ui->cardGif->hide();


    QPixmap spadePix("Images/Spade.png");
    ui->spade->setPixmap(spadePix);
    ui->spade->setScaledContents(true);


    QPixmap diamondPix("Images/Diamond.png");
    ui->diamond->setPixmap(diamondPix);
    ui->diamond->setScaledContents(true);

    QPixmap heartPix("Images/Heart.png");
    ui->hearts->setPixmap(heartPix);
    ui->hearts->setScaledContents(true);

    QPixmap clubPix("Images/Clubs.png");
    ui->club->setPixmap(clubPix);
    ui->club->setScaledContents(true);

    taken = new bool [36];
    n = 0;
    ui->nextButton->hide();
}

Card::~Card()
{
    delete mo;
    delete [] taken;
    delete ui;
}

void Card::cardChosen(int r)
{
    if(r < 9)
    {
        ui->cardResult->QTextEdit::append("<span style=' font-style:b; color:red;'>Hearts </span");
    }
    else if(r < 18)
    {
        ui->cardResult->QTextEdit::append("Spades ");
    }
    else if(r < 27)
    {
        ui->cardResult->QTextEdit::append("<span style=' font-style:b; color:red;'>Diamonds </span");
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

void Card::hideGif()
{
    mo->stop();
    ui->cardGif->hide();
    ui->cardResult->show();
}

void Card::on_cardModelButton_clicked()
{
    ui->cardResult->hide();
    ui->cardGif->show();
    mo->start();

    QTimer *tmr = new QTimer;
    tmr->start(1750);
    QTimer::singleShot(1750, this, SLOT(hideGif()));

    delete [] taken;
    taken = new bool[36];
    for(int i = 0; i < 36; ++i)
    {
        taken[i] = false;
    }
    n = 0;
    ui->cardResult->clear();
    n += n + ui->cardQuantaty->value();
    Model(ui->cardQuantaty->value());
    ui->nextButton->show();
    ui->nextButton->setEnabled(n < 36);
}

void Card::on_nextButton_clicked()
{
    n++;
    Model(1);
    ui->nextButton->setEnabled(n < 36);
}
