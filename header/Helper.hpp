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

signals:
    void left0();

public slots:
    void selectNum(ControlCell* Cell, int num);
    void ChangeCell(GameCell* Cell);

private:
    ControlCell* prevCell;
    int CurrentNum;
};

#endif
