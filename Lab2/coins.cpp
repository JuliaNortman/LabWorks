#include "coins.h"
#include "ui_coins.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QMessageBox>
#include <QMainWindow>

Coins::Coins(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Coins)
{
    ui->setupUi(this);
    QPixmap coinPix("D:/VSprojects/LabWorks/Lab2/Coin.png");
    ui->coinPicture->setPixmap(coinPix);

    //ui->coinPicture->setScaledContents( true );

  //  ui->coinPicture->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->ModelButton->setEnabled(false);
    ui->Result->hide();
    ui->coinPrevButton->hide();
}

Coins::~Coins()
{
    delete ui;
}

void Coins::Model(int value, int n, long long int seed)
{
    ui->Result->show();
    qsrand(seed);
    for(int i = 0; i < n; ++i)
    {
         if(value < qrand() % ((100 + 1) - 1) + 1)
         {
             ui->Result->QTextEdit::append("Head");
          }
          else
          {
              ui->Result->QTextEdit::append("Tail");
          }
    }


}

void Coins::on_ModelButton_clicked()
{
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
}

void Coins::on_Coin1_valueChanged(int arg1)
{
    if(arg1 + ui->Coin2->value() == 100)
    {
        ui->ModelButton->setEnabled(true);
        /*QPalette myPalette = m_bButtonClose->palette();
myPalette.setColor( m_bButtonClose->backgroundRole(), QColor(0,250,0) );
m_bButtonClose->setPalette( myPalette );*/
        /*QPalette buttonPlt = ui->ModelButton->palette();
        buttonPlt.setColor(ui->ModelButton->backgroundRole(), QColor(0, 250, 0));
        ui->ModelButton->setPalette(buttonPlt);*/
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
        /*QPalette buttonPlt = ui->ModelButton->palette();
        buttonPlt.setColor(ui->ModelButton->backgroundRole(), QColor(0, 250, 0));
        ui->ModelButton->setPalette(buttonPlt);*/
    }
    else
    {
        ui->ModelButton->setEnabled(false);
    }
}


void Coins::on_coinPrevButton_clicked()
{
    ui->Result->clear();
    prev.pop_back();
    prevQuant.pop_back();
    prevPercentage.pop_back();
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
}
