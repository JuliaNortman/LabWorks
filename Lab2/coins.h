#ifndef COINS_H
#define COINS_H

#include <QDialog>
#include <QVector>
#include <QMovie>

namespace Ui {
class Coins;
}


class Coins : public QDialog
{
    Q_OBJECT

public:
    explicit Coins(QWidget *parent = nullptr);
    ~Coins();
    void Model(int, int, long long int);


private slots:
    void on_ModelButton_clicked();

    void on_Coin1_valueChanged(int arg1);

    void on_Coin2_valueChanged(int arg1);

    void on_coinPrevButton_clicked();

    void hideGif();

    void on_statisticsButton_clicked();

private:
    Ui::Coins *ui;
    QVector<long long int> prev;
    QVector<int> prevQuant;
    QVector<int> prevPercentage;
    QMovie *mo;
    bool previousButton;
    int *statistics;
};

#endif // COINS_H
