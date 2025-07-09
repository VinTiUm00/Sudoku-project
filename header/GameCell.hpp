#ifndef GAMECELL_HPP
#define GAMECELL_HPP

// класс игровой ячейки
#include <QPushButton>

class GameCell : public QPushButton{

    Q_OBJECT

public:
    GameCell(int row, int col, QWidget* parent = nullptr);
    virtual ~GameCell();
    void ChangeNum(int num);

signals:
    void WannaChangeOut(GameCell* Cell);

public slots:
    void WannaChangeIn();

private:
    int row;
    int col;
    int num;
};

#endif
