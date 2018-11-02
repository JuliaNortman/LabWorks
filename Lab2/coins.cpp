#include "coins.h"
#include "ui_coins.h"
#include <QRandomGenerator>
#include <QMessageBox>

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
    for(int i = 0; i < n; ++i)
    {
       // QDebug(QString::number(i) + " ");
        int k = qrand() % ((100 + 1) - 1) + 1;
        ui->Result->setText(QString::number(k) + " ");
         /*if(value < qrand() % ((100 + 1) - 1) + 1)
         {
             ui->Result->setText("Gerb ");
          }
          else
          {
              ui->Result->setText("Reshka ");
          }*/
    }


}

void Coins::on_ModelButton_clicked()
{
    int x = ui->Coin1->value();
    int n = ui->Quantaty->value();
    if(ui->ModelButton->isEnabled())
    {
        Model(x, n);
    }
    else if(! ui->ModelButton->isEnabled())
    {
        QMessageBox *warning = new QMessageBox;
        warning->setText("Warning");
        warning->setIcon(QMessageBox::Warning);
        warning->setInformativeText("The sum of probabilities must be 100%");
        warning->show();
        delete warning;
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

