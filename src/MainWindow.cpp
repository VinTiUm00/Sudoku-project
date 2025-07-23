#include <QVBoxLayout>
#include <QFont> // для изменнения размера шрифта
#include <algorithm>

#include "MainWindow.hpp"
#include "Difficult.hpp"
#include "PlayingWindow.hpp"
#include "ScoreWindow.hpp"
#include "ScoreFunctions.hpp"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent){
    // получение предыдущих счетов 
    this->scoreList = loadScores();

    QVBoxLayout* layout = new QVBoxLayout(this); // Группировка кнопок

    // инициализация текса
    if (!this->scoreList.empty()){
        this->maxScore = *(std::max_element(this->scoreList.begin(), this->scoreList.end()));
    }
    lblMaxScore = new QLabel(this);
    lblMaxScore->setText(QString("Ваш максимальный счет: " + QString::number(maxScore)));
    lblMaxScore->setFixedHeight(150);
    lblMaxScore->setStyleSheet("QLabel { color: white; font-size: 20px; }");

    // инициализация кнопок
    btnPlay = new QPushButton("Играть", this);
    btnPlay->setFixedHeight(50);

    btnScoreTable = new QPushButton("Статистика", this);

    btnExit = new QPushButton("Выход", this);
    btnExit->setFixedHeight(50);

    // кастомизация
    btnPlay->setStyleSheet("QPushButton { background-color: #7CD47B; color: white; font-size: 16px; }");

    btnScoreTable->setFixedHeight(50);
    btnScoreTable->setStyleSheet("QPushButton { font-size: 16px; }");

    btnExit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; font-size: 16px; }");

    // добавление в группировку
    layout->addWidget(lblMaxScore);
    layout->addWidget(btnPlay);
    layout->addWidget(btnScoreTable);
    layout->addWidget(btnExit);

    connect(btnPlay, &QPushButton::clicked, this, &MainWindow::OpenDifficultMenu);
    connect(btnScoreTable, &QPushButton::clicked, this, &MainWindow::OpenScoreTable);
    connect(btnExit, &QPushButton::clicked, this, &MainWindow::closeWindow);
}

MainWindow::~MainWindow() = default;

void MainWindow::OpenDifficultMenu(){
    DifficultMenu* Menu = new DifficultMenu(this);
    PlayingWindow* GameWindow = new PlayingWindow();
    Menu->setStyleSheet("DifficultMenu { background-color: #282C34; }");
    GameWindow->setStyleSheet("PlayingWindow { background-color: #282C34; }");

    // Привязка счета
    connect(GameWindow, &PlayingWindow::sayScore, this, &MainWindow::saveScore);

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
    Menu->exec();
}

void MainWindow::OpenScoreTable(){
    ScoreWindow* ScoreTable = new ScoreWindow();
    ScoreTable->setFixedWidth(500);
    ScoreTable->setStyleSheet("ScoreWindow { background-color: #282C34; }");
    this->hideWindow();

    connect(ScoreTable, &ScoreWindow::windowClosed, this, &MainWindow::showWindow);
    connect(ScoreTable, &ScoreWindow::windowClosed, ScoreTable, &QObject::deleteLater);

    ScoreTable->raise();
    ScoreTable->show();
}

void MainWindow::saveScore(int Score){
    this->scoreList.push_back(Score);
    saveScores(this->scoreList);
}

void MainWindow::closeWindow(){
    this->close();
}

void MainWindow::hideWindow(){
    this->hide();
}

void MainWindow::showWindow(){
    this->scoreList = loadScores();
    this->maxScore = *(std::max_element(this->scoreList.begin(), this->scoreList.end()));
    lblMaxScore->setText(QString("Ваш максимальный счет: " + QString::number(maxScore)));
    this->show();
}
