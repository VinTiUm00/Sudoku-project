#include <QVBoxLayout>
#include <QFont> // для изменнения размера шрифта

#include "MainWindow.hpp"
#include "Difficult.hpp"
#include "PlayingWindow.hpp"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent){
    QVBoxLayout* layout = new QVBoxLayout(this); // Группировка кнопок

    // инициализация текса
    lblMaxScore = new QLabel(this);
    lblMaxScore->setText(QString("Ваш максимальный счет: "));
    lblMaxScore->setFixedHeight(150);

    // изменение размера шрифта
    QFont* font = new QFont(lblMaxScore->font());
    font->setPointSize(16);
    lblMaxScore->setFont(*font);

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
    DifficultMenu* Menu = new DifficultMenu(this);
    PlayingWindow* GameWindow = new PlayingWindow();

    connect(Menu, &DifficultMenu::EasySelected, GameWindow, &PlayingWindow::startEasy);
    connect(Menu, &DifficultMenu::EasySelected, Menu, &DifficultMenu::closeWindow);
    connect(Menu, &DifficultMenu::EasySelected, this, &MainWindow::hideWindow);

    connect(Menu, &DifficultMenu::NormalSelected, GameWindow, &PlayingWindow::startNormal);
    connect(Menu, &DifficultMenu::NormalSelected, Menu, &DifficultMenu::closeWindow);
    connect(Menu, &DifficultMenu::NormalSelected, this, &MainWindow::hideWindow);

    connect(Menu, &DifficultMenu::HardSelected, GameWindow, &PlayingWindow::startHard);
    connect(Menu, &DifficultMenu::HardSelected, Menu, &DifficultMenu::closeWindow);
    connect(Menu, &DifficultMenu::HardSelected, this, &MainWindow::hideWindow);

    connect(Menu, &DifficultMenu::InsaneSelected, GameWindow, &PlayingWindow::startInsane);
    connect(Menu, &DifficultMenu::InsaneSelected, Menu, &DifficultMenu::closeWindow);
    connect(Menu, &DifficultMenu::InsaneSelected, this, &MainWindow::hideWindow);

    connect(GameWindow, &PlayingWindow::windowClosed, this, &MainWindow::showWindow);

    Menu->setWindowTitle("Выбор сложности");
    Menu->resize(300, 150);
    Menu->raise();
    Menu->show();
}

void MainWindow::closeWindow(){
    this->close();
}

void MainWindow::hideWindow(){
    this->hide();
}

void MainWindow::showWindow(){
    this->show();
}
