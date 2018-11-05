#ifndef CARD_H
#define CARD_H

#include <QDialog>
#include <QMovie>

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

    void hideGif();

    void on_nextButton_clicked();

private:
    Ui::Card *ui;
    bool *taken;
    void Model(int);
    void cardChosen(int);
    QMovie *mo;
    int n; //number of cards that are already taken
};

#endif // CARD_H
