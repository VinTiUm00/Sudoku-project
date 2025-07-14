#include <QMessageBox>

#include "Helper.hpp"

Helper::Helper(int num){
    this->CurrentNum = num;
}

void Helper::selectNum(ControlCell* Cell, int num){
    this->prevCell->setPassive();
    this->setPrevCell(Cell);
    this->CurrentNum = num;
    switch (num) {
        case 1:
            emit SelectCell1(); break;
        case 2:
            emit SelectCell2(); break;
        case 3:
            emit SelectCell3(); break;
        case 4:
            emit SelectCell4(); break;
        case 5:
            emit SelectCell5(); break;
        case 6:
            emit SelectCell6(); break;
        case 7:
            emit SelectCell7(); break;
        case 8:
            emit SelectCell8(); break;
        case 9:
            emit SelectCell9(); break;
    }
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
