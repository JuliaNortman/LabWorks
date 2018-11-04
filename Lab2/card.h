#ifndef CARD_H
#define CARD_H

#include <QDialog>

namespace Ui {
class Card;
}

class Card : public QDialog
{
    Q_OBJECT

public:
    explicit Card(QWidget *parent = nullptr);
    ~Card();

private slots:
    void on_cardModelButton_clicked();

private:
    Ui::Card *ui;
    bool *taken;
    void Model(int);
    void cardChosen(int);
};

#endif // CARD_H
