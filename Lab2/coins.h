#ifndef COINS_H
#define COINS_H

#include <QDialog>

namespace Ui {
class Coins;
}

class Coins : public QDialog
{
    Q_OBJECT

public:
    explicit Coins(QWidget *parent = nullptr);
    ~Coins();
    void Model(int, int);

private slots:
    void on_ModelButton_clicked();

    void on_Coin1_valueChanged(int arg1);

    void on_Coin2_valueChanged(int arg1);

private:
    Ui::Coins *ui;
};

#endif // COINS_H
