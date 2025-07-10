#include "ControlCell.hpp"

ControlCell::ControlCell(int num, QString name, QWidget* parent) : QPushButton(name, parent){
    this->num = num;

    // кастомизация
    this->setStyleSheet("ControlCell { background-color: #61AFEF; color: black; font-weight: 900; }");

    connect(this, &QPushButton::clicked, this, &ControlCell::NumSelect); // связь нажатия и NumSelect
}

ControlCell::~ControlCell() = default;

void ControlCell::NumSelect(){
    emit selectNum(this, this->num);
}

int ControlCell::saynum(){
    return this->num;
}

void ControlCell::setPassive(){
    this->setStyleSheet("ControlCell { background-color: #61AFEF; color: black; font-weight: 900; }");
}

void ControlCell::setActive(){
    this->setStyleSheet("ControlCell { background-color: #7CD47B; color: black; font-weight: 900; }");
}
