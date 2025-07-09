#include "ControlCell.hpp"

ControlCell::ControlCell(int num, QString name, QWidget* parent) : QPushButton(name, parent){
    this->num = num;
    this->setStyleSheet("ControlCell { background-color: #61AFEF; color: black; }");
    connect(this, &QPushButton::clicked, this, &ControlCell::NumSelect);
}

ControlCell::~ControlCell() = default;

void ControlCell::NumSelect(){
    emit selectNum(this, this->num);
}

int ControlCell::saynum(){
    return this->num;
}

void ControlCell::setPassive(){
    this->setStyleSheet("ControlCell { background-color: #61AFEF; color: black; }");
}

void ControlCell::setActive(){
    this->setStyleSheet("ControlCell { background-color: #7CD47B; color: black; }");
}
