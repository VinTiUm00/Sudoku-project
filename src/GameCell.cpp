#include "GameCell.hpp"

GameCell::GameCell(int row, int col, QWidget* parent) : QPushButton(parent){
    this->row = row;
    this->col = col;
}

GameCell::~GameCell() = default;

void GameCell::ChangeNum(int num){
    this->num = num;
}
