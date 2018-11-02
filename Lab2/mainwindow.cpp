#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ModelButton_clicked()
{
    if(ui->ChooseProb->currentText() == "Coins")
    {
        c = new Coins();
        c->setModal(true);
        c->exec();
    }
    if(ui->ChooseProb->currentText() == "Dices")
    {
        d = new Dice();
        d->setModal(true);
        d->exec();
    }
    if(ui->ChooseProb->currentText() == "Cards")
    {
        card = new Card();
        card->setModal(true);
        card->exec();
    }
}

