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
    lblMaxScore->setStyleSheet("QLabel { color: white; }");

    // изменение размера шрифта
    QFont* font = new QFont(lblMaxScore->font());
    font->setPointSize(16);
    lblMaxScore->setFont(*font);

    // инициализация кнопок
    btnPlay = new QPushButton("Играть", this);
    btnPlay->setFixedHeight(50);

    btnSettings = new QPushButton("Настройки", this);

    btnExit = new QPushButton("Выход", this);
    btnExit->setFixedHeight(50);

    // кастомизация
    btnPlay->setFont(*font);
    btnPlay->setStyleSheet("QPushButton { background-color: #7CD47B; color: white }");

    btnSettings->setFixedHeight(50);
    btnSettings->setFont(*font);

    btnExit->setFont(*font);
    btnExit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; }");

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
    Menu->setStyleSheet("DifficultMenu { background-color: #282C34; }");
    GameWindow->setStyleSheet("PlayingWindow { background-color: #282C34; }");

    // Привязка сигнала с передачей значения ползунка из Dif Menu в Play Win
    connect(Menu, &DifficultMenu::SlValChanged, GameWindow, &PlayingWindow::setFormatVal);

    // Остальные привязки
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
    connect(GameWindow, &PlayingWindow::windowClosed, GameWindow, &QObject::deleteLater);

    Menu->setWindowTitle("Выбор сложности");
    Menu->resize(350, 200);
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
