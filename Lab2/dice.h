#ifndef DICE_H
#define DICE_H

#include <QDialog>

namespace Ui {
class Dice;
}

class Dice : public QDialog
{
    Q_OBJECT

public:
    explicit Dice(QWidget *parent = nullptr);
    ~Dice();

private slots:
    void on_side1_valueChanged(int arg1);

    void on_side2_valueChanged(int arg1);

    void on_side3_valueChanged(int arg1);

    void on_side5_valueChanged(int arg1);

    void on_side4_valueChanged(int arg1);

    void on_side6_valueChanged(int arg1);

    void on_diceModelButton_clicked();

private:
    Ui::Dice *ui;
    void ifClicked(int, int, int);
    void Model(int);
    int *prob;
};

#endif // DICE_H
