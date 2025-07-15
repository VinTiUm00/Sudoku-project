#include <QMessageBox>

#include "PlayingWindow.hpp"
#include "Helper.hpp"
#include "Generator.hpp"

//#define DEBUG

PlayingWindow::PlayingWindow(QWidget* parent) : QWidget(parent){}

void PlayingWindow::InitialiseGameField(short int mesh_size, short int format_chance){
    // группировщик
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // кнопка выхода
    QPushButton* btnExit = new QPushButton("Выход", this);
    mainLayout->addWidget(btnExit);
    connect(btnExit, &QPushButton::clicked, this, &PlayingWindow::closeWindow);

    QFont* font = new QFont(btnExit->font());
    font->setPointSize(12);
    btnExit->setFont(*font);
    btnExit->setStyleSheet("QPushButton { background-color: #AF505A; color: white; }");

    // проставка
    QWidget* tmp1 = new QWidget(this); // вероятнее всего будет заменен на "текущий счет"
    tmp1->setFixedHeight(40);
    mainLayout->addWidget(tmp1);

    // помощник
    Helper* helper = new Helper(0);

    // Шрифт для дальнейшего использования
    QPushButton* forFont = new QPushButton();
    QFont* btnFont = new QFont(forFont->font());
    btnFont->setPointSize(14);

    // Почти решенное судоку
    this->Matrix = Generate(mesh_size, format_chance);

    QGridLayout* gridLayoutGame = new QGridLayout();
    gridLayoutGame->setSpacing(2);

    // инициализация игрового поля
    for (int row = 0; row < mesh_size * mesh_size; row++){
        for (int col = 0; col < mesh_size * mesh_size; col++){
            GameCell* button = nullptr;

            if (Matrix[row][col] == 0){ // если в Martix 0, значит его нужно решить
                button = new GameCell(this, true);
                button->setPositionMatrix(Matrix, mesh_size, row, col);

                button->connectPW(CellButtons, left2victory);
                this->left2victory++;
            }
            else{ // если не 0, значит ячейка меняться не может
                button = new GameCell(this, Matrix[row][col]);
                button->setPositionMatrix(Matrix, mesh_size, row, col);
                button->setStyleSheet("GameCell { background-color: #6e6e6e; color: black; font-weight: 900;}");

                button->connectPW(CellButtons, left2victory);
            }

            button->setFixedSize(40, 40);
            button->setFont(*btnFont);

            gridLayoutGame->addWidget(button, row, col);

            connect(button, &GameCell::WannaChangeOut, helper, &Helper::ChangeCell);

            CellButtons.append(button);
        }
    }

    mainLayout->addLayout(gridLayoutGame);
    connect(helper, &Helper::left0, this, &PlayingWindow::Victory);

    // проставка
    QWidget* tmp = new QWidget(this);
    tmp->setFixedHeight(40);
    mainLayout->addWidget(tmp);

    QHBoxLayout* hBoxLayoutControl = new QHBoxLayout();

    // инициализация кнопок управления
    for (int i = 1; i <= mesh_size * mesh_size; i++){
        ControlCell* button = new ControlCell(i, QString::number(i), this);

        // кастомизация управляющих кнопок
        button->setFixedSize(40, 40);
        button->setFont(*btnFont);

        // группировка
        hBoxLayoutControl->addWidget(button);

        // выбор числа, которое будем вставлять в игровую ячейку
        connect(button, &ControlCell::selectNum, helper, &Helper::selectNum);

        ControlButtons.append(button);
    }

    mainLayout->addLayout(hBoxLayoutControl);

    helper->setPrevCell(ControlButtons[0]);

    setLayout(mainLayout);
}

PlayingWindow::~PlayingWindow() = default;

void PlayingWindow::closeWindow(){
    emit PlayingWindow::windowClosed();
    this->close();
}

void PlayingWindow::startEasy(){
#ifdef DEBUG
    qDebug() << "startEasy";
#endif
    short int mesh_size = 2;
    this->InitialiseGameField(mesh_size, format_chance);

    this->show();
    this->raise();
}

void PlayingWindow::startNormal(){
#ifdef DEBUG
    qDebug() << "startNormal";
#endif
    short int mesh_size = 3;
    this->InitialiseGameField(mesh_size, format_chance);

    this->show();
    this->raise();
}

void PlayingWindow::startHard(){
#ifdef DEBUG
    qDebug() << "startHard";
#endif
    short int mesh_size = 4;
    this->InitialiseGameField(mesh_size, format_chance);

    this->show();
    this->raise();
}

void PlayingWindow::startInsane(){
#ifdef DEBUG
    qDebug() << "startInsane";
#endif
    short int mesh_size = 5;
    this->InitialiseGameField(mesh_size, format_chance);

    this->show();
    this->raise();
}

void PlayingWindow::Victory(){
    for (GameCell *CurCell : CellButtons){
        (*CurCell).setGREENclr();
        (*CurCell).setfCanChange(false);
    }

    this->left2victory--;

    QMessageBox* box = new QMessageBox;
    box->setText("Вы решили судоку!!!");
    box->exec();
    box->setIcon(QMessageBox::Critical);

    delete box;
}

void PlayingWindow::setFormatVal(int new_val){
    this->format_chance = new_val;
}