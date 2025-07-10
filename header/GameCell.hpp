#ifndef GAMECELL_HPP
#define GAMECELL_HPP

// класс игровой ячейки
#include <QPushButton>

class GameCell : public QPushButton{

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    GameCell(QWidget* parent = nullptr, bool fvalue = false); // конструктор для изменяемой кнопки
    GameCell(QWidget* parent = nullptr, short int num = 0); // конструктор для неизменяемой кнопки
    virtual ~GameCell();
    void ChangeNum(int num); // изменить число ячейки
    void setfCanChange(bool value); // установить fCanChange

signals:
    void WannaChangeOut(GameCell* Cell);

public slots:
    void WannaChangeIn();

private:
    int num;
    bool fCanChange;
};

#endif
