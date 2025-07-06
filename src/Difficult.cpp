#include "Difficult.hpp"

#include <QVBoxLayout>

DifficultMenu::DifficultMenu(QWidget* parent) : QDialog(parent){

    // инициализция кнопок
    Easy = new QPushButton("Легкий", this);
    Easy->setFixedHeight(40);

    Normal = new QPushButton("Средний", this);
    Normal->setFixedHeight(40);

    Hard = new QPushButton("Сложный", this);
    Hard->setFixedHeight(40);

    Insane = new QPushButton("Невозможный", this);
    Insane->setFixedHeight(40);

    Exit = new QPushButton("Назад", this);
    Exit->setFixedHeight(40);

    // кастомизация
    Exit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; }");

    QFont* font = new QFont(Easy->font());
    font->setPointSize(12);

    Easy->setFont(*font);
    Normal->setFont(*font);
    Hard->setFont(*font);
    Insane->setFont(*font);
    Exit->setFont(*font);

    // группировка
    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(Easy);
    layout->addWidget(Normal);
    layout->addWidget(Hard);
    layout->addWidget(Insane);
    layout->addWidget(Exit);

    connect(Exit, &QPushButton::clicked, this, &DifficultMenu::closeWindow);
    connect(Easy, &QPushButton::clicked, this, &DifficultMenu::EasySelected);
    connect(Normal, &QPushButton::clicked, this, &DifficultMenu::NormalSelected);
    connect(Hard, &QPushButton::clicked, this, &DifficultMenu::HardSelected);
    connect(Insane, &QPushButton::clicked, this, &DifficultMenu::InsaneSelected);
}

DifficultMenu::~DifficultMenu() = default;

void DifficultMenu::closeWindow(){
    this->close();
}
