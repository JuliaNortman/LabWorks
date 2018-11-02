#include "card.h"
#include "ui_card.h"

Card::Card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Card)
{
    ui->setupUi(this);
}

Card::~Card()
{
    delete ui;
}
