#include "Difficult.hpp"

#include <QVBoxLayout>
#include <string>

DifficultMenu::DifficultMenu(QWidget* parent) : QDialog(parent){

    // инициализция кнопок
    Easy = new QPushButton("Легкий (4x4)", this);
    Easy->setFixedHeight(40);
    Easy->setStyleSheet("QPushButton { background-color: #3C3C3C; color: white; }");

    Normal = new QPushButton("Средний (9x9)", this);
    Normal->setFixedHeight(40);
    Normal->setStyleSheet("QPushButton { background-color: #3C3C3C; color: white; }");

    Hard = new QPushButton("Сложный (16x16)", this);
    Hard->setFixedHeight(40);
    Hard->setStyleSheet("QPushButton { background-color: #3C3C3C; color: white; }");

    Insane = new QPushButton("Невозможный (25x25)", this);
    Insane->setFixedHeight(40);
    Insane->setStyleSheet("QPushButton { background-color: #3C3C3C; color: white; }");

    Exit = new QPushButton("Назад", this);
    Exit->setFixedHeight(40);

    SliderValue = new QLabel(this);
    SliderValue->setFixedHeight(31); // Минимальная высота для 1 строки
    SliderValue->setStyleSheet("QLabel { color: white; }");
    SliderValue->setAlignment(Qt::AlignmentFlag::AlignCenter);
    SliderValue->setAttribute(Qt::WA_TranslucentBackground);

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

