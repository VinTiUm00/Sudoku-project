#include <QMessageBox>

#include "GameCell.hpp"
#include "Check.hpp"

GameCell::GameCell(QWidget* parent, bool fvalue) : QPushButton(parent){
    this->fCanChange = fvalue;
    connect(this, &QPushButton::clicked, this, &GameCell::WannaChangeIn);
}

GameCell::GameCell(QWidget* parent, short int num) : QPushButton(parent){
    this->num = num;
    connect(this, &QPushButton::clicked, this, &GameCell::WannaChangeIn);
    this->setText(QString::number(num));
}

GameCell::~GameCell() = default;

void GameCell::ChangeNum(int num){
    if (this->fCanChange == true){
        this->num = num;
        this->mesh[this->row][this->col] = num;
        this->setText(QString::number(num));
        
        if (!isCellAccord2Rules(this->mesh, this->mesh_size, this->row, this->col)){
            this->setStyleSheet("GameCell { background-color: #AF505A; color: black; font-weight: 900; }");
        }
        else {
            this->setStyleSheet("GameCell { background-color: #61AFEF; color: black; font-weight: 900; }");
        }
    }
    else{
        QMessageBox* box = new QMessageBox;
        box->setText("Нельзя менять!");
        box->exec();
        box->setIcon(QMessageBox::Critical);

        delete box;
    };
}

void GameCell::WannaChangeIn(){
    emit WannaChangeOut(this);
}

void GameCell::setfCanChange(bool value){
    this->fCanChange = value;
}

void GameCell::setPositionMatrix(std::vector<std::vector<short int>> &mesh, short int mesh_size, short int row, short int col){
    this->mesh = mesh;
    this->mesh_size = mesh_size;
    this->row = row;
    this->col = col;
}