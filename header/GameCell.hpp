#ifndef GAMECELL_HPP
#define GAMECELL_HPP

// класс игровой ячейки
#include <QPushButton>

class GameCell : public QPushButton{

    Q_OBJECT

public:
    GameCell(int row, int col, QWidget* parent = nullptr);
    virtual ~GameCell();
signals:
    void WannaChange();

public slots:
    void ChangeNum(int num);

private:
    int row;
    int col;
    int num;
};

#endif
