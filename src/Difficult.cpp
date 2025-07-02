#include "Difficult.hpp"

#include <QVBoxLayout>

DifficultMenu::DifficultMenu(QWidget* parent) : QDialog(parent){

    // инициализция кнопок
    Easy = new QPushButton("Легкий", this);
    Normal = new QPushButton("Средний", this);
    Hard = new QPushButton("Сложный", this);
    Insane = new QPushButton("Невозможный", this);
    Exit = new QPushButton("Назад", this);

    QVBoxLayout* layout = new QVBoxLayout(this);

    // добавление в группировку
    layout->addWidget(Easy);
    layout->addWidget(Normal);
    layout->addWidget(Hard);
    layout->addWidget(Insane);
    layout->addWidget(Exit);

    connect(Exit, &QPushButton::clicked, this, &DifficultMenu::closeWindow);
}

DifficultMenu::~DifficultMenu() = default;

void DifficultMenu::closeWindow(){
    this->close();
}
