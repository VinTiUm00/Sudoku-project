#include <QMessageBox>

#include "GameCell.hpp"

GameCell::GameCell(QWidget* parent, bool fvalue) : QPushButton(parent){
    this->fCanChange = fvalue;
    connect(this, &QPushButton::clicked, this, &GameCell::WannaChangeIn);
}

GameCell::GameCell(QWidget* parent, short int num) : QPushButton(parent){
    this->num = num;
    connect(this, &QPushButton::clicked, this, &GameCell::WannaChangeIn);
    this->setText(QString::number(num));
}

GameCell::~GameCell() = default;

// Изменение значения ячейки
void GameCell::ChangeNum(int num){
    if (this->fCanChange == true){
        // Проверка на попытку присвоить то же значение
        if (this->num == num){
            return;
        }

        // Изменение значения
        this->prev_val = this->num;
        this->num = num;
        (*(this->mesh))[this->row][this->col] = num;
        this->setText(QString::number(num));
        
        // Проверка на корректность
        if (!(this->isCellAccord2Rules(false))){
            // Конфликтует - в красный
            this->replace_StyleSheet(29, 7, "#AF505A");

            // Прибавление счетчика, если цвет сменился с синего на красный
            if (this->conflict_level == 'B'){
                (*counter)++;
            }
            this->conflict_level = 'R';
        }
        else { // Синий - значение не конфликтует
            this->replace_StyleSheet(29, 7, "#61AFEF");
            this->replace_StyleSheet(45, 7, "#FFFFFF");

            // Проверка на предыдущее состояние
            if (this->conflict_level != 'B'){
                (*counter)--;
            }

            emit this->addScore(25);

            this->conflict_level = 'B';
            this->conflict_counter = 0;
        }
    }
    else{
        // Сообщение о невозможности редактирования
        QMessageBox* box = new QMessageBox;
        box->setText("Нельзя менять!");
        box->exec();
        box->setIcon(QMessageBox::Critical);

        delete box;
    };
}

void GameCell::WannaChangeIn(){
    emit WannaChangeOut(this);
}

// Изменение редактируемости
void GameCell::setfCanChange(bool value){
    this->fCanChange = value;
}

// Получение ссылки на матрицу, положение в матрице
void GameCell::setPositionMatrix(std::vector<std::vector<short int>> &mesh, short int mesh_size, short int row, short int col){
    this->mesh = &mesh;
    this->mesh_size = mesh_size;
    this->row = row;
    this->col = col;
}

// Связь с вектором этих ячеек, счетчиком
void GameCell::connectPW(QVector<GameCell*> &GC_vector, int &counter){
    this->GC_vector = &GC_vector;
    this->counter = &counter;
}

