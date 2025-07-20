#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "ScoreWindow.hpp"
#include "ScoreFunctions.hpp"

ScoreWindow::ScoreWindow(QWidget* parent) : QWidget(parent){
    this->scoreList = loadScores(); // получение счетов
    QVBoxLayout* vbox = new QVBoxLayout(this); // layout

    QPushButton* btnExit = new QPushButton("Выход", this);
    btnExit->setFixedHeight(50);
    btnExit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; font-size: 16px; }");
    connect(btnExit, &QPushButton::clicked, this, &ScoreWindow::closeWindow);
    vbox->addWidget(btnExit);

    // заполенине окна
    for (int score : scoreList){
        QLabel* row = new QLabel("Счет: " + QString::number(score), this);
        row->setFixedHeight(40);
        row->setContentsMargins(10, 0, 0, 0);
        row->setStyleSheet("QLabel { background-color: #3c3c3c; color: white; font-size: 16px; }");
        vbox->addWidget(row);
    }

    this->setLayout(vbox);
};

ScoreWindow::~ScoreWindow() = default;

void ScoreWindow::closeWindow(){
    this->close();
    emit this->windowClosed();
}
