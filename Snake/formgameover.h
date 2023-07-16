#ifndef FORMGAMEOVER_H
#define FORMGAMEOVER_H

#include <QWidget>

namespace Ui {
class FormGameOver;
}

class FormGameOver : public QWidget
{
    Q_OBJECT

public:
    explicit FormGameOver(int score, QWidget *parent = nullptr);
    ~FormGameOver();

private:
    Ui::FormGameOver *ui;
};

#endif // FORMGAMEOVER_H
