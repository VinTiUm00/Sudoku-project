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
    else if (draftMode){
        Cell->toDraft(this->CurrentNum);
    }
    else{
        Cell->ChangeNum(this->CurrentNum);

        // Проверка на решенность
        if (!Cell->getLeft()){
            emit left0(this);
        }
    }
}

int Helper::sayCurScore(){
    return this->currentScore;
}

void Helper::ChangeScore(int AddScore){
    this->currentScore += AddScore;
    emit updateCurScore(this->currentScore);
}

// Переключение режима черновика
void Helper::setDraftMode(bool turnOn){
    if (turnOn){
        this->draftMode = true;
    }
    else {
        this->draftMode = false;
    }
}