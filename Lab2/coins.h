#ifndef COINS_H
#define COINS_H

#include <QDialog>
#include <QVector>

namespace Ui {
class Coins;
}

class Coins : public QDialog
{
    Q_OBJECT

public:
    explicit Coins(QWidget *parent = nullptr);
    ~Coins();


private slots:
    void on_ModelButton_clicked();

    void on_Coin1_valueChanged(int arg1);

    void on_Coin2_valueChanged(int arg1);

    void on_coinPrevButton_clicked();

private:
    Ui::Coins *ui;
    void Model(int, int, long long int);
    QVector<long long int> prev;
    QVector<int> prevQuant;
    QVector<int> prevPercentage;
};

#endif // COINS_H
