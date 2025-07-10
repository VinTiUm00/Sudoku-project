#include <QMessageBox>

#include "GameCell.hpp"

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
        this->setText(QString::number(num));
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
