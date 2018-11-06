#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "coins.h"
#include "dice.h"
#include "card.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ModelButton_clicked();

private:
    Ui::MainWindow *ui;
    Coins *c;
    Dice *d;
    Card *card;
};



#endif // MAINWINDOW_H
