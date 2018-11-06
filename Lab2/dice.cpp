#include "dice.h"
#include "ui_dice.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QMovie>
#include <QTimer>
#include <QMessageBox>


Dice::Dice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dice)
{
    ui->setupUi(this);

    Dice::setWindowIcon(QIcon("Images/diceIcon.png"));

    mo = new QMovie();
    mo->setFileName("Images/DicesAnimation.gif");
    ui->diceGif->setMovie(mo);
    ui->diceGif->hide();

    QPixmap redPix("Images/FlyingDices.png");
    ui->RedDice->setPixmap(redPix);
    ui->RedDice->setScaledContents(true);

    QPixmap greenPix("Images/GreenDices.png");
    ui->GreenDice->setPixmap(greenPix);
    ui->GreenDice->setScaledContents(true);

    ui->diceModelButton->setEnabled(false);
    ui->diceResult->hide();
    prob = new int[6];
    statistics = new int[6];
    ui->statisticsButton->hide();
}

Dice::~Dice()
{
    delete [] prob;
    delete [] statistics;
    delete mo;
    delete ui;
}

void Dice::ifClicked(int x, int y, int z)
{
    if(x+y+z == 100)
    {
        ui->diceModelButton->setEnabled(true);
    }
    else
    {
        ui->diceModelButton->setEnabled(false);
    }
}

void Dice::on_side1_valueChanged(int arg1)
{
    prob[0] = arg1;
    prob[1] = prob[0] + ui->side2->value();
    prob[2] = prob[1] + ui->side3->value();
    prob[3] = prob[2] + ui->side4->value();
    prob[4] = prob[3] + ui->side5->value();
    prob[5] = prob[4] + ui->side6->value();
    int x = ui->side2->value() + arg1;
    int y = ui->side3->value() + ui->side4->value();
    int z = ui->side5->value() + ui->side6->value();
    ifClicked(x, y, z);
}

void Dice::on_side2_valueChanged(int arg1)
{
    prob[0] = ui->side1->value();
    prob[1] = prob[0] + arg1;
    prob[2] = prob[1] + ui->side3->value();
    prob[3] = prob[2] + ui->side4->value();
    prob[4] = prob[3] + ui->side5->value();
    prob[5] = prob[4] + ui->side6->value();
    int x = ui->side1->value() + arg1;
    int y = ui->side3->value() + ui->side4->value();
    int z = ui->side5->value() + ui->side6->value();
    ifClicked(x, y, z);
}

void Dice::on_side3_valueChanged(int arg1)
{
    prob[0] = ui->side1->value();;
    prob[1] = prob[0] + ui->side2->value();
    prob[2] = prob[1] + arg1;
    prob[3] = prob[2] + ui->side4->value();
    prob[4] = prob[3] + ui->side5->value();
    prob[5] = prob[4] + ui->side6->value();
    int x = ui->side2->value() + ui->side1->value();
    int y = arg1 + ui->side4->value();
    int z = ui->side5->value() + ui->side6->value();
    ifClicked(x, y, z);
}

void Dice::on_side5_valueChanged(int arg1)
{
    prob[0] = ui->side1->value();
    prob[1] = prob[0] + ui->side2->value();
    prob[2] = prob[1] + ui->side3->value();
    prob[3] = prob[2] + ui->side4->value();
    prob[4] = prob[3] + arg1;
    prob[5] = prob[4] + ui->side6->value();
    int x = ui->side2->value() + ui->side1->value();
    int y = ui->side3->value() + ui->side4->value();
    int z = arg1 + ui->side6->value();
    ifClicked(x, y, z);
}

void Dice::on_side4_valueChanged(int arg1)
{
    prob[0] = ui->side1->value();
    prob[1] = prob[0] + ui->side2->value();
    prob[2] = prob[1] + ui->side3->value();
    prob[3] = prob[2] + arg1;
    prob[4] = prob[3] + ui->side5->value();
    prob[5] = prob[4] + ui->side6->value();
    int x = ui->side2->value() + ui->side1->value();
    int y = ui->side3->value() + arg1;
    int z = ui->side5->value() + ui->side6->value();
    ifClicked(x, y, z);
}

void Dice::on_side6_valueChanged(int arg1)
{
    prob[0] = ui->side1->value();
    prob[1] = prob[0] + ui->side2->value();
    prob[2] = prob[1] + ui->side3->value();
    prob[3] = prob[2] + ui->side4->value();
    prob[4] = prob[3] + ui->side5->value();
    prob[5] = prob[4] + arg1;
    int x = ui->side2->value() + ui->side1->value();
    int y = ui->side3->value() + ui->side4->value();
    int z = ui->side5->value() + arg1;
    ifClicked(x, y, z);
}

void Dice::hideGif()
{
    mo->stop();
    ui->diceGif->hide();
    ui->diceResult->show();
    ui->statisticsButton->show();
}

void Dice::Model(int n)
{
    for(int i = 0; i < 6; ++i)
    {
        statistics[i] = 0;
    }

    ui->diceResult->hide();
    ui->diceGif->show();
    mo->start();

    QTimer *tmr = new QTimer;
    tmr->start(2600);
    QTimer::singleShot(2600, this, SLOT(hideGif()));

    qsrand(QDateTime::currentMSecsSinceEpoch());
    for(int i = 1; i <= n; ++i)
    {
        int r = qrand() % 100 + 1;
        int j = 0;
        for(j = 0; j<6; ++j)
        {
            if(r <= prob[j])
            {
                ui->diceResult->QTextEdit::append("Side: " + QString::number(j+1));
                statistics[j]++;
                break;
            }
        }
    }
}

void Dice::on_diceModelButton_clicked()
{
    ui->diceResult->clear();
    int n = ui->diceQuantaty->value();
    Model(n);
}



void Dice::on_statisticsButton_clicked()
{
    QString mes = "Number of experiments: "  + QString::number(ui->diceQuantaty->value()) + "\n";
    QString mes1 = "Side1: " + QString::number(statistics[0]) + "\n";
    QString mes2 = "Side2: " + QString::number(statistics[1]) + "\n";
    QString mes3 = "Side3: " + QString::number(statistics[2]) + "\n";
    QString mes4 = "Side4: " + QString::number(statistics[3]) + "\n";
    QString mes5 = "Side5: " + QString::number(statistics[4]) + "\n";
    QString mes6 = "Side6: " + QString::number(statistics[5]) + "\n";
    QMessageBox *st = new QMessageBox;
    st->setWindowIcon(QIcon("Images/Statistics.png"));
    st->setText(mes+mes1+mes2+mes3+mes4+mes5+mes6);
    st->setWindowTitle("Statistics");
    st->setIcon(QMessageBox::Information);
    st->exec();
    delete st;
}
