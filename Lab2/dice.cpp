#include "dice.h"
#include "ui_dice.h"
#include <QRandomGenerator>
#include <QDateTime>

Dice::Dice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dice)
{
    ui->setupUi(this);
    ui->diceModelButton->setEnabled(false);
    ui->diceResult->hide();
    prob = new int[6];
}

Dice::~Dice()
{
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

void Dice::Model(int n)
{
    ui->diceResult->show();
    qsrand(QDateTime::currentMSecsSinceEpoch());
    for(int i = 1; i <= n; ++i)
    {
        int r = qrand() % 100 + 1;
        ui->diceResult->QTextEdit::append("Random: " + QString::number(r) + " ");
        int j = 0;
        for(j = 0; j<6; ++j)
        {
            if(r <= prob[j])
            {
                ui->diceResult->QTextEdit::append(QString::number(j+1) + " ");
                break;
            }
        }
        if(j == 6)
        {
            ui->diceResult->QTextEdit::append(QString::number(j+1) + " ");
        }
    }
}

void Dice::on_diceModelButton_clicked()
{
    ui->diceResult->clear();
    int n = ui->diceQuantaty->value();
    Model(n);
}
