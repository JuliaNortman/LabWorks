#include "coins.h"
#include "ui_coins.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QMessageBox>
#include <QMainWindow>
#include <QTimer>

Coins::Coins(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Coins)
{
    ui->setupUi(this);

    Coins::setWindowIcon(QIcon("Images/CoinIcon.png"));

    mo = new QMovie();
    mo->setFileName("Images/coinAnimation.gif");
    ui->coinGif->setMovie(mo);
    ui->coinGif->hide();

    ui->ModelButton->setEnabled(false);
    ui->Result->hide();
    ui->coinPrevButton->hide();

    previousButton = false;

    statistics = new int [2];
    statistics[0] = statistics[1] = 0;
    ui->statisticsButton->hide();
}

Coins::~Coins()
{
    delete mo;
    delete [] statistics;
    delete ui;
}

void Coins::Model(int value, int n, long long int seed)
{
    ui->Result->hide();
    ui->coinGif->show();
    mo->start();
    statistics[0] = statistics[1] = 0;
    QTimer *tmr = new QTimer;
    tmr->start(3000);
    QTimer::singleShot(3000, this, SLOT(hideGif()));


    qsrand(seed);
    for(int i = 0; i < n; ++i)
    {
         if(value < qrand() % 100 + 1)
         {
             ui->Result->QTextEdit::append("Head");
             statistics[0]++;
         }
         else
         {
              ui->Result->QTextEdit::append("Tail");
              statistics[1]++;
         }
    }
}

void Coins::hideGif()
{
    mo->stop();
    ui->coinGif->hide();
    ui->Result->show();
    ui->statisticsButton->show();
}

void Coins::on_ModelButton_clicked()
{
    previousButton = false;
    if(!prev.empty())
    {
        ui->coinPrevButton->show();
    }
    ui->Result->clear();
    int x = ui->Coin1->value();
    int n = ui->Quantaty->value();
    long long int seed = QDateTime::currentMSecsSinceEpoch();
    prev.push_back(seed);
    prevQuant.push_back(n);
    prevPercentage.push_back(x);
    Model(x, n, seed);

    if(prev.size() > 1)
    {
        ui->coinPrevButton->setEnabled(true);
    }
}

void Coins::on_Coin1_valueChanged(int arg1)
{
    if(arg1 + ui->Coin2->value() == 100)
    {
        ui->ModelButton->setEnabled(true);
    }
    else
    {
        ui->ModelButton->setEnabled(false);
    }
}

void Coins::on_Coin2_valueChanged(int arg1)
{
    if(arg1 + ui->Coin1->value() == 100)
    {
        ui->ModelButton->setEnabled(true);
    }
    else
    {
        ui->ModelButton->setEnabled(false);
    }
}


void Coins::on_coinPrevButton_clicked()
{
    ui->Result->clear();
    if(!previousButton)
    {
        prev.pop_back();
        prevQuant.pop_back();
        prevPercentage.pop_back();
    }
    long long int seed = prev.value(prev.size()-1);
    prev.pop_back();
    int n = prevQuant.value(prevQuant.size()-1);
    prevQuant.pop_back();
    int x = prevPercentage.value(prevPercentage.size()-1);
    prevPercentage.pop_back();
    ui->Coin1->setValue(x);
    ui->Coin2->setValue(100-x);
    ui->Quantaty->setValue(n);
    Model(x, n, seed);
    if(prev.empty())
    {
        ui->coinPrevButton->setEnabled(false);
    }

    previousButton = true;
}


void Coins::on_statisticsButton_clicked()
{
    QString message1 = "Number of experiments: "  + QString::number(ui->Quantaty->value()) + "\n";
    QString message2 = "Head: " + QString::number(statistics[0]) + "\n";
    QString message3 = "Tail: " + QString::number(statistics[1]) + "\n";
    QMessageBox *st = new QMessageBox;
    st->setWindowIcon(QIcon("Images/Statistics.png"));
    st->setText(message1+message2+message3);
    st->setWindowTitle("Statistics");
    st->setIcon(QMessageBox::Information);
    st->exec();
    delete st;
}
