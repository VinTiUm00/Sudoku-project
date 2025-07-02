#include <QVBoxLayout>

#include "MainWindow.hpp"
#include "Difficult.hpp"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout(this); // Группировка кнопок

    // инициализация текса
    lblMaxScore = new QLabel(this);
    lblMaxScore->setText(QString("Ваш максимальный счет: "));
    lblMaxScore->setFixedHeight(150);

    // инициализация кнопок
    btnPlay = new QPushButton("Играть", this);
    btnSettings = new QPushButton("Настройки", this);
    btnExit = new QPushButton("Выход", this);

    // добавление в группировку
    layout->addWidget(lblMaxScore);
    layout->addWidget(btnPlay);
    layout->addWidget(btnSettings);
    layout->addWidget(btnExit);

    connect(btnPlay, &QPushButton::clicked, this, &MainWindow::OpenDifficultMenu);
    connect(btnExit, &QPushButton::clicked, this, &MainWindow::closeWindow);
}

MainWindow::~MainWindow() = default;

void MainWindow::OpenDifficultMenu(){
    DifficultMenu* Menu = new DifficultMenu();
    Menu->setWindowTitle("Выбор сложности");
    Menu->setGeometry(100, 100, 200, 50);
    Menu->raise();
    Menu->exec();
}

void MainWindow::closeWindow(){
    this->close();
}