// Проверка на конфликт
bool GameCell::isCellAccord2Rules (bool just_check){
    bool accord = true; // Подчиняется правилам

    // Check line
    for (short int j = 0; j < this->mesh_size * this->mesh_size; j++){
        if (this->col != j){
            if (this->num == (*this->mesh)[this->row][j]){ // Есть конфликт
                accord = false;
                if (!just_check){
                    (*((*(this->GC_vector))[this->row * mesh_size * mesh_size + j])).setYELLOWclr();
                }
            }
            else if (!just_check // Не конфликтует сейчас/больше
            and this->prev_val == (*this->mesh)[this->row][j]
            and ((*((*(this->GC_vector))[this->row * mesh_size * mesh_size + j])).get_conflict_level() == 'Y'
            or   (*((*(this->GC_vector))[this->row * mesh_size * mesh_size + j])).get_conflict_level() == 'R')){
                 (*((*(this->GC_vector))[this->row * mesh_size * mesh_size + j])).setSELFclr();
            }
        }
    }

    // Check column
    for (short int i = 0; i < this->mesh_size * this->mesh_size; i++){
        if (this->row != i){
            if (this->num == (*this->mesh)[i][this->col]){ // Есть конфликт
                accord = false;
                if (!just_check){
                    (*((*(this->GC_vector))[i * mesh_size * mesh_size + this->col])).setYELLOWclr();
                }
            }
            else if (!just_check // Не конфликтует сейчас/больше
            and this->prev_val == (*this->mesh)[i][this->col]
            and ((*((*(this->GC_vector))[i * mesh_size * mesh_size + this->col])).get_conflict_level() == 'Y'
            or   (*((*(this->GC_vector))[i * mesh_size * mesh_size + this->col])).get_conflict_level() == 'R')){
                 (*((*(this->GC_vector))[i * mesh_size * mesh_size + this->col])).setSELFclr();
            }
        }
    }

    // Check big cell
    for (short int i = this->row / this->mesh_size * this->mesh_size; i < (this->row / this->mesh_size + 1) * this->mesh_size; i++){
        for (short int j = this->col / this->mesh_size * this->mesh_size; j < (this->col / this->mesh_size + 1) * this->mesh_size; j++){
            if (this->row != i or this->col != j){
                if (this->num == (*this->mesh)[i][j]){ // Есть конфликт
                    accord = false;
                    if (!just_check){
                        (*((*(this->GC_vector))[i * mesh_size * mesh_size + j])).setYELLOWclr();
                    }
                }
                else if (!just_check // Не конфликтует сейчас/больше
                and this->prev_val == (*this->mesh)[i][j]
                and ((*((*(this->GC_vector))[i * mesh_size * mesh_size + j])).get_conflict_level() == 'Y'
                or   (*((*(this->GC_vector))[i * mesh_size * mesh_size + j])).get_conflict_level() == 'R')){
                     (*((*(this->GC_vector))[i * mesh_size * mesh_size + j])).setSELFclr();
                }
            }
        }
    }

    return accord;
}

// Окраска в желтый
void GameCell::setYELLOWclr(){
    if (this->conflict_level != 'R'){ // Красные не перекрашиваем
        this->replace_StyleSheet(29, 7, "#DBE45C");

        if (this->conflict_level == 'B'){ // Теперь эта ячейка под сомнением
            (*counter)++;
        }
        this->conflict_level = 'Y';
    }
    this->conflict_counter++;
}

// Окраска в "свой" цвет // Для возврата в исходное состояние
void GameCell::setSELFclr(){
    // Чтобы не уйти в минус
    if (this->conflict_counter){
        this->conflict_counter--;
    }

    // Перекраска + цепная проверка
    if (this->conflict_counter == 0){
        if (this->fCanChange){ // Для редактируемых
            if (this->conflict_level == 'Y'){
                this->replace_StyleSheet(29, 7, "#61AFEF");
                (*counter)--;
                this->conflict_level = 'B';
            }
            else if (this->conflict_level == 'R' and this->isCellAccord2Rules()){
                this->isCellAccord2Rules(false); // Цепная проверка
                this->replace_StyleSheet(29, 7, "#61AFEF");
                (*counter)--;
                this->conflict_level = 'B';
            }
        }
        else { // Для НЕредактируемых
            this->replace_StyleSheet(29, 7, "#6E6E6E");
            this->conflict_level = 'G';
        }
    }
}

// Окраска в зеленый (при полном решении)
void GameCell::setGREENclr(){
    this->replace_StyleSheet(29, 7, "#7CD47B");
}

// Получение значения счетчика
int GameCell::getLeft(){
    return *(this->counter);
}

// Получение conflict_level
char GameCell::get_conflict_level(){
    return this->conflict_level;
}

// Изменение StyleSheet
void GameCell::replace_StyleSheet(int pos, int count, QString string){
    QString StyleSheet = this->styleSheet();
    StyleSheet.replace(pos, count, string);
    this->setStyleSheet(StyleSheet);
}

// Получение значения ячейки
int GameCell::get_num(){
    return this->num;
}
