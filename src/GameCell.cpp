#include "GameCell.hpp"

GameCell::GameCell(int row, int col, QWidget* parent) : QPushButton(parent){
    connect(this, &QPushButton::clicked, this, &GameCell::WannaChangeIn);
    this->row = row;
    this->col = col;
}

GameCell::~GameCell() = default;

void GameCell::ChangeNum(int num){
    this->num = num;
    this->setText(QString::number(num));
}

void GameCell::WannaChangeIn(){
    emit WannaChangeOut(this);
}
