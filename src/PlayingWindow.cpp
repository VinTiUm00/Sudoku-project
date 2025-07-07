#include <QLabel>

#include "PlayingWindow.hpp"
#include "GameCell.hpp"
#include "ControlCell.hpp"

#define DEBUG

int CurrentSelectNum = 1;

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

    QLabel* CurrentNum = new QLabel(QString::number(CurrentSelectNum), this);

    // инициализация игрового поля
    for (int row = 1; row < 10; row++){
        for (int col = 0; col < 9; col++){
            GameCell* button = new GameCell(row, col, this);

            button->setFixedSize(40, 40);

            gridLayout->addWidget(button, row, col);

            CellButtons.append(button);
        }
    }

    QFont* btnFont = new QFont(CellButtons[1]->font());
    btnFont->setPointSize(14);

    // инициализация кнопок управления
    for (int i = 1; i < 10; i++){
        ControlCell* button = new ControlCell(i, QString::number(i), this);

        // кастомизация управляющих кнопок
        button->setFixedSize(40, 40);
        button->setStyleSheet("ControlCell { background-color: #61AFEF; color: white; }");
        button->setFont(*btnFont);

        gridLayout->addWidget(button, 10, i-1);

        // выбор числа, которое будем вставлять в игровую ячейку
        connect(button, &QPushButton::clicked, button, &ControlCell::NumSelect);
        connect(button, &ControlCell::selectNum, [](int num){CurrentSelectNum = num;});
        connect(button, &ControlCell::selectNum, CurrentNum, [CurrentNum](int num){CurrentNum->setText(QString::number(num));});
    }

    CurrentNum->setFixedSize(40, 40);
    CurrentNum->setStyleSheet("QLabel { background-color: #61AFEF; color: white; }");
    gridLayout->addWidget(CurrentNum, 4, 11);

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

