#ifndef HELPER_HPP
#define HELPER_HPP

#include <QObject>

#include "ControlCell.hpp"
#include "GameCell.hpp"

// класс помощника. Помогает на игровом поле
class Helper : public QObject{

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    Helper(int num);
    int SayCurNum(); // говорит текущее выбранное число (для debug'а)
    void setPrevCell(ControlCell* Cell); // для принудительного указания предыдущей активной ячейки
    int sayCurScore(); // говорит текущий счет

signals:
    void left0(Helper* helper); // Сигнал об обнулении счетчика незаполненных клеток (left2victory)
    void updateCurScore(int newScore); // Обновление ScoreLabel

public slots:
    void selectNum(ControlCell* Cell, int num);
    void ChangeCell(GameCell* Cell);
    void ChangeScore(int AddScore); // добавление счета

private:
    ControlCell* prevCell;
    int CurrentNum;

    int currentScore = 0; // текущий счет
};

#endif
