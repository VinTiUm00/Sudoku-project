#include "Difficult.hpp"

#include <QVBoxLayout>
#include <string>

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

    SliderValue = new QTextEdit();
    SliderValue->setFixedHeight(31); // Минимальная высота для 1 строки
    SliderValue->setReadOnly(true);  // Только для чтения

    FormatSlider = new QSlider(Qt::Horizontal, this); // Горизонтальный ползунок
    FormatSlider->setFixedHeight(30);
    FormatSlider->setMaximum(70); // Максимальное значение
    FormatSlider->setMinimum(20); // Минимальное значение
    FormatSlider->setValue(45);   // Значение по умолчанию

    // Чтобы текст был сразу
    this->changeValue();

    // кастомизация
    Exit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; }");

    QFont* font = new QFont(Easy->font());
    font->setPointSize(12);

    Easy->setFont(*font);
    Normal->setFont(*font);
    Hard->setFont(*font);
    Insane->setFont(*font);
    Exit->setFont(*font);
    SliderValue->setFont(*font);
    FormatSlider->setFont(*font);

    // группировка
    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(Easy);
    layout->addWidget(Normal);
    layout->addWidget(Hard);
    layout->addWidget(Insane);
    layout->addWidget(SliderValue);
    layout->addWidget(FormatSlider);
    layout->addWidget(Exit);

    // коннекты
    connect(Exit, &QPushButton::clicked, this, &DifficultMenu::closeWindow);
    connect(Easy, &QPushButton::clicked, this, &DifficultMenu::EasySelected);
    connect(Normal, &QPushButton::clicked, this, &DifficultMenu::NormalSelected);
    connect(Hard, &QPushButton::clicked, this, &DifficultMenu::HardSelected);
    connect(Insane, &QPushButton::clicked, this, &DifficultMenu::InsaneSelected);
    connect(FormatSlider, &QSlider::valueChanged, this, &DifficultMenu::changeValue);
}

DifficultMenu::~DifficultMenu() = default;

void DifficultMenu::closeWindow(){
    this->close();
}

// Обновление текста + передача сигнала
void DifficultMenu::changeValue(){
    this->SliderValue->setText(QString::fromStdString("Количество пустых клеток в сетке: " + std::to_string(this->FormatSlider->value()) + "%."));
    emit SlValChanged(this->FormatSlider->value());
}

