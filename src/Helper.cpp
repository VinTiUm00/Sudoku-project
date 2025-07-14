#include <QMessageBox>

#include "Helper.hpp"

Helper::Helper(int num){
    this->CurrentNum = num;
}

void Helper::selectNum(ControlCell* Cell, int num){
    this->prevCell->setPassive();
    this->setPrevCell(Cell);
    this->CurrentNum = num;
    Cell->setActive();
}

int Helper::SayCurNum(){
    return this->CurrentNum;
}

void Helper::setPrevCell(ControlCell* Cell){
    this->prevCell = Cell;
}

void Helper::ChangeCell(GameCell* Cell){
    if (this->CurrentNum == 0){
        QMessageBox* box = new QMessageBox;
        box->setText("Перед изменением клетки выберите число!");
        box->exec();
        box->setIcon(QMessageBox::Critical);

        delete box;
    }
    else{
        Cell->ChangeNum(this->CurrentNum);

        if (!Cell->getLeft()){
            emit left0();
        }
    }
}
