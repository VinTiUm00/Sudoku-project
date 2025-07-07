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

signals:
    void selectNum(int num);

public slots:
    void NumSelect();

private:
    int num;

};

#endif
