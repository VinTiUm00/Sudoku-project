#ifndef CONTROLLCELL_HPP
#define CONTROLLCELL_HPP

// класс для управляющих кнопок
#include <QPushButton>

class ControlCell : public QPushButton{

    Q_OBJECT

public:
    ControlCell(int num, QString name, QWidget* parent = nullptr);
    virtual ~ControlCell();
    int saynum();
    void setPassive();

signals:
    void selectNum(ControlCell* thisCell, int num);

public slots:
    void NumSelect();
    void setActive();

private:
    int num;

};

#endif
