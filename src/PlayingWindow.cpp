#include "PlayingWindow.hpp"

PlayingWindow::PlayingWindow(QWidget* parent) : QWidget(parent){
    QGridLayout* gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(2);

    QPushButton* btnExit = new QPushButton("Выход", this);
    gridLayout->addWidget(btnExit, 0, 0, 1, 9);
    connect(btnExit, &QPushButton::clicked, this, &PlayingWindow::closeWindow);

    QFont* font = new QFont(btnExit->font());
    font->setPointSize(12);
    btnExit->setFont(*font);
    btnExit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; }");

    for (int row = 1; row < 10; row++){
        for (int col = 0; col < 9; col++){
            QPushButton* button = new QPushButton(this);

            button->setFixedSize(40, 40);

            gridLayout->addWidget(button, row, col);

            buttons.append(button);
        }
    }

    QFont* btnFont = new QFont(buttons[1]->font());
    btnFont->setPointSize(14);

    for (int i = 1; i < 10; i++){
        QPushButton* button = new QPushButton(QString::number(i), this);

        button->setFixedSize(40, 40);
        button->setStyleSheet("QPushButton { background-color: #61AFEF; color: white; }");
        button->setFont(*btnFont);

        gridLayout->addWidget(button, 10, i-1);
        
        buttons.append(button);
    }

    setLayout(gridLayout);
}

PlayingWindow::~PlayingWindow() = default;

void PlayingWindow::closeWindow(){
    emit PlayingWindow::windowClosed();
    this->close();
}

void PlayingWindow::startEasy(){
    qDebug() << "startEasy";
    this->show();
    this->raise();
}

void PlayingWindow::startNormal(){
    qDebug() << "startNormal";
    this->show();
    this->raise();
}

void PlayingWindow::startHard(){
    qDebug() << "startHard";
    this->show();
    this->raise();
}

void PlayingWindow::startInsane(){
    qDebug() << "startInsane";
    this->show();
    this->raise();
}

