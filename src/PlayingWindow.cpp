#include <QMessageBox>
#include <QLabel>

#include "PlayingWindow.hpp"
#include "Helper.hpp"
#include "Generator.hpp"
#include "ScoreLabel.hpp"

//#define DEBUG

PlayingWindow::PlayingWindow(QWidget* parent) : QWidget(parent){}

void PlayingWindow::InitialiseGameField(short int mesh_size){
    // группировщик
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // помощник
    Helper* helper = new Helper(0);

    // кнопка выхода
    QPushButton* btnExit = new QPushButton("Выход", this);
    mainLayout->addWidget(btnExit);
    connect(btnExit, &QPushButton::clicked, this, &PlayingWindow::closeWindow);

    btnExit->setFixedHeight(40);
    btnExit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; font-size: 18px; }");

    // текущий счет
    ScoreLabel* currentScore = new ScoreLabel(QString::number(helper->sayCurScore()), this);
    currentScore->setFixedHeight(40);
    currentScore->setAlignment(Qt::AlignmentFlag::AlignCenter);
    currentScore->setStyleSheet("ScoreLabel { color: white; font-size: 16px; }");
    mainLayout->addWidget(currentScore);

    connect(helper, &Helper::updateCurScore, currentScore, &ScoreLabel::ChangeScore);

    // Шрифт для дальнейшего использования
    QPushButton* forFont = new QPushButton();
    QFont* btnFont = new QFont(forFont->font());
    delete forFont;
    btnFont->setPointSize(14);

    // Почти решенное судоку
    this->Matrix = Generate(mesh_size, this->format_chance);

    QGridLayout* gridLayoutGame = new QGridLayout();
    gridLayoutGame->setSpacing(2);

    // инициализация игрового поля // Теперь для любой сетки
    for (int row = 0; row < mesh_size * mesh_size; row++){
        for (int col = 0; col < mesh_size * mesh_size; col++){
            GameCell* button = nullptr;

            if (Matrix[row][col] == 0){ // если в Martix 0, значит его нужно решить
                button = new GameCell(this, true);
                button->setPositionMatrix(Matrix, mesh_size, row, col);
                button->setStyleSheet("GameCell { background-color: #3C3C3C; color: #000000; font-weight: 900; font-size: 20px; }");

                this->left2victory++; // Подсчет пустых ячеек
            }
            else{ // если не 0, значит ячейка меняться не может
                button = new GameCell(this, Matrix[row][col]);
                button->setPositionMatrix(Matrix, mesh_size, row, col);
                button->setStyleSheet("GameCell { background-color: #6E6E6E; color: #000000; font-weight: 900; font-size: 20px; }");

            }

            button->connectPW(CellButtons, left2victory); // Передача связующих переменных // вынесено в общую инициализацию
            button->setFixedSize(40, 40);

            gridLayoutGame->addWidget(button, row, col, Qt::AlignTop);

            connect(button, &GameCell::WannaChangeOut, helper, &Helper::ChangeCell);
            connect(button, &GameCell::addScore, helper, &Helper::ChangeScore);

            CellButtons.append(button);

            if (col % mesh_size == mesh_size - 1){
                QSpacerItem* hspacer = new QSpacerItem(50, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);
                gridLayoutGame->addItem(hspacer, row, col);
            }
        }
        if (row % mesh_size == mesh_size - 1){
            QSpacerItem* vspacer = new QSpacerItem(0, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);
            gridLayoutGame->addItem(vspacer, row, 0, 1, mesh_size+(mesh_size-1));
        }
    }

    mainLayout->addLayout(gridLayoutGame);
    connect(helper, &Helper::left0, this, &PlayingWindow::Victory); // Привязка сигнала об обнулении счетчика

    // Черновик
    QPushButton *draftBtn = new QPushButton("Режим черновика", this);
    draftBtn->setFixedHeight(40);
    draftBtn->setFont(*btnFont);
    draftBtn->setStyleSheet("QPushButton { background-color: #61AFEF; color: #000000; font-weight: 500; }");
    draftBtn->setCheckable(true);
    mainLayout->addWidget(draftBtn);

    connect(draftBtn, &QPushButton::toggled, helper, &Helper::setDraftMode);

    QHBoxLayout* hBoxLayoutControl = new QHBoxLayout();

    // инициализация кнопок управления // Теперь для любой сетки
    for (int i = 1; i <= mesh_size * mesh_size; i++){
        ControlCell* button = new ControlCell(i, QString::number(i), this);

        // кастомизация управляющих кнопок
        button->setFixedSize(40, 40);
        button->setFont(*btnFont);

        // группировка
        hBoxLayoutControl->addWidget(button);

        // выбор числа, которое будем вставлять в игровую ячейку
        connect(button, &ControlCell::selectNum, helper, &Helper::selectNum);
        connect(button, &ControlCell::selectNum, this, &PlayingWindow::Highlight);

        ControlButtons.append(button);
    }

    mainLayout->addLayout(hBoxLayoutControl);

    helper->setPrevCell(ControlButtons[0]);
    // Здесь было 9 connect'ов

    setLayout(mainLayout);
}

PlayingWindow::~PlayingWindow() = default;

void PlayingWindow::closeWindow(){
    emit PlayingWindow::windowClosed();
    this->close();
}

void PlayingWindow::startEasy(){
#ifdef DEBUG // Зачем оно тут? Что оно делает?
    qDebug() << "startEasy"; 
#endif
    // Инициализация собственно игрового поля
    short int mesh_size = 2; // Для наглядности, позже убрать
    this->InitialiseGameField(mesh_size);

    this->show();
    this->raise();
}

void PlayingWindow::startNormal(){
#ifdef DEBUG
    qDebug() << "startNormal";
#endif
    short int mesh_size = 3;
    this->InitialiseGameField(mesh_size);

    this->show();
    this->raise();
}

void PlayingWindow::startHard(){
#ifdef DEBUG
    qDebug() << "startHard";
#endif
    short int mesh_size = 4;
    this->InitialiseGameField(mesh_size);

    this->show();
    this->raise();
}

void PlayingWindow::startInsane(){
#ifdef DEBUG
    qDebug() << "startInsane";
#endif
    short int mesh_size = 5;
    this->InitialiseGameField(mesh_size);

    this->show();
    this->raise();
}

// Победа (Решение судоку)
void PlayingWindow::Victory(Helper* helper){
    for (GameCell *CurCell : CellButtons){
        (*CurCell).setGREENclr(); // Озеленяем поле
        (*CurCell).setfCanChange(false); // Блокируем возможность менять значения в ячейках
    }

    this->left2victory--; // Для отключения сигнала left0
    emit this->sayScore(helper->sayCurScore());

    // Сообщение о победе
    QMessageBox* box = new QMessageBox(this);
    box->setText("Вы выиграли!!!");
    box->setIcon(QMessageBox::Information);
    int res = box->exec();
    if (res == QMessageBox::Ok)
        emit this->windowClosed();
    delete box;
}

// Изменение шанса на полученное из сигнала
void PlayingWindow::setFormatVal(int new_val){
    this->format_chance = new_val;
}

// Подсвечивание чисел ячеек, равных выбранному значению
void PlayingWindow::Highlight(ControlCell *CCell, int val){
    for (GameCell *Cell : this->CellButtons){
        if (val == (*Cell).get_num()){
            (*Cell).replace_StyleSheet(45, 7, "#FFFFFF");
        }
        else {
            (*Cell).replace_StyleSheet(45, 7, "#000000");
        }
    }
}
