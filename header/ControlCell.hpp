#ifndef CONTROLLCELL_HPP
#define CONTROLLCELL_HPP

// класс для управляющих кнопок
#include <QPushButton>

class ControlCell : public QPushButton{ // наследуется от Qt Кнопки

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    ControlCell(int num, QString name, QWidget* parent = nullptr); // конструктор
    virtual ~ControlCell();
    int saynum(); // возвращает свое число
    void setPassive(); // делает кнопку неактивной

signals:
    void selectNum(ControlCell* thisCell, int num); // сигнал для изменения выбранного числа

public slots:
    void NumSelect();
    void setActive(); // делает кнопку активной

private:
    int num; // свое число
};

#endif
