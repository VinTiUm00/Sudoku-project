#include "ControlCell.hpp"

ControlCell::ControlCell(int num, QString name, QWidget* parent) : QPushButton(name, parent){
    this->num = num;
}

ControlCell::~ControlCell() = default;

void ControlCell::NumSelect(){
    emit selectNum(this->num);
}

int ControlCell::saynum(){
    return this->num;
}
