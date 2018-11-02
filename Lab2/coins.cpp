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

    ui->ModelButton->setEnabled(false);
    ui->Result->hide();
}

Coins::~Coins()
{
    delete ui;
}

void Coins::Model(int value, int n)
{
    ui->Result->show();
    qsrand(QDateTime::currentMSecsSinceEpoch());
    for(int i = 0; i < n; ++i)
    {
         if(value < qrand() % ((100 + 1) - 1) + 1)
         {
             ui->Result->QTextEdit::append("Gerb ");
          }
          else
          {
              ui->Result->QTextEdit::append("Reshka ");
          }
    }


}

void Coins::on_ModelButton_clicked()
{
    ui->Result->clear();
    int x = ui->Coin1->value();
    int n = ui->Quantaty->value();
    Model(x, n);
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

