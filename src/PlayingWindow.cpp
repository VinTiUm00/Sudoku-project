#include "PlayingWindow.hpp"
#include "GameCell.hpp"
#include "ControlCell.hpp"
#include "Helper.hpp"

#define DEBUG

PlayingWindow::PlayingWindow(QWidget* parent) : QWidget(parent){
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(2);

    // кнопка выхода
    QPushButton* btnExit = new QPushButton("Выход", this);
    gridLayout->addWidget(btnExit, 0, 0, 1, 9);
    connect(btnExit, &QPushButton::clicked, this, &PlayingWindow::closeWindow);

    QFont* font = new QFont(btnExit->font());
    font->setPointSize(12);
    btnExit->setFont(*font);
    btnExit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; }");

    QWidget* tmp1 = new QWidget(this); // вероятнее всего будет заменен на "текущий счет"
    tmp1->setFixedHeight(40);
    gridLayout->addWidget(tmp1, 1, 0, 1, 9);

    // инициализация игрового поля
    for (int row = 2; row < 11; row++){
        for (int col = 0; col < 9; col++){
            GameCell* button = new GameCell(row-2, col, this);

            button->setFixedSize(40, 40);

            gridLayout->addWidget(button, row, col);

            CellButtons.append(button);
        }
    }

    QWidget* tmp = new QWidget(this);
    tmp->setFixedHeight(40);
    gridLayout->addWidget(tmp, 11, 0, 1, 9);

    QFont* btnFont = new QFont(CellButtons[1]->font());
    btnFont->setPointSize(14);

    Helper* helper = new Helper(0);

    // инициализация кнопок управления
    for (int i = 1; i < 10; i++){
        ControlCell* button = new ControlCell(i, QString::number(i), this);

        // кастомизация управляющих кнопок
        button->setFixedSize(40, 40);
        button->setFont(*btnFont);

        gridLayout->addWidget(button, 12, i-1);

        // выбор числа, которое будем вставлять в игровую ячейку
        connect(button, &ControlCell::selectNum, helper, &Helper::selectNum);

        ControlButtons.append(button);
    }

    helper->setPrevCell(ControlButtons[0]);

    connect(helper, &Helper::SelectCell1, ControlButtons[0], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell2, ControlButtons[1], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell3, ControlButtons[2], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell4, ControlButtons[3], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell5, ControlButtons[4], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell6, ControlButtons[5], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell7, ControlButtons[6], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell8, ControlButtons[7], &ControlCell::setActive);
    connect(helper, &Helper::SelectCell9, ControlButtons[8], &ControlCell::setActive);

    setLayout(gridLayout);
}

PlayingWindow::~PlayingWindow() = default;

void PlayingWindow::closeWindow(){
    emit PlayingWindow::windowClosed();
    this->close();
}

void PlayingWindow::startEasy(){
#ifdef DEBUG
    qDebug() << "startEasy";
#endif
    this->show();
    this->raise();
}

void PlayingWindow::startNormal(){
#ifdef DEBUG
    qDebug() << "startNormal";
#endif
    this->show();
    this->raise();
}

void PlayingWindow::startHard(){
#ifdef DEBUG
    qDebug() << "startHard";
#endif
    this->show();
    this->raise();
}

void PlayingWindow::startInsane(){
#ifdef DEBUG
    qDebug() << "startInsane";
#endif
    this->show();
    this->raise();
}

