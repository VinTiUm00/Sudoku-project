#ifndef GAMECELL_HPP
#define GAMECELL_HPP

// класс игровой ячейки
#include <QPushButton>
#include <vector>

class GameCell : public QPushButton{

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    GameCell(QWidget* parent = nullptr, bool fvalue = false); // конструктор для изменяемой кнопки
    GameCell(QWidget* parent = nullptr, short int num = 0); // конструктор для неизменяемой кнопки
    virtual ~GameCell();
    void ChangeNum(int num); // изменить число ячейки
    void setfCanChange(bool value); // установить fCanChange

    // Получение необходимых данных о матрице, ее размере, а также позиции ячейки в матрице
    void setPositionMatrix(std::vector<std::vector<short int>> &mesh, short int mesh_size, short int row, short int col);

    void connectPW(QVector<GameCell*> &GC_vector, int &counter); // Связь с вектором этих ячеек, счетчиком заполненности редактируемых ячеек
    bool isCellAccord2Rules (bool just_check = true); // Проверка на корректность установленного значения
    int getLeft(); // Получение значения счетчика

    // Окраска ячеек
    void setYELLOWclr();
    void setSELFclr();
    void setGREENclr();

    char get_conflict_level(); // Получения уровня конфликта

signals:
    void WannaChangeOut(GameCell* Cell);

public slots:
    void WannaChangeIn();

private:
    int num = 0; // Собственное значение
    bool fCanChange = false; // Флаг редактируемости

    // Позиция, связь с матрицей
    short int row;
    short int col;
    std::vector<std::vector<short int>> *mesh;
    short int mesh_size;

    QVector<GameCell*> *GC_vector; // Вектор этих ячеек
    char conflict_level = 'G'; // G - Серый / B - Синий / Y - Желтый / R - Красный
    short int conflict_counter = 0; // Счетчик конфликтов с данной ячейкой
    int *counter; // Счетчик left2victory
    short int prev_val = 0; // Предыдущее значение
};

#endif
